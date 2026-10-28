// Standalone correctness + benchmark tests for FunctionParserBase::Eval2,
// the batch bytecode interpreter used by the pariso engines.
//
// Usage: fparser_eval2_test <mode> [args]
//   mode = check (default) : verify Eval2 batch results vs scalar Eval
//   mode = fuzz [seed] [count] : randomized correctness check
//   mode = bench [NB]      : time Eval2 on a large batch
//   mode = bench_mt [T] [NBtotal] : multithreaded bench mimicking the app
//
// check mode, per case:
//   Phase A: run the batch on raw data. If it reports an error, verify the
//            scalar reference has at least one point with the matching error
//            class (batch aborts on first error; results are not written).
//   Phase B: patch every singular point (found by scalar scan) to safe
//            values (1,1,1), rerun the batch, and require bit-identical
//            results vs the scalar reference for every point.
//
// NOTE on this fork's conventions (they differ from upstream fparser):
//   - Parse() returns -1 on success, >=0 (position) on error.
//   - Eval2() returns 6 (EVAL_NO_ERROR) on success, 5 (IF_FUNCT_ERROR),
//     7 (VAR_OVERFLOW), 1 (DIVISION_BY_ZERO), 0 (domain errors 2..4).
//   - Vars are laid out point-major: point e, variable v is at Vars[e*NbVar+v].

#ifndef _USE_MATH_DEFS
#define _USE_MATH_DEFS
#endif
#include "fparser.hh"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <mutex>

// ---------------------------------------------------------------- raw funcs
static double raw_mul3(const double* p) { return p[0]*p[1]*p[2]; }
static double raw_sinexp(const double* p) { return sin(p[0]) * exp(-p[1]*p[1]) + cos(p[2]); }
static double raw_divsafe(const double* p) { return p[1] == 0.0 ? 0.0 : p[0]/p[1]; }

// Expression-defined user functions (exercise the cPCall / nested-parser path).
// Kept as globals so the linked sub-parsers outlive all Eval calls.
static FunctionParser gSubH; // h(u,v) = u*sin(v)+v^2
static FunctionParser gSubQ; // q(a,b,c) = a*b-c+cos(a)
static FunctionParser gSubR; // r(s,t) = h(s,t)+s^2   (nested cPCall: r calls h)

struct Case
{
    const char* expr;
    const char* vars;   // variable list
    int nbvar;
    int xmode;          // 0 = normal rnd, 1 = force x>0, 2 = force x<0
    bool hasPCall;      // expression-defined (sub-parser) user functions
};

static const Case cases[] =
{
    { "cos(x)+cos(y)+cos(z)", "x,y,z", 3, 0, false },
    { "sin(x*y)*exp(-z^2)+(x^2)+sqrt(abs(y))+log(abs(z)+1)", "x,y,z", 3, 0, false },
    { "max(x,z)*min(y,x)+floor(x)+ceil(y)+abs(z)+int(x)+trunc(y)", "x,y,z", 3, 0, false },
    { "tan(x)*cot(y)+sec(x*y)+atan2(y,x)+hypot(x,z)+1/sin(x+y)", "x,y,z", 3, 0, false },
    { "f1(x,y,z)*f2(x,y,z)+f1(f2(x,y,z),x,z)+g(x,y)", "x,y,z", 3, 0, false },
    { "(x+y)*(y+z)*(z+x)+(x-y)^3+x^2+y^2+z^2+1/x+1/y+1/z", "x,y,z", 3, 0, false },
    { "if(x>0, x*y, y*z)+max(x,z)", "x,y,z", 3, 0, false },        // varying condition
    { "if(abs(x)>2, sin(x), 0)+if(y*z>1, cos(y), -cos(z))", "x,y,z", 3, 0, false },
    { "if(x>0, x*y, y*z)+max(x,z)", "x,y,z", 3, 1, false },        // uniform true branch
    { "if(x>0, x*y, y*z)+max(x,z)", "x,y,z", 3, 2, false },        // uniform false branch
    { "r(q(x,y,z), y)*q(x, z, x)+h(x, y)", "x,y,z", 3, 0, true },  // cPCall + nesting
};

// Map a batch return code to the scalar eval-error types that could produce
// it: 1 -> {1}, 7 -> {7}, 0 -> {2,3,4}. Returns 0 if code is not an error
// return (i.e. 6 or 5).
static int batchCodeErrorClass(double code)
{
    if(code == 1.0) return 1;
    if(code == 7.0) return 7;
    if(code == 0.0) return 2; // any of domain errors 2..4
    return 0;
}

