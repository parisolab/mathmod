// Verification for the new "Minimal_Helicoid_Catenoid" collection entry
// (and identity of the existing "Helicoid_To_Catenoid", model 219)
// against the REAL app expression engine, replicating pariso/parametric/
// Model3D.cpp exactly:
//
//   * one FunctionParser per field  (myParserX / myParserY / myParserZ)
//   * AddConstant("pi", PI)         (PI from pariso/commun.h:27, NOT M_PI)
//   * Parse(expr, "u,v,t")          (ParFunctParameters)
//   * AllocateStackMemory(NB, 3)
//   * Eval2(&vars[0], 3, &res[0], NB)   (point-major: vars[e*3+v])
//
// Checks:
//   1. All expressions parse without error (strict model, model 219,
//      unit-sphere control).
//   2. fparser results are BIT-IDENTICAL to a C++ reference of the same
//      closed form (same operation order, same PI, same libm) over a
//      (u,v) grid covering the app bounds [-pi,pi]x[-pi,pi] at several t.
//   3. Identity: model-219 (x,y) vs strict, and model-219 z vs 3 * strict z
//      (both bit-exact: floating-point addition is commutative, and the
//      only extra factor is an exact sign/3 scaling).
//   4. End-to-end minimal-surface check, mean curvature from
//      fparser-evaluated points only (central differences, h=1e-3):
//         unit sphere (control) -> |H| = 1 exactly (FD accuracy ~1e-6)
//         strict model          -> |H| small at every frame
//         model 219             -> |H| ~ 0.44 at the t=0.25 catenoid frame
//
// Build (from this directory; both TUs compiled with -ffp-contract=off
// so neither side uses FMA):
//   c++ -O2 -std=c++17 -ffp-contract=off strict_minimal_model_test.cpp \
//       -I.. ../fparser.cc -o strict_minimal_model_test

#include "fparser.hh"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

// pariso/commun.h:27
static const double PI = (double(314159265) / double(100000000)); // 3.14159265

struct Field
{
  const char* label;
  const char* expr;
  double (*ref)(double u, double v, double t);
};

// ---------------------------------------------------------------------------
// Closed-form references. Operation order matches the bytecode execution
// (left-to-right, no FMA):  a*b*c == (a*b)*c
// ---------------------------------------------------------------------------
// Strict model (new entry)
//   Fx = sin(2*t*pi)*cosh(v)*cos(u)+cos(2*t*pi)*sinh(v)*sin(u)
//   Fy = sin(2*t*pi)*cosh(v)*sin(u)-cos(2*t*pi)*sinh(v)*cos(u)
//   Fz = v*sin(2*t*pi)+u*cos(2*t*pi)
static double refSx(double u, double v, double t)
{
  double a = 2.0*t*PI;
  double s = std::sin(a), c = std::cos(a);
  double sv = std::sinh(v), cv = std::cosh(v);
  double su = std::sin(u), cu = std::cos(u);
  return ((s*cv)*cu) + ((c*sv)*su);
}
static double refSy(double u, double v, double t)
{
  double a = 2.0*t*PI;
  double s = std::sin(a), c = std::cos(a);
  double sv = std::sinh(v), cv = std::cosh(v);
  double su = std::sin(u), cu = std::cos(u);
  return ((s*cv)*su) - ((c*sv)*cu);
}
static double refSz(double u, double v, double t)
{
  double a = 2.0*t*PI;
  return (v*std::sin(a)) + (u*std::cos(a));
}

// Model 219 (existing collection entry)
//   Fx = cos(2*t*pi)*sinh(v)*sin(u)+sin(2*t*pi)*cosh(v)*cos(u)
//   Fy = -cos(2*t*pi)*sinh(v)*cos(u)+sin(2*t*pi)*cosh(v)*sin(u)
//   Fz = 3*(u*cos(2*t*pi)+v*sin(2*t*pi))
static double refMx(double u, double v, double t)
{
  double a = 2.0*t*PI;
  double s = std::sin(a), c = std::cos(a);
  double sv = std::sinh(v), cv = std::cosh(v);
  double su = std::sin(u), cu = std::cos(u);
  return ((c*sv)*su) + ((s*cv)*cu);
}
static double refMy(double u, double v, double t)
{
  double a = 2.0*t*PI;
  double s = std::sin(a), c = std::cos(a);
  double sv = std::sinh(v), cv = std::cosh(v);
  double su = std::sin(u), cu = std::cos(u);
  return -((c*sv)*cu) + ((s*cv)*su);   // unary minus binds to cos(...)
}
static double refMz(double u, double v, double t)
{
  double a = 2.0*t*PI;
  return 3.0 * ((u*std::cos(a)) + (v*std::sin(a)));
}

