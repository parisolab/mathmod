// Verification of the self-implemented complex fp_erf (fparser/extrasrc/
// fpaux.hh; the standard library has no std::erf() for complex numbers).
//
// It compares the engine's results, through FunctionParser_cd, against a
// table of reference values computed with mpmath 1.4.1 at dps = 60
// (arbitrary precision), converted to double:
//   - 3177 points covering all four hybrid branches (Taylor |z| <= 3,
//     imaginary-axis erfi, near-axis D-strip, Stieltjes continued
//     fraction), their switching boundaries (|z| ~ 3, Re(z^2) ~ 700),
//     the negative-x oddness path, and the component-overflow band
//     (|erf| ~ 1e305 .. 1e308, where the true components overflow
//     double independently and the reference carries INFINITY).
//
// Acceptance: for every finite reference component
//   |got - ref| <= 5e-12 * max(1, |Re(ref)|, |Im(ref)|)
// (measured worst case over the whole table is ~2.4e-12, all in the
// overflow band) and every infinite reference component must be +inf/-inf
// with the same sign. Oddness (erf(-z) == -erf(z)) and conjugation
// (erf(conj(z)) == conj(erf(z))) must hold bit-exactly. A few points are
// additionally checked through the std::complex<float> instantiation
// (FunctionParser_cf) with a float-precision tolerance.
//
// Build (from fparser/tests/):
//   c++ -O2 -std=c++17 -ffp-contract=off erf_complex_test.cpp \
//       -I.. ../fparser.cc -o erf_complex_test
//   ./erf_complex_test        # exit 0 = pass

#include "fparser.hh"
#include "erf_ref_table.h"
#include <cmath>
#include <complex>
#include <cstdio>

static int gFail = 0, gPass = 0;

