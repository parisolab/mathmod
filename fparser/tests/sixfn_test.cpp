// Value verification of the six built-in functions added to this fparser
// fork: erf, round, sign, coth, sech, csch
// (opcodes in extrasrc/fptypes.hh, name registrations in
// extrasrc/fp_identifier_parser.inc, math routines in extrasrc/fpaux.hh).
//
// Everything goes through the real engine (Parse + Eval / Eval2):
//   1. Name probe: the six new names parse as built-ins in the real
//      (double) parser, all pre-existing names still parse, ComplexOnly
//      names are still treated as variables, and unknown names still
//      fail. (Parse() returns -1 on success in this fork; see
//      eval2_test.cpp.)
//   2. Real (double) values:
//        erf            bit-identical to std::erf
//        round          bit-identical to std::round
//        sign           exact (1 / -1 / 0; NaN -> 0)
//        coth/sech/csch bit-identical to 1/tanh, 1/cosh, 1/sinh
//        coth(0), csch(0) -> EvalError() == 1 (division by zero)
//   3. Complex (double) values through FunctionParser_cd:
//        coth/sech/csch bit-identical to 1/std::tanh, 1/std::cosh,
//        1/std::sinh of the complex argument
//        round/sign     component-wise
//      (the complex erf hybrid has its own dedicated table test:
//       erf_complex_test.cpp, since stdlib has no complex std::erf)
//   4. Batch Eval2 (tiled) results bit-identical to scalar Eval for all
//      six functions; a coth/csch batch containing x = 0 aborts with
//      code 1 (division by zero).
//
// Build (from fparser/tests/):
//   c++ -O2 -std=c++17 -ffp-contract=off sixfn_test.cpp -I.. ../fparser.cc -o sixfn_test
//   ./sixfn_test        # exit 0 = pass

#include "fparser.hh"
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>

static int gFail = 0, gPass = 0;

static void checkBits(const char* what, double a, double b)
{
    unsigned long long ba, bb;
    std::memcpy(&ba, &a, 8);
    std::memcpy(&bb, &b, 8);
    const bool ok = (ba == bb) || ((a == 0) && (b == 0)); // +0 / -0
    if(ok) { ++gPass; }
    else
    {
        ++gFail;
        std::printf("FAIL(bits) %s: got %.17g (0x%016llx), want %.17g (0x%016llx)\n",
                    what, a, ba, b, bb);
    }
}

static void checkEq(const char* what, double a, double b)
{
    if(a == b) { ++gPass; }
    else { ++gFail; std::printf("FAIL(eq) %s: got %g, want %g\n", what, a, b); }
}