// Unit-sphere control (parametrization, t unused): H must come out as 1.
static double refPx(double u, double v, double t) { (void)t; return std::sin(u)*std::cos(v); }
static double refPy(double u, double v, double t) { (void)t; return std::sin(u)*std::sin(v); }
static double refPz(double u, double v, double t) { (void)t; return std::cos(u); }

static const Field strictFields[3] = {
  { "strict Fx", "sin(2*t*pi)*cosh(v)*cos(u)+cos(2*t*pi)*sinh(v)*sin(u)", refSx },
  { "strict Fy", "sin(2*t*pi)*cosh(v)*sin(u)-cos(2*t*pi)*sinh(v)*cos(u)", refSy },
  { "strict Fz", "v*sin(2*t*pi)+u*cos(2*t*pi)",                            refSz },
};
static const Field model219Fields[3] = {
  { "m219 Fx", "cos(2*t*pi)*sinh(v)*sin(u)+sin(2*t*pi)*cosh(v)*cos(u)",    refMx },
  { "m219 Fy", "-cos(2*t*pi)*sinh(v)*cos(u)+sin(2*t*pi)*cosh(v)*sin(u)",   refMy },
  { "m219 Fz", "3*(u*cos(2*t*pi)+v*sin(2*t*pi))",                          refMz },
};
static const Field sphereFields[3] = {
  { "sphere Fx", "sin(u)*cos(v)", refPx },
  { "sphere Fy", "sin(u)*sin(v)", refPy },
  { "sphere Fz", "cos(u)",        refPz },
};

static int gFail = 0;

static bool bitEq(double a, double b)
{
  if(a == b && a == 0.0) return true; // +0.0 == -0.0
  if(a != b) return false;
  unsigned la, lb;
  std::memcpy(&la, &a, sizeof la);
  std::memcpy(&lb, &b, sizeof lb);
  return la == lb;
}

// Parse exactly like Model3D.cpp (AddConstant before Parse, vars "u,v,t").
static bool setup(const Field& f, FunctionParser& p)
{
  p.AddConstant("pi", PI);
  int err = p.Parse(f.expr, "u,v,t");
  if(err >= 0)
  {
    std::printf("  PARSE FAIL %s at %d: %s\n", f.label, err, p.ErrorMsg());
    return false;
  }
  return true;
}

// ---------------------------------------------------------------------------
// Mean curvature magnitude of a parametric surface from evaluated points.
// Central differences (2nd order), textbook second-fundamental-form formula:
//   N  = (Fu x Fv) / |Fu x Fv|
//   e = N.Fuu,  f = N.Fuv,  g = N.Fvv
//   |H| = |eG - 2fF + gE| / (2 (EG - F^2))
// ---------------------------------------------------------------------------
struct Ctx { FunctionParser pX, pY, pZ; };

static void eval3(Ctx& c, double u, double v, double t, double out[3])
{
  c.pX.AllocateStackMemory(1, 3);
  c.pY.AllocateStackMemory(1, 3);
  c.pZ.AllocateStackMemory(1, 3);
  double vars[3] = { u, v, t };
  c.pX.Eval2(&vars[0], 3, &out[0], 1);
  c.pY.Eval2(&vars[0], 3, &out[1], 1);
  c.pZ.Eval2(&vars[0], 3, &out[2], 1);
}

static double meanCurvMag(Ctx& c, double u, double v, double t)
{
  const double h = 1e-3;
  double uu[3] = { u-h, u, u+h }, vv[3] = { v-h, v, v+h };
  double p[3][3][3]; // [u-dir][v-dir][xyz]
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      eval3(c, uu[i], vv[j], t, p[i][j]);

  double fu[3], fv[3], fuu[3], fvv[3], fuv[3];
  for(int c3 = 0; c3 < 3; ++c3)
  {
    fu[c3]  = (p[2][1][c3] - p[0][1][c3]) / (2.0*h);
    fv[c3]  = (p[1][2][c3] - p[1][0][c3]) / (2.0*h);
    fuu[c3] = (p[2][1][c3] - 2.0*p[1][1][c3] + p[0][1][c3]) / (h*h);
    fvv[c3] = (p[1][2][c3] - 2.0*p[1][1][c3] + p[1][0][c3]) / (h*h);
    fuv[c3] = (p[2][2][c3] - p[2][0][c3] - p[0][2][c3] + p[0][0][c3]) / (4.0*h*h);
  }
  double E = fu[0]*fu[0] + fu[1]*fu[1] + fu[2]*fu[2];
  double F = fu[0]*fv[0] + fu[1]*fv[1] + fu[2]*fv[2];
  double G = fv[0]*fv[0] + fv[1]*fv[1] + fv[2]*fv[2];
  double det = E*G - F*F;
  double nx = fu[1]*fv[2] - fu[2]*fv[1];
  double ny = fu[2]*fv[0] - fu[0]*fv[2];
  double nz = fu[0]*fv[1] - fu[1]*fv[0];
  double nw = std::sqrt(nx*nx + ny*ny + nz*nz);
  if(nw < 1e-9) return -1.0;
  nx /= nw; ny /= nw; nz /= nw;
  double e = nx*fuu[0] + ny*fuu[1] + nz*fuu[2];
  double f = nx*fuv[0] + ny*fuv[1] + nz*fuv[2];
  double g = nx*fvv[0] + ny*fvv[1] + nz*fvv[2];
  double H = (e*G - 2.0*f*F + g*E) / (2.0*det);
  return std::fabs(H);
}