// Parse/link the sub-parsers exactly once (they are shared globals).
static bool setupSubsOnce()
{
    static bool done = false;
    if(done) return true;
    if(gSubH.Parse("u*sin(v)+v^2", "u,v") != -1)
    { printf("  parse fail h\n"); return false; }
    if(gSubQ.Parse("a*b-c+cos(a)", "a,b,c") != -1)
    { printf("  parse fail q\n"); return false; }
    if(!gSubR.AddFunction("h", gSubH))
    { printf("  link fail r->h\n"); return false; }
    if(gSubR.Parse("h(s,t)+s^2", "s,t") != -1)
    { printf("  parse fail r\n"); return false; }
    done = true;
    return true;
}

static bool setupParser(FunctionParser& p, const Case& c, unsigned nbStack)
{
    p.AddFunction("f1", raw_mul3, 3);
    p.AddFunction("f2", raw_sinexp, 3);
    p.AddFunction("g", raw_divsafe, 2);
    if(c.hasPCall)
    {
        if(!setupSubsOnce()) return false;
        if(!p.AddFunction("h", gSubH) || !p.AddFunction("q", gSubQ) || !p.AddFunction("r", gSubR))
        { printf("  link fail\n"); return false; }
        gSubH.AllocateStackMemory(nbStack, 2);
        gSubQ.AllocateStackMemory(nbStack, 3);
        gSubR.AllocateStackMemory(nbStack, 2);
    }
    // NOTE: this fparser fork returns -1 on success, >=0 (position) on error
    if(p.Parse(c.expr, c.vars) != -1)
    {
        printf("  parse failed: %s\n", p.ErrorMsg());
        return false;
    }
    p.AllocateStackMemory(nbStack, c.nbvar);
    return true;
}

// deterministic pseudo-random in [-2.5, 2.5], avoiding exact 0 (for 1/x etc.)
static double rnd(uint& seed)
{
    seed = seed*1664525u + 1013904223u;
    double u = double(seed >> 8) / double(0x1000000); // [0,1)
    double v = (u - 0.5) * 5.0;
    if(v > -0.25 && v < 0.25) v = (v < 0 ? -0.25 : 0.25);
    return v;
}

static double rndForVar(uint& seed, int varIdx, int xmode)
{
    if(varIdx == 0 && xmode != 0)
    {
        seed = seed*1664525u + 1013904223u;
        double u = double(seed >> 8) / double(0x1000000); // [0,1)
        return xmode == 1 ? 0.25 + u*2.25 : -0.25 - u*2.25;
    }
    return rnd(seed);
}

// Scan all points with the scalar parser; for every point with a nonzero eval
// error, replace its variables with safe values (1,1,1). Returns the number of
// points patched (0 = data is clean).
static int patchSingularPoints(FunctionParser& scalar, std::vector<double>& bvars,
                               unsigned NB, int nbvar)
{
    int patched = 0;
    for(unsigned i = 0; i < NB; ++i)
    {
        scalar.Eval(&bvars[i*nbvar]);
        if(scalar.EvalError() != 0)
        {
            for(int v = 0; v < nbvar; ++v) bvars[i*nbvar + v] = 1.0;
            ++patched;
        }
    }
    return patched;
}

// Full bit-identical comparison of batch results vs scalar reference.
static bool compareAll(FunctionParser& scalar, const std::vector<double>& bvars,
                       const std::vector<double>& res, unsigned NB, int nbvar)
{
    int mism = 0;
    double maxdiff = 0;
    for(unsigned i = 0; i < NB; ++i)
    {
        double ref = scalar.Eval(&bvars[i*nbvar]);
        if(ref != res[i])
        {
            if(mism < 3)
                printf("  MISMATCH i=%u batch=%.17g scalar=%.17g\n", i, res[i], ref);
            ++mism;
        }
        double d = fabs(ref - res[i]);
        if(d > maxdiff) maxdiff = d;
    }
    if(mism) { printf("  %u mismatches\n", mism); return false; }
    printf("  OK: bit-identical to scalar reference (maxdiff %.3g)\n", maxdiff);
    return true;
}

// ------------------------------------------------------------------- fuzzing
static uint gFuzzSeed;
static uint frnd() { gFuzzSeed = gFuzzSeed*1664525u + 1013904223u; return gFuzzSeed; }