// ------------------------------------------------------------------
// 1. Name probe
// ------------------------------------------------------------------
static void nameProbe()
{
    std::printf("== name probe ==\n");
    // NOTE on the return convention of this fork (fparser.cc,
    // FunctionParserBase::ParseFunction):
    //   -1   -> success
    //   >= 0 -> failure, the index of the error location in the string
    // Probing "name(args)" with the variables x,y,z:
    //   recognized built-in  -> parses fine (-1)
    //   unknown name         -> treated as a variable; calling a
    //                           variable is a parse error
    //   ComplexOnly name     -> dropped from the real parser, same as unknown
    static const struct { const char* e; bool wantBuiltin; } c[] = {
        // new
        { "erf(x)",   true }, { "round(x)", true }, { "sign(x)", true },
        { "coth(x)",  true }, { "sech(x)",  true }, { "csch(x)", true },
        // pre-existing must NOT regress
        { "exp(x)",   true }, { "exp2(x)",  true }, { "log(x)",  true },
        { "log2(x)",  true }, { "log10(x)", true }, { "pow(x,y)", true },
        { "sqrt(x)",  true }, { "cbrt(x)",  true }, { "hypot(x,y)", true },
        { "sin(x)",   true }, { "cos(x)",   true }, { "tan(x)",  true },
        { "asin(x)",  true }, { "acos(x)",  true }, { "atan(x)", true },
        { "atan2(x,y)", true },
        { "sec(x)",   true }, { "csc(x)",   true }, { "cot(x)",  true },
        { "sinh(x)",  true }, { "cosh(x)",  true }, { "tanh(x)", true },
        { "asinh(x)", true }, { "acosh(x)", true }, { "atanh(x)", true },
        { "abs(x)",   true }, { "floor(x)", true }, { "ceil(x)", true },
        { "trunc(x)", true },
        { "int(x)",   true }, { "max(x,y)", true }, { "min(x,y)", true },
        { "if(x>0,y,z)", true }, { "psh(x,y)", true }, { "csd(x)", true },
        // ComplexOnly -> treated as variable in the real parser
        { "real(x)",  false }, { "imag(x)", false }, { "conj(x)", false },
        { "polar(x,y)", false }, { "arg(x)", false },
        // must remain unknown (variables)
        { "erfc(x)",  false }, { "rint(x)", false }, { "gamma(x)", false },
        { "fmod(x,y)", false }, { "get(x)", false },
    };
    for(unsigned i = 0; i < sizeof c / sizeof c[0]; ++i)
    {
        FunctionParser p;
        const int r = p.Parse(c[i].e, "x,y,z");
        const bool isBuiltin = (r == -1);
        if(isBuiltin == c[i].wantBuiltin) { ++gPass; }
        else
        {
            ++gFail;
            std::printf("FAIL(name) %-13s: Parse=%d (%s), want builtin=%d\n",
                        c[i].e, r,
                        r >= 0 ? p.ErrorMsg() : "success",
                        (int)c[i].wantBuiltin);
        }
    }
}

// ------------------------------------------------------------------
// 2. Real values
// ------------------------------------------------------------------
static void realValues()
{
    std::printf("== real values ==\n");
    FunctionParser p;
    double xs[] = { 0.0, 1.0, -1.0, 2.5, -2.5, 0.5, -0.5, 1.5, -1.5,
                    0.25, -0.75, 3.14159265, -3.14159265, 1e-8, 1e8, 0.123456789 };

    // --- erf
    p.Parse("erf(x)", "x");
    for(unsigned i = 0; i < sizeof xs / sizeof xs[0]; ++i)
    {
        const double x = xs[i];
        char tag[64]; std::snprintf(tag, sizeof tag, "erf(%g)", x);
        checkBits(tag, p.Eval(&x), std::erf(x));
    }

    // --- round
    p.Parse("round(x)", "x");
    for(unsigned i = 0; i < sizeof xs / sizeof xs[0]; ++i)
    {
        const double x = xs[i];
        char tag[64]; std::snprintf(tag, sizeof tag, "round(%g)", x);
        checkBits(tag, p.Eval(&x), std::round(x));
    }

    // --- sign
    p.Parse("sign(x)", "x");
    double sx[] = { 0.0, 1.0, -1.0, 0.5, -0.5, 123.456, -9.75e-3, 1e300, -1e-300 };
    for(unsigned i = 0; i < sizeof sx / sizeof sx[0]; ++i)
    {
        const double x = sx[i];
        const double want = x > 0 ? 1.0 : (x < 0 ? -1.0 : 0.0);
        char tag[64]; std::snprintf(tag, sizeof tag, "sign(%g)", x);
        checkEq(tag, p.Eval(&x), want);
    }
    // NaN -> 0 (both comparisons false)
    const double nan = std::nan("");
    checkEq("sign(NaN)", p.Eval(&nan), 0.0);

    // --- coth
    p.Parse("coth(x)", "x");
    double cx[] = { 0.1, -0.1, 0.5, -0.5, 1.0, -1.0, 2.0, -2.0, 0.777, -12.5 };
    for(unsigned i = 0; i < sizeof cx / sizeof cx[0]; ++i)
    {
        const double x = cx[i];
        char tag[64]; std::snprintf(tag, sizeof tag, "coth(%g)", x);
        checkBits(tag, p.Eval(&x), 1.0 / std::tanh(x));
    }
    // coth(0) -> division-by-zero error code 1
    const double z = 0.0;
    p.Eval(&z);
    if(p.EvalError() == 1) { ++gPass; }
    else { ++gFail; std::printf("FAIL(coth0) error code=%d, want 1\n", p.EvalError()); }

    // --- sech
    p.Parse("sech(x)", "x");
    double qx[] = { 0.0, 0.25, -0.25, 1.0, -1.0, 3.0, -3.0, 0.125, -7.5 };
    for(unsigned i = 0; i < sizeof qx / sizeof qx[0]; ++i)
    {
        const double x = qx[i];
        char tag[64]; std::snprintf(tag, sizeof tag, "sech(%g)", x);
        checkBits(tag, p.Eval(&x), 1.0 / std::cosh(x));
    }

    // --- csch
    p.Parse("csch(x)", "x");
    for(unsigned i = 0; i < sizeof cx / sizeof cx[0]; ++i)
    {
        const double x = cx[i];
        char tag[64]; std::snprintf(tag, sizeof tag, "csch(%g)", x);
        checkBits(tag, p.Eval(&x), 1.0 / std::sinh(x));
    }
    // csch(0) -> division-by-zero error code 1
    p.Eval(&z);
    if(p.EvalError() == 1) { ++gPass; }
    else { ++gFail; std::printf("FAIL(csch0) error code=%d, want 1\n", p.EvalError()); }
}