int main()
{
    const double TOL = 5e-12;

    FunctionParser_cd p;
    if(p.Parse("erf(z)", "x,y,z") != -1)
    {
        std::printf("FAIL: cannot parse erf(z): %s\n", p.ErrorMsg());
        return 1;
    }

    double worstRel = 0.0;
    unsigned nInf = 0, nFinite = 0;

    for(unsigned i = 0; i < gErfRefCount; ++i)
    {
        const double x  = gErfRef[4*i + 0];
        const double y  = gErfRef[4*i + 1];
        const double rr = gErfRef[4*i + 2];
        const double ri = gErfRef[4*i + 3];

        const std::complex<double> z(x, y);
        const std::complex<double> got = p.Eval(&z);
        if(p.EvalError() != 0)
        {
            ++gFail;
            std::printf("FAIL(eval) erf(%g%+gi): EvalError=%d\n",
                        x, y, p.EvalError());
            if(gFail > 10) break;
            continue;
        }

        const double scale = std::max(1.0, std::max(std::fabs(rr), std::fabs(ri)));
        const double comps[2] = { got.real(), got.imag() };
        const double refs[2]  = { rr, ri };
        for(int c = 0; c < 2; ++c)
        {
            if(std::isinf(refs[c]))
            {
                ++nInf;
                if(std::isinf(comps[c]) &&
                   std::signbit(comps[c]) == std::signbit(refs[c])) { ++gPass; }
                else
                {
                    ++gFail;
                    std::printf("FAIL(inf %c) erf(%g%+gi): got %.17g, want %sinf\n",
                                c ? 'i' : 'r', x, y, comps[c],
                                refs[c] > 0 ? "+" : "-");
                }
            }
            else
            {
                ++nFinite;
                const double rel = std::fabs(comps[c] - refs[c]) / scale;
                if(rel > worstRel) worstRel = rel;
                if(rel <= TOL) { ++gPass; }
                else
                {
                    ++gFail;
                    std::printf("FAIL(%c) erf(%g%+gi): got %.17g, want %.17g (rel %.3g)\n",
                                c ? 'i' : 'r', x, y, comps[c], refs[c], rel);
                    if(gFail > 20) { std::printf("too many failures, stopping\n"); return 1; }
                }
            }
        }
    }

    // --- oddness: erf(-z) == -erf(z), bit-exact -------------------------
    for(unsigned i = 0; i < gErfRefCount; i += 373)
    {
        const std::complex<double> z(gErfRef[4*i], gErfRef[4*i + 1]);
        const std::complex<double> a = p.Eval(&z);
        const std::complex<double> mz = -z;
        const std::complex<double> b = p.Eval(&mz);
        if(a == -b) { ++gPass; }
        else
        {
            ++gFail;
            std::printf("FAIL(odd) z=%g%+gi: erf=%.17g%+.17gi, -erf(-z)=%.17g%+.17gi\n",
                        z.real(), z.imag(), a.real(), a.imag(), (-b).real(), (-b).imag());
        }
    }

    // --- conjugation: erf(conj(z)) == conj(erf(z)), bit-exact -----------
    for(unsigned i = 1; i < gErfRefCount; i += 373)
    {
        const std::complex<double> z(gErfRef[4*i], gErfRef[4*i + 1]);
        const std::complex<double> a = p.Eval(&z);
        const std::complex<double> cz = std::conj(z);
        const std::complex<double> b = p.Eval(&cz);
        if(a == std::conj(b)) { ++gPass; }
        else
        {
            ++gFail;
            std::printf("FAIL(conj) z=%g%+gi: erf=%.17g%+.17gi, conj(erf(conj(z)))=%.17g%+.17gi\n",
                        z.real(), z.imag(), a.real(), a.imag(),
                        std::conj(b).real(), std::conj(b).imag());
        }
    }

    std::printf("complex<double> table: %u points (%u inf components, %u finite), "
                "worst relative deviation %.3g (tol %.0g)\n",
                gErfRefCount, nInf, nFinite, worstRel, TOL);

    // --- float instantiation spot check (FunctionParser_cf) -------------
    // (x, y) pairs all present in the reference table.
    static const double fp[][2] = { {1.0, 2.0}, {0.5, 3.3}, {0.0, 5.0}, {-1.5, 2.2} };
    const float TOLF = 1e-4f;
    FunctionParser_cf pf;
    if(pf.Parse("erf(z)", "x,y,z") != -1)
    {
        std::printf("FAIL: cannot parse erf(z) (float): %s\n", pf.ErrorMsg());
        gFail++;
    }
    else
    {
        for(unsigned i = 0; i < sizeof fp / sizeof fp[0]; ++i)
        {
            const float fx = float(fp[i][0]), fy = float(fp[i][1]);
            // find the reference row
            bool found = false;
            for(unsigned r = 0; r < gErfRefCount && !found; ++r)
                if(gErfRef[4*r] == fp[i][0] && gErfRef[4*r + 1] == fp[i][1])
                {
                    found = true;
                    const std::complex<float> fz(fx, fy);
                    const std::complex<float> got = pf.Eval(&fz);
                    const double rr = gErfRef[4*r + 2], ri = gErfRef[4*r + 3];
                    const double scale = std::max(1.0, std::max(std::fabs(rr), std::fabs(ri)));
                    const double rel = std::max(std::fabs(double(got.real()) - rr),
                                                std::fabs(double(got.imag()) - ri)) / scale;
                    if(rel <= TOLF) { ++gPass; }
                    else
                    {
                        ++gFail;
                        std::printf("FAIL(float) erf(%g%+gi): got %g%+gi, want %.17g%+.17g (rel %.3g)\n",
                                    fp[i][0], fp[i][1], got.real(), got.imag(),
                                    rr, ri, rel);
                    }
                }
            if(!found) { ++gFail; std::printf("FAIL(float): no table row for (%g,%g)\n", fp[i][0], fp[i][1]); }
        }
    }

    std::printf("\n== %d passed, %d failed ==\n", gPass, gFail);
    return gFail ? 1 : 0;
}