static double fdataVal()
{
    double u = double(frnd() >> 8) / double(0x1000000);
    double v = (u - 0.5) * 5.0;
    if(v > -0.25 && v < 0.25) v = (v < 0 ? -0.25 : 0.25);
    return v;
}

// Random expression over x,y,z using a subset of the built-ins.
static std::string genExpr(int depth)
{
    const char* vars[] = { "x", "y", "z" };
    if(depth <= 0 || frnd() % 4 == 0)
        return std::string(vars[frnd() % 3]);
    const char* un[] = { "sin(%%)", "cos(%%)", "abs(%%)", "sqrt(abs(%%))", "exp(-%%*%%/10)", "log(abs(%%)+1)", "tan(%%/2)", "floor(%%)", "ceil(%%)", "int(%%)" };
    const char* bin[] = { "%%+%%", "%%-%%", "%%*%%", "max(%%,%%)", "min(%%,%%)", "atan2(%%,%%)", "hypot(%%,%%)", "%%/(abs(%%)+1)" };
    std::string a = genExpr(depth-1);
    std::string b = genExpr(depth-1);
    if(frnd() % 2)
    {
        std::string t = un[frnd() % 10];
        size_t p1 = t.find("%%");
        t.replace(p1, 2, a);
        size_t p2 = t.find("%%");
        if(p2 != std::string::npos) t.replace(p2, 2, b);
        return t;
    }
    std::string t = bin[frnd() % 8];
    size_t p1 = t.find("%%"); t.replace(p1, 2, a);
    size_t p2 = t.find("%%"); t.replace(p2, 2, b);
    return t;
}

// --------------------------------------------------------------------- modes
static int runCheck()
{
    const unsigned NB = 1000;
    int failures = 0;
    for(size_t ci = 0; ci < sizeof(cases)/sizeof(cases[0]); ++ci)
    {
        const Case& c = cases[ci];
        FunctionParser batch, scalar;
        if(!setupParser(batch, c, NB) || !setupParser(scalar, c, NB))
        { failures++; continue; }

        std::vector<double> bvars(NB * c.nbvar);
        uint seed = 12345u + unsigned(ci);
        for(unsigned i = 0; i < NB; ++i)
            for(int v = 0; v < c.nbvar; ++v)
                bvars[i*c.nbvar + v] = rndForVar(seed, v, c.xmode);

        std::vector<double> res(NB);
        bool ok = true;

        // ---------- Phase A: batch on raw data ------------------------
        double code = batch.Eval2(&bvars[0], c.nbvar, &res[0], NB);
        printf("case %zu: %s\n", ci, c.expr);
        printf("  Eval2 return code: %g\n", code);

        if(code == 6)
        {
            ok = compareAll(scalar, bvars, res, NB, c.nbvar);
        }
        else if(code == 5)
        {
            // varying if() across the batch: batch must fall back to scalar
            if(!c.hasPCall && c.xmode != 0) { printf("  UNEXPECTED if-error on uniform-branch case\n"); ok = false; }
            else printf("  (if() non-uniform across batch: scalar fallback, expected)\n");
        }
        else
        {
            // Batch aborted on the first error; results[] not written.
            // Verify the scalar reference contains at least one point of
            // the matching error class.
            int cls = batchCodeErrorClass(code);
            int found = 0;
            for(unsigned i = 0; i < NB; ++i)
            {
                scalar.Eval(&bvars[i*c.nbvar]);
                int et = scalar.EvalError();
                if(et == 1 && cls == 1) { found = 1; break; }
                if(et == 7 && cls == 7) { found = 1; break; }
                if(et >= 2 && et <= 4 && cls == 2) { found = 1; break; }
            }
            if(!found)
            { printf("  UNEXPECTED batch error class %g: no matching scalar error point\n", code); ok = false; }
            else
                printf("  (batch aborted on error class %d, matching a scalar singular point)\n", cls);
        }

        // ---------- Phase B: patch singular points, re-check ----------
        if(ok)
        {
            int patched = 0;
            for(int pass = 0; pass < 5; ++pass)
            {
                int p = patchSingularPoints(scalar, bvars, NB, c.nbvar);
                if(p == 0) break;
                patched += p;
            }
            if(patched)
                printf("  patched %d singular point(s), re-running batch\n", patched);
            code = batch.Eval2(&bvars[0], c.nbvar, &res[0], NB);
            if(code == 6)
            {
                ok = compareAll(scalar, bvars, res, NB, c.nbvar);
            }
            else if(code == 5)
            {
                if(c.xmode != 0) { printf("  UNEXPECTED if-error on uniform-branch case after patching\n"); ok = false; }
                else printf("  (if() still non-uniform after patching: skipped)\n");
            }
            else
            {
                printf("  UNEXPECTED error code %g after patching\n", code);
                ok = false;
            }
        }
        if(!ok) failures++;
    }
    printf(failures ? "CHECK FAILED (%d)\n" : "CHECK PASSED\n", failures);
    return failures ? 1 : 0;
}