// ------------------------------------------------------------------
// 3. Complex values (coth/sech/csch/round/sign; erf: see erf_complex_test)
// ------------------------------------------------------------------
static void complexValues()
{
    std::printf("== complex values ==\n");
    FunctionParser_cd p;
    std::complex<double> zs[] = {
        {1.0, 2.0}, {-1.5, 0.25}, {0.0, 1.0}, {2.5, -0.75},
        {0.1, 0.1}, {-3.0, 0.0}, {0.0, -2.0}, {1.25, 3.75}
    };
    char tag[96];

    p.Parse("coth(z)", "x,y,z");
    for(unsigned i = 0; i < sizeof zs / sizeof zs[0]; ++i)
    {
        const std::complex<double> want = std::complex<double>(1.0) / std::tanh(zs[i]);
        const std::complex<double> got = p.Eval(&zs[i]);
        std::snprintf(tag, sizeof tag, "coth(%g%+gi)", zs[i].real(), zs[i].imag());
        checkBits(tag, got.real(), want.real());
        checkBits(tag, got.imag(), want.imag());
    }

    p.Parse("sech(z)", "x,y,z");
    for(unsigned i = 0; i < sizeof zs / sizeof zs[0]; ++i)
    {
        const std::complex<double> want = std::complex<double>(1.0) / std::cosh(zs[i]);
        const std::complex<double> got = p.Eval(&zs[i]);
        std::snprintf(tag, sizeof tag, "sech(%g%+gi)", zs[i].real(), zs[i].imag());
        checkBits(tag, got.real(), want.real());
        checkBits(tag, got.imag(), want.imag());
    }

    p.Parse("csch(z)", "x,y,z");
    for(unsigned i = 0; i < sizeof zs / sizeof zs[0]; ++i)
    {
        const std::complex<double> want = std::complex<double>(1.0) / std::sinh(zs[i]);
        const std::complex<double> got = p.Eval(&zs[i]);
        std::snprintf(tag, sizeof tag, "csch(%g%+gi)", zs[i].real(), zs[i].imag());
        checkBits(tag, got.real(), want.real());
        checkBits(tag, got.imag(), want.imag());
    }

    // round: component-wise
    p.Parse("round(z)", "x,y,z");
    std::complex<double> rs[] = {{1.4, 2.6}, {-0.5, 0.5}, {2.5, -2.5}, {0.0, -1.0}};
    for(unsigned i = 0; i < sizeof rs / sizeof rs[0]; ++i)
    {
        const std::complex<double> got = p.Eval(&rs[i]);
        const double wr = std::round(rs[i].real()), wi = std::round(rs[i].imag());
        std::snprintf(tag, sizeof tag, "round(%g%+gi)", rs[i].real(), rs[i].imag());
        checkEq(tag, got.real(), wr);
        checkEq(tag, got.imag(), wi);
    }

    // sign: component-wise
    p.Parse("sign(z)", "x,y,z");
    std::complex<double> ss[] = {{2.3, -1.7}, {0.0, 5.0}, {-4.0, 0.0}, {0.5, -0.5}};
    for(unsigned i = 0; i < sizeof ss / sizeof ss[0]; ++i)
    {
        const std::complex<double> got = p.Eval(&ss[i]);
        const double wr = ss[i].real() > 0 ? 1 : (ss[i].real() < 0 ? -1 : 0);
        const double wi = ss[i].imag() > 0 ? 1 : (ss[i].imag() < 0 ? -1 : 0);
        std::snprintf(tag, sizeof tag, "sign(%g%+gi)", ss[i].real(), ss[i].imag());
        checkEq(tag, got.real(), wr);
        checkEq(tag, got.imag(), wi);
    }
}