int main()
{
  const double ts[] = { 0.0, 0.05, 0.1, 0.25, 0.3, 0.5, 0.75, 0.9, 1.0 };
  const int nts = (int)(sizeof ts / sizeof ts[0]);
  const int N = 17; // grid per axis, includes both bounds
  const int NB = N*N;

  std::vector<double> vars(NB*3), res(NB);

  // ------------------------------------------------ checks 1+2: parse + bits
  for(int m = 0; m < 2; ++m)
  {
    const Field* F = m == 0 ? strictFields : model219Fields;
    FunctionParser pX, pY, pZ;
    FunctionParser* p[3] = { &pX, &pY, &pZ };

    std::printf("== Model %s: parse ==\n", m == 0 ? "strict (new entry)" : "219 (existing)");
    bool ok = true;
    for(int k = 0; k < 3; ++k) ok = setup(F[k], *p[k]) && ok;
    if(!ok) { gFail = 1; return 1; }
    std::printf("  all 3 parsed OK\n");

    int mismatches = 0;
    for(int it = 0; it < nts; ++it)
    {
      double t = ts[it];
      for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
          double u = -PI + (2.0*PI)*i/(N-1);
          double v = -PI + (2.0*PI)*j/(N-1);
          int e = i*N + j;
          vars[e*3+0] = u; vars[e*3+1] = v; vars[e*3+2] = t;
        }
      for(int k = 0; k < 3; ++k)
      {
        p[k]->AllocateStackMemory((unsigned)NB, 3);
        double code = p[k]->Eval2(&vars[0], 3, &res[0], (unsigned)NB);
        if(code != 6.0) // EVAL_NO_ERROR
        {
          std::printf("  EVAL ERROR %s t=%.2f code=%g\n", F[k].label, t, code);
          gFail = 1;
          return 1;
        }
        for(int e = 0; e < NB; ++e)
        {
          double u = -PI + (2.0*PI)*(e/N)/(N-1);
          double v = -PI + (2.0*PI)*(e%N)/(N-1);
          double r = F[k].ref(u, v, t);
          if(!bitEq(res[e], r))
          {
            if(mismatches < 5)
              std::printf("  BIT MISMATCH %s u=%.9f v=%.9f t=%.2f fparser=%.17g ref=%.17g\n",
                          F[k].label, u, v, t, res[e], r);
            ++mismatches;
            gFail = 1;
          }
        }
      }
    }
    std::printf("  bit-identical vs closed form: %s (%d points x 3 fields x %d t-values)\n",
                mismatches ? "FAILED" : "OK", NB, nts);
    if(mismatches) break;
  }

  // ------------------------------------------------ check 3: identity 219 vs strict
  {
    FunctionParser pSX, pSY, pSZ, pMX, pMY, pMZ;
    std::printf("== Identity model219 vs strict (fparser values, all frames) ==\n");
    bool ok = setup(strictFields[0], pSX) && setup(strictFields[1], pSY) && setup(strictFields[2], pSZ)
           && setup(model219Fields[0], pMX) && setup(model219Fields[1], pMY) && setup(model219Fields[2], pMZ);
    if(!ok) { gFail = 1; return 1; }

    double maxXY = 0.0, maxZ = 0.0;
    for(int it = 0; it < nts; ++it)
    {
      double t = ts[it];
      for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
          double u = -PI + (2.0*PI)*i/(N-1);
          double v = -PI + (2.0*PI)*j/(N-1);
          int e = i*N + j;
          vars[e*3+0] = u; vars[e*3+1] = v; vars[e*3+2] = t;
        }
      FunctionParser* pS[3] = { &pSX, &pSY, &pSZ };
      FunctionParser* pM[3] = { &pMX, &pMY, &pMZ };
      std::vector<double> rS(NB), rM(NB);
      for(int k = 0; k < 3; ++k)
      {
        pS[k]->AllocateStackMemory((unsigned)NB, 3);
        pM[k]->AllocateStackMemory((unsigned)NB, 3);
        pS[k]->Eval2(&vars[0], 3, &rS[0], (unsigned)NB);
        pM[k]->Eval2(&vars[0], 3, &rM[0], (unsigned)NB);
        for(int e2 = 0; e2 < NB; ++e2)
        {
          if(k < 2) maxXY = std::max(maxXY, std::fabs(rM[e2] - rS[e2]));
          else      maxZ  = std::max(maxZ,  std::fabs(rM[e2] - 3.0*rS[e2]));
        }
      }
    }
    std::printf("  max|Mx-Sx|, |My-Sy| over all frames: %.3e\n", maxXY);
    std::printf("  max|Mz-3*Sz|  over all frames:       %.3e\n", maxZ);
    if(maxXY > 1e-12 || maxZ > 1e-12)
    { std::printf("  FAIL: identity violated\n"); gFail = 1; }
  }

  // ------------------------------------------------ check 4: |H| end to end
  {
    std::printf("== Mean curvature |H| (from fparser values, central diff h=1e-3) ==\n");
    Ctx cP, cS, cM;
    bool ok = setup(sphereFields[0], cP.pX)  && setup(sphereFields[1], cP.pY)  && setup(sphereFields[2], cP.pZ)
           && setup(strictFields[0], cS.pX)  && setup(strictFields[1], cS.pY)  && setup(strictFields[2], cS.pZ)
           && setup(model219Fields[0], cM.pX) && setup(model219Fields[1], cM.pY) && setup(model219Fields[2], cM.pZ);
    if(!ok) { gFail = 1; return 1; }

    // control: unit sphere (u=theta, v=phi; avoid the poles where the
    // parametrization degenerates)
    double maxSphere = 0.0;
    for(int i = 1; i < 9; ++i)
      for(int j = 1; j < 17; ++j)
      {
        double u = 0.2 + (PI - 0.4)*i/9.0;
        double v = 2.0*PI*j/17.0;
        double hs = meanCurvMag(cP, u, v, 0.0);
        maxSphere = std::max(maxSphere, std::fabs(hs - 1.0));
      }
    std::printf("  sphere control: max||H|-1| = %.3e (FD tolerance ~1e-5)\n", maxSphere);
    if(maxSphere > 1e-5) { std::printf("  FAIL: sphere control wrong, |H| formula/pipeline broken\n"); gFail = 1; }

    const double hts[] = { 0.0, 0.1, 0.25, 0.5 };
    double maxHS = 0.0, maxHM219cat = 0.0;
    for(double t : hts)
    {
      double hs = 0.0, hm = 0.0;
      // 11x11 grid incl. (u,v)=(0,0): the m219 catenoid-frame |H| maximum
      // (exactly 4/9) sits at the origin and is missed by 9-division grids.
      for(int i = 0; i < 11; ++i)
        for(int j = 0; j < 11; ++j)
        {
          double u = -PI + (2.0*PI)*i/10.0;
          double v = -PI + (2.0*PI)*j/10.0;
          double s = meanCurvMag(cS, u, v, t);
          double mm = meanCurvMag(cM, u, v, t);
          if(s > hs) hs = s;
          if(mm > hm) hm = mm;
        }
      std::printf("  t=%.2f : strict max|H| = %.3e   m219 max|H| = %.6f\n", t, hs, hm);
      if(hs > maxHS) maxHS = hs;
      if(t == 0.25) maxHM219cat = hm;
    }
    std::printf("  summary: strict max|H| all frames = %.3e (want < 1e-5)\n", maxHS);
    std::printf("            m219 catenoid frame (t=0.25) max|H| = %.3f (expect ~0.44)\n", maxHM219cat);
    if(maxHS > 1e-5) { std::printf("  FAIL: strict model not minimal\n"); gFail = 1; }
    if(maxHM219cat < 0.3 || maxHM219cat > 0.6)
      std::printf("  NOTE: m219 catenoid |H| outside expected 0.3..0.6 range\n");
  }

  std::printf("\n%s\n", gFail ? "RESULT: FAIL" : "RESULT: PASS");
  return gFail;
}
