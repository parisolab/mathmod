# fparser Eval2 tests

Standalone correctness + benchmark tests for the batch bytecode interpreter
`FunctionParserBase::Eval2`, the hot path used by the pariso engines
(`Iso3D::VoxelEvaluation`, `Model3D::ParCompute`).

The tests are self-contained: they compile `fparser.cc` directly and compare
the batch interpreter against the scalar `Eval` reference. **No Qt is
required.**

## Build

With qmake (from this directory):

    qmake tests.pro CONFIG+=release
    make -j

Or with a single compiler command:

    c++ -O2 -std=c++17 eval2_test.cpp -I.. ../fparser.cc -o fparser_eval2_test

## Run

    ./fparser_eval2_test                # same as `check`
    ./fparser_eval2_test check          # hand-picked cases: batch vs scalar
    ./fparser_eval2_test fuzz [seed] [count]
    ./fparser_eval2_test bench [NB]     # single-thread throughput
    ./fparser_eval2_test bench_mt [T] [NBtotal]   # multithreaded, mimicking the app

Exit code is `0` on pass, `1` on fail for `check` and `fuzz`.

## What `check` verifies

For each of ~11 hand-picked expressions it runs the batch `Eval2` and the
scalar `Eval` on the same input and requires **bit-identical** results.

Coverage includes:
- the core built-in math opcodes (trig, exponentials, logs, rounding,
  comparisons in `if()`, `max`/`min`, `^`, `1/x`, `atan2`, `hypot`, ...),
- raw user functions (`cFCall`),
- expression-defined user functions including two-level nesting (`cPCall`),
- `if()` with a varying condition (must force the scalar fallback, code 5),
  and with a uniform condition (must run in batch, both branches),
- division-by-zero / domain-error abort semantics (batch aborts on the first
  singular point; the error class must match a scalar singular point).

## What `fuzz` verifies

Generates random expressions over `x,y,z` and random data, then requires the
batch result to be bit-identical to the scalar reference (or, on an error, to
match a scalar singular point of the same class). Deterministic per seed;
the default seed is `424242`.

## Note on conventions

This fparser fork differs from upstream:
- `Parse()` returns `-1` on success (>=0 = error position).
- `Eval2()` returns `6` (EVAL_NO_ERROR), `5` (IF_FUNCT_ERROR), `7`
  (VAR_OVERFLOW), `1` (DIVISION_BY_ZERO), or `0` (domain errors 2..4).
- `Vars` are point-major: point `e`, variable `v` is at `Vars[e*NbVar+v]`.

The test file documents these; keep it in sync if they ever change.

## strict_minimal_model_test

Regression check for the collection's catenoid-helicoid associate family
(`Helicoid_To_Catenoid` and its strict companion `Minimal_Helicoid_Catenoid`
at the end of `mathmodcollection.js`). It replicates the exact
compile/eval mechanism of `pariso/parametric/Model3D.cpp` (one
`FunctionParser` per field, `AddConstant("pi", PI)` with the app's 9-digit
PI from `pariso/commun.h` — **not** `M_PI` —, `Parse(expr, "u,v,t")`,
`AllocateStackMemory(NB, 3)`, batch `Eval2`) and verifies:

- all six expressions parse without error;
- batch results are **bit-identical** to a closed-form C++ reference
  (same operation order, same PI, same libm) over the app bounds
  `[-pi,pi]x[-pi,pi]` at 9 t-values;
- the identities model-219 (x,y) == strict family (x,y) and
  model-219 z == 3 x strict z (bit-exact);
- mean curvature from fparser values only (central differences):
  unit-sphere control |H| = 1, strict model |H| < 1e-5 in **every**
  frame (minimal everywhere, including the catenoid frame), and model 219
  |H| ~ 0.44 (= 4/9 at the waist) at the t=0.25 catenoid frame — the
  3x z-stretch is what makes that frame non-minimal.

Both translation units must be compiled without FMA contraction
(buildable via `strict_minimal_model_test.pro` or):

    c++ -O2 -std=c++17 -ffp-contract=off strict_minimal_model_test.cpp \
        -I.. ../fparser.cc -o strict_minimal_model_test
    ./strict_minimal_model_test        # exit 0 = pass