// ------------------------------------------------------------------
// 4. Batch Eval2 (tiled) vs scalar Eval
// ------------------------------------------------------------------
static void batchVsScalar()
{
    std::printf("== batch (Eval2) vs scalar ==\n");
    static const char* exprs[] = { "erf(x)", "round(x)", "sign(x)",
                                   "coth(x)", "sech(x)", "csch(x)" };
    // avoid x = 0 for coth/csch (error path; checked separately below)
    double xs[] = { 0.31, -0.77, 1.0, 2.5, -1.25, 0.031, 5.0, -0.5 };
    const unsigned N = sizeof xs / sizeof xs[0];
    const unsigned NB = 3; // batch (tile) size

    for(unsigned e = 0; e < sizeof exprs / sizeof exprs[0]; ++e)
    {
        FunctionParser ps, pb;
        if(ps.Parse(exprs[e], "x") != -1 || pb.Parse(exprs[e], "x") != -1)
        { ++gFail; std::printf("FAIL(parse batch %s)\n", exprs[e]); continue; }
        pb.AllocateStackMemory(N, 1);

        for(unsigned i = 0; i + NB <= N; i += NB)
        {
            double scal[NB];
            for(unsigned k = 0; k < NB; ++k) scal[k] = ps.Eval(&xs[i + k]);

            double out[NB];
            const double code = pb.Eval2(&xs[i], 1, out, NB);
            if(code != 6.0)
            {
                ++gFail;
                std::printf("FAIL(batch code) %s at x=%g: Eval2 returned %g, want 6\n",
                            exprs[e], xs[i], code);
                continue;
            }
            for(unsigned k = 0; k < NB; ++k)
            {
                char tag[96];
                std::snprintf(tag, sizeof tag, "%s(x=%g) batch", exprs[e], xs[i + k]);
                checkBits(tag, out[k], scal[k]);
            }
        }
    }

    // coth/csch batch containing x = 0 must abort with code 1
    for(unsigned e = 0; e < 2; ++e)
    {
        const char* expr = e ? "csch(x)" : "coth(x)";
        FunctionParser pb;
        if(pb.Parse(expr, "x") != -1) { ++gFail; std::printf("FAIL(parse %s)\n", expr); continue; }
        pb.AllocateStackMemory(3, 1);
        double zs[3] = { 0.7, 0.0, -0.3 };
        double out[3];
        const double code = pb.Eval2(zs, 1, out, 3);
        if(code == 1.0) { ++gPass; }
        else { ++gFail; std::printf("FAIL(batch zero) %s: Eval2 returned %g, want 1\n", expr, code); }
    }
}

// ------------------------------------------------------------------
int main()
{
    nameProbe();
    realValues();
    complexValues();
    batchVsScalar();
    std::printf("\n== %d passed, %d failed ==\n", gPass, gFail);
    return gFail ? 1 : 0;
}
