// Value verification for the newly registered `pow` and `csc` names.
// Uses the real FunctionParser (app mechanism) and requires:
//   * pow(x,y)  bit-identical to x^y            (same cPow opcode)
//   * pow(x,y)  bit-identical to a faithful replication of fp_pow
//               (fparser's pow is a hybrid: integer-y repeated squaring,
//                x>0 uses exp(y*log(x)), fallback std::pow — see
//                fp_pow in fparser/extrasrc/fpaux.hh; it is NOT libm pow)
//   * csc(x)    bit-identical to 1/sin(x)
//   * csc(0)    reports division-by-zero (batch code 1)
//
// Build (from this directory; both TUs compiled with -ffp-contract=off
// so neither side uses FMA):
//   c++ -O2 -std=c++17 -ffp-contract=off pow_csc_test.cpp \
//       -I.. ../fparser.cc -o pow_csc_test

#include "fparser.hh"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

static int gFail = 0;

static bool bitEq(double a, double b)
{
  unsigned la, lb;
  std::memcpy(&la, &a, sizeof la);
  std::memcpy(&lb, &b, sizeof lb);
  if(la == lb) return true; // covers NaNs from identical libm calls too
  return (a == 0.0 && b == 0.0); // +0.0 == -0.0
}

// ---- faithful replication of fp_pow (fparser/extrasrc/fpaux.hh) ----
static const double FP_EPS = 1E-12; // Epsilon<double>::defaultValue()
static long makeLongInteger(double v) { return (long)std::trunc(v); }
static bool isLongInteger(double v) { return v == (double)makeLongInteger(v); }
static bool isInteger(double v) { return std::fabs(v - std::floor(v)) <= FP_EPS; }
static double fp_powi_ref(double x, unsigned long y)
{
  double result(1);
  while(y != 0)
  {
    if(y & 1) { result *= x; y -= 1; }
    else      { x = x*x;  y /= 2; }
  }
  return result;
}
static double pow_ref(double x, double y)
{
  if(x == 1.0) return 1.0;
  if(isLongInteger(y))
  {
    if(y >= 0.0) return fp_powi_ref(x, (unsigned long)makeLongInteger(y));
    return 1.0 / fp_powi_ref(x, (unsigned long)(-makeLongInteger(y)));
  }
  if(y >= 0.0)
  {
    if(x > 0.0) return std::exp(std::log(x) * y);
    if(x == 0.0) return 0.0;
    if(!isInteger(y*16.0))
      return -std::exp(std::log(-x) * y);
  }
  else
  {
    if(x > 0.0) return std::exp(std::log(1.0 / x) * (0.0 - y));
    if(x < 0.0)
    {
      if(!isInteger(y * (0.0 - 16.0)))
        return -std::exp(std::log((0.0 - 1.0) / x) * (0.0 - y));
    }
  }
  return std::pow(x, y);
}

int main()
{
  // x^y grid: x<0 is fine (fp_pow has explicit negative-x paths); avoid 0^y
  std::vector<double> xs, ys;
  for(double x = -2.0; x <= 2.0; x += 0.1)
    if(x > 0.05 || x < -0.05) xs.push_back(x);
  for(double y = -2.0; y <= 2.0; y += 0.1)
    if(std::fabs(y) > 0.05) ys.push_back(y);

  const int NX = (int)xs.size(), NY = (int)ys.size();
  const int NB = NX*NY;
  std::vector<double> vars(NB*2), rPow(NB), rCaret(NB);

  FunctionParser pPow, pCaret, pCsc;
  if(pPow.Parse("pow(x,y)", "x,y") != -1)   { printf("PARSE FAIL pow: %s\n", pPow.ErrorMsg()); return 1; }
  if(pCaret.Parse("x^y", "x,y") != -1)      { printf("PARSE FAIL caret: %s\n", pCaret.ErrorMsg()); return 1; }
  if(pCsc.Parse("csc(x)", "x") != -1)       { printf("PARSE FAIL csc: %s\n", pCsc.ErrorMsg()); return 1; }
  printf("parse: pow(x,y) OK, x^y OK, csc(x) OK\n");

  int mm = 0;
  for(int i = 0; i < NX; ++i)
    for(int j = 0; j < NY; ++j)
    {
      int e = i*NY + j;
      vars[e*2] = xs[i]; vars[e*2+1] = ys[j];
    }
  pPow.AllocateStackMemory((unsigned)NB, 2);
  pCaret.AllocateStackMemory((unsigned)NB, 2);
  double code = pPow.Eval2(&vars[0], 2, &rPow[0], (unsigned)NB);
  if(code != 6.0) { printf("EVAL ERROR pow code=%g\n", code); return 1; }
  code = pCaret.Eval2(&vars[0], 2, &rCaret[0], (unsigned)NB);
  if(code != 6.0) { printf("EVAL ERROR caret code=%g\n", code); return 1; }
  for(int e = 0; e < NB; ++e)
  {
    double ref = pow_ref(xs[e/NY], ys[e%NY]);
    if(!bitEq(rPow[e], ref))
    {
      if(mm < 3) printf("POW MISMATCH x=%g y=%g fparser=%.17g ref=%.17g\n", xs[e/NY], ys[e%NY], rPow[e], ref);
      ++mm; gFail = 1;
    }
    if(!bitEq(rPow[e], rCaret[e]))
    {
      if(mm < 3) printf("POW!=CARET x=%g y=%g pow=%.17g caret=%.17g\n", xs[e/NY], ys[e%NY], rPow[e], rCaret[e]);
      ++mm; gFail = 1;
    }
  }
  printf("pow: %d points (%d x %d grid): %s (bit-identical to fp_pow reference AND to x^y)\n",
         NB, NX, NY, mm ? "FAILED" : "OK");

  // csc: grid avoiding multiples of pi
  std::vector<double> cx;
  for(double x = -3.0; x <= 3.0; x += 0.1)
    if(std::fabs(std::sin(x)) > 0.05) cx.push_back(x);
  const int NC = (int)cx.size();
  std::vector<double> cvars(NC), rcsc(NC);
  for(int i = 0; i < NC; ++i) cvars[i] = cx[i];
  pCsc.AllocateStackMemory((unsigned)NC, 1);
  code = pCsc.Eval2(&cvars[0], 1, &rcsc[0], (unsigned)NC);
  if(code != 6.0) { printf("EVAL ERROR csc code=%g\n", code); return 1; }
  int cm = 0;
  for(int i = 0; i < NC; ++i)
  {
    double ref = 1.0/std::sin(cx[i]);
    if(!bitEq(rcsc[i], ref))
    {
      if(cm < 3) printf("CSC MISMATCH x=%g fparser=%.17g ref=%.17g\n", cx[i], rcsc[i], ref);
      ++cm; gFail = 1;
    }
  }
  printf("csc: %d points: %s (bit-identical to 1/sin(x))\n", NC, cm ? "FAILED" : "OK");

  // csc(0) must report division by zero (batch abort code 1)
  {
    std::vector<double> cz = { -1e-3, 0.0, 1e-3 };
    std::vector<double> rz(3);
    pCsc.AllocateStackMemory(3, 1);
    code = pCsc.Eval2(&cz[0], 1, &rz[0], 3);
    printf("csc at x=0: batch code=%g (%s)\n", code, code == 1.0 ? "OK: division by zero reported" : "FAIL: expected code 1");
    if(code != 1.0) gFail = 1;
  }

  printf("\n%s\n", gFail ? "RESULT: FAIL" : "RESULT: PASS");
  return gFail;
}