## pow_csc_test

Value verification for the `pow` and `csc` names (registered in
`extrasrc/fp_identifier_parser.inc`; both opcodes, `cPow`/`cCsc`, were
already implemented — `^` compiles to `cPow`):

- `pow(x,y)` is bit-identical to `x^y` (same opcode) and to a faithful
  replication of `fp_pow` (fparser's pow is a hybrid: integer exponents
  use repeated squaring, `x>0` uses `exp(y*log(x))`, fallback `std::pow`
  — it is deliberately **not** libm `pow`);
- `csc(x)` is bit-identical to `1/sin(x)`;
- `csc(0)` aborts the batch with code 1 (division by zero).

    c++ -O2 -std=c++17 -ffp-contract=off pow_csc_test.cpp \
        -I.. ../fparser.cc -o pow_csc_test
    ./pow_csc_test                     # exit 0 = pass

## sixfn_test

Value verification for the six built-ins added to this fork:
`erf`, `round`, `sign`, `coth`, `sech`, `csch` (opcodes in
`extrasrc/fptypes.hh`, name registrations in
`extrasrc/fp_identifier_parser.inc`, math routines in
`extrasrc/fpaux.hh`). Everything goes through the real engine
(Parse + Eval / Eval2):

- name probe: the six new names parse as built-ins, all
  pre-existing names still parse, ComplexOnly names are still
  treated as variables, unknown names still fail;
- real (double) values: `erf` bit-identical to `std::erf`,
  `round` to `std::round`, `coth`/`sech`/`csch` to
  `1/tanh`/`1/cosh`/`1/sinh`; `sign` exact (1/-1/0, NaN->0);
  `coth(0)`/`csch(0)` set `EvalError() == 1` (division by zero);
- complex (double) values through `FunctionParser_cd`:
  `coth`/`sech`/`csch` bit-identical to `1/std::tanh`/`1/std::cosh`/
  `1/std::sinh` of the complex argument; `round`/`sign`
  component-wise (the complex `erf` hybrid is covered by
  `erf_complex_test`);
- batch `Eval2` (tiled) bit-identical to scalar `Eval` for all
  six; a `coth`/`csch` batch containing x=0 aborts with code 1.

    c++ -O2 -std=c++17 -ffp-contract=off sixfn_test.cpp \
        -I.. ../fparser.cc -o sixfn_test
    ./sixfn_test                      # exit 0 = pass

## erf_complex_test

Verification of the self-implemented complex `fp_erf`
(`extrasrc/fpaux.hh` — the standard library has no `std::erf()`
for complex numbers). It compares the engine's results, through
`FunctionParser_cd`, against the reference table `erf_ref_table.h`
(3177 points of `erf(x+i y)` computed with mpmath 1.4.1 at
dps = 60 and converted to double, `INFINITY` where the true
component overflows double). The grid covers all four hybrid
branches (Taylor |z| <= 3, imaginary-axis erfi, near-axis D-strip,
Stieltjes continued fraction), their switching boundaries
(|z| ~ 3, Re(z^2) ~ 700), the negative-x oddness path, and the
component-overflow band (|erf| ~ 1e305..1e308).

Acceptance: finite reference components within
`5e-12 * max(1, |Re(ref)|, |Im(ref)|)` (measured worst case
~1e-13), infinite reference components must be inf of the same
sign; oddness (`erf(-z) == -erf(z)`) and conjugate symmetry
(`erf(conj(z)) == conj(erf(z))`) bit-exact; a few points
through the `std::complex<float>` instantiation with a
float-precision tolerance.

`erf_ref_table.h` is auto-generated (do not edit by hand);
regenerate it with the mpmath generator script used in the
development session (grid layout documented in the comments of
`erf_ref_table.h`).

    c++ -O2 -std=c++17 -ffp-contract=off erf_complex_test.cpp \
        -I.. ../fparser.cc -o erf_complex_test
    ./erf_complex_test                # exit 0 = pass