static int runFuzz(uint seed, int count)
{
    gFuzzSeed = seed;
    const unsigned NB = 500;
    int failures = 0, skipped = 0, done = 0;
    for(int t = 0; t < count; ++t)
    {
        std::string expr = genExpr(2 + frnd() % 2);
        FunctionParser batch, scalar;
        if(batch.Parse(expr.c_str(), "x,y,z") != -1 || scalar.Parse(expr.c_str(), "x,y,z") != -1)
        { ++skipped; continue; }
        batch.AllocateStackMemory(NB, 3);
        std::vector<double> bvars(NB*3);
        for(unsigned i = 0; i < NB*3; ++i) bvars[i] = fdataVal();
        std::vector<double> res(NB);
        double code = batch.Eval2(&bvars[0], 3, &res[0], NB);
        if(code == 5) { ++skipped; continue; }
        if(code != 6)
        {
            // error class must match a scalar singular point
            int found = 0;
            for(unsigned i = 0; i < NB; ++i) { scalar.Eval(&bvars[i*3]); if(scalar.EvalError() != 0) { found = 1; break; } }
            if(!found) { printf("FUZZ FAIL t=%d: batch error code %g, no scalar error\n%s\n", t, code, expr.c_str()); ++failures; }
            else ++skipped;
            continue;
        }
        bool bad = false;
        for(unsigned i = 0; i < NB; ++i)
        {
            double ref = scalar.Eval(&bvars[i*3]);
            if(scalar.EvalError() != 0) { printf("FUZZ FAIL t=%d: scalar error at i=%u\n%s\n", t, i, expr.c_str()); ++failures; bad = true; break; }
            if(ref != res[i])
            { printf("FUZZ MISMATCH t=%d i=%u batch=%.17g scalar=%.17g\n%s\n", t, i, res[i], ref, expr.c_str()); ++failures; bad = true; break; }
        }
        if(!bad) ++done;
    }
    if(failures)
        printf("FUZZ FAILED (%d failures, %d ok, %d skipped, seed %u)\n",
               failures, done, skipped, seed);
    else
        printf("FUZZ PASSED (%d/%d bit-identical, %d skipped, seed %u)\n",
               done, count, skipped, seed);
    return failures ? 1 : 0;
}

int main(int argc, char** argv)
{
    const char* mode = argc > 1 ? argv[1] : "check";

    if(strcmp(mode, "check") == 0)
    {
        return runCheck();
    }

    if(strcmp(mode, "fuzz") == 0)
    {
        uint seed = argc > 2 ? (uint)strtoul(argv[2], 0, 10) : 424242u;
        int count = argc > 3 ? atoi(argv[3]) : 40;
        if(count < 1) count = 1;
        return runFuzz(seed, count);
    }

    if(strcmp(mode, "bench") == 0)
    {
        // Representative implicit-surface style expression + a heavier one +
        // a cPCall (nested-parser) one.
        const char* exprs[4] =
        {
            "cos(x)+cos(y)+cos(z)",
            "sin(x*y)*exp(-z^2)+(x^2)+sqrt(abs(y))+log(abs(z)+1)",
            "f1(x,y,z)*f2(x,y,z)+f1(f2(x,y,z),x,z)+g(x,y)+sin(x)+cos(y)*tan(z/2)",
            "r(q(x,y,z), y)*q(x, z, x)+h(x, y)",
        };
        const Case pcallCase = { "", "x,y,z", 3, 0, true };
        const char* vars = "x,y,z";
        const unsigned nbvar = 3;
        const unsigned NB = argc > 2 ? (unsigned)atoi(argv[2]) : 100000;

        for(unsigned e = 0; e < 4; ++e)
        {
            FunctionParser p;
            p.AddFunction("f1", raw_mul3, 3);
            p.AddFunction("f2", raw_sinexp, 3);
            p.AddFunction("g", raw_divsafe, 2);
            if(e == 3)
            {
                if(!setupSubsOnce()) return 1;
                p.AddFunction("h", gSubH);
                p.AddFunction("q", gSubQ);
                p.AddFunction("r", gSubR);
            }
            if(p.Parse(exprs[e], vars) != -1) { printf("parse fail expr %u\n", e); return 1; }
            p.AllocateStackMemory(NB, nbvar);
            if(e == 3)
            {
                gSubH.AllocateStackMemory(NB, 2);
                gSubQ.AllocateStackMemory(NB, 3);
                gSubR.AllocateStackMemory(NB, 2);
            }
            (void)pcallCase;

            std::vector<double> bvars(NB * nbvar);
            uint seed = 777u;
            for(unsigned i = 0; i < NB*nbvar; ++i) bvars[i] = rnd(seed);
            std::vector<double> res(NB);

            // warmup
            for(int w = 0; w < 2; ++w) p.Eval2(&bvars[0], nbvar, &res[0], NB);

            const int reps = 5;
            auto t0 = std::chrono::high_resolution_clock::now();
            for(int r = 0; r < reps; ++r) p.Eval2(&bvars[0], nbvar, &res[0], NB);
            auto t1 = std::chrono::high_resolution_clock::now();
            double ms = std::chrono::duration<double, std::milli>(t1 - t0).count() / reps;
            printf("expr[%u] NB=%u: %.3f ms   (%.2f Mpoints/s)\n",
                   e, NB, ms, double(NB)/ (ms*1000.0));
            (void)res[0];
        }
        return 0;
    }

    if(strcmp(mode, "bench_mt") == 0)
    {
        // Mimic VoxelEvaluation: T worker threads, each owning one parser and
        // one contiguous region (point-major Vars, one big Eval2 call).
        const char* exprs[2] =
        {
            "cos(x)+cos(y)+cos(z)",
            "(sin(x)*cos(y)+cos(x)*sin(y))*(exp(-(x^2+y^2)/2))+(sin(x+y+z)+cos(x-y-z))*(x^3-3*x*y^2)+cos(x*z)*sin(y*z)+sqrt(x^2+y^2+z^2)*log(1+x^2)/(abs(y)+abs(z)+1)+atan2(x,y)+atan2(y,z)+max(x,y)-min(x,z)+floor(x)+ceil(y)-trunc(z)",
        };
        const unsigned nbvar = 3;
        const unsigned NBtotal = argc > 3 ? (unsigned)atoi(argv[3]) : 2000000;
        const int T = argc > 2 ? atoi(argv[2]) : 4;

        std::mutex mt;
        for(unsigned e = 0; e < 2; ++e)
        {
            unsigned per = NBtotal / (unsigned)T;
            per = (per + 1023u) & ~1023u; // round up to 1024
            std::vector<std::thread> workers;
            double totalMs = 0;
            const int reps = 3;

            auto t0 = std::chrono::high_resolution_clock::now();
            for(int t = 0; t < T; ++t)
            {
                workers.emplace_back([&, t]() {
                    FunctionParser p;
                    if(p.Parse(exprs[e], "x,y,z") != -1) { printf("parse fail\n"); return; }
                    p.AllocateStackMemory(per, nbvar);
                    std::vector<double> bvars(per * nbvar);
                    uint seed = 777u + unsigned(t);
                    for(unsigned i = 0; i < per*nbvar; ++i) bvars[i] = rnd(seed);
                    std::vector<double> res(per);
                    double localMs = 0;
                    for(int r = 0; r < reps; ++r)
                    {
                        auto a = std::chrono::high_resolution_clock::now();
                        p.Eval2(&bvars[0], nbvar, &res[0], per);
                        auto b = std::chrono::high_resolution_clock::now();
                        localMs += std::chrono::duration<double, std::milli>(b - a).count();
                    }
                    std::unique_lock<std::mutex> lk(mt);
                    totalMs += localMs / reps;
                });
            }
            for(auto& w : workers) w.join();
            auto t1 = std::chrono::high_resolution_clock::now();
            double wall = std::chrono::duration<double, std::milli>(t1 - t0).count();
            printf("expr[%u] T=%d NBtotal=%u (per=%u): wall %.3f ms  (%.2f Mpoints/s, sum %.3f ms)\n",
                   e, T, (unsigned)NBtotal, per, wall,
                   double(NBtotal) / (wall * 1000.0), totalMs);
        }
        return 0;
    }

    printf("usage: %s <check|fuzz [seed] [count]|bench [NB]|bench_mt [T] [NBtotal]>\n", argv[0]);
    return 2;
}
