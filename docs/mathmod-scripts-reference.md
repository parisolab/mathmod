# MathMod Script Collection — Reference

Reference for the MathMod model/script format as used by
`mathmodcollection.js` (~400 models) and `advancedmodels.js` in the repo
root. This is the canonical description of what a "MathMod script" is:
JSON blocks of surface definitions written in the MathMod expression
language (compiled by the `fparser` engine).

> Sources: the collection files themselves, `json_parser/`,
> `ui_modules/parametersoptions.cpp`, `ui_modules/drawingoptions.cpp`,
> `pariso/commun.h`, and `fparser/` (built-in name table in
> `fparser/extrasrc/fp_identifier_parser.inc`).

---

## 1. File format

- Extension `.js` but the content is **JSON** (top-level object).
- It is *JS-flavored* JSON: string values may contain **raw control
  characters** (e.g. a raw tab inside a Description). Strict JSON parsers
  need `strict=False` (Python) or equivalent. Always parse leniently.
- **`DOTSYMBOL` placeholder**: decimal points are written as the literal
  string `DOTSYMBOL` (e.g. `0DOTSYMBOL5` = `0.5`). The loader replaces
  `DOTSYMBOL` with the locale decimal separator *before* any parsing
  (`parametersoptions.cpp:66,309,389`, `ParisoMathObject.cpp:49`).
  `mathmodcollection.js` mostly uses plain `.` (fractions like `1/100`);
  `advancedmodels.js` uses `DOTSYMBOL` extensively. When *writing*
  scripts, `.` or fractions are fine for the main collection.
- Numbers are stored as **strings** (`"Xmax": ["3/2"]`) — every field
  value is an array of expression strings; the app evaluates them.
- Empty arrays/strings are meaningful (e.g. `""` in a parallel `Cnd`
  array means "no condition for this component").

## 2. Top-level structure

```json
{
  "MathModels":   [ <model entry>, ... ],   // ~400 entries
  "TexturesList": [ {"Texture": <texture object>}, ... ],  // 14
  "PigmentsList": [ {"Pigment": <pigment object>}, ... ]   // 5
}
```

`mathmodcollection_empty.js` is just `{ "MathModels": [] }` — the
template copied to the user file on first run. New models created in the
UI are *appended* to the user file's `MathModels` array
(`DrawingOptions::SaveToFile_CurentMathModel`).

### Model entry

Each `MathModels[i]` object contains **one surface block** (key = type)
plus any combination of the auxiliary blocks `Sliders`, `Texture`,
`Pigment`:

| Surface key | Models | Meaning |
|---|---|---|
| `Iso3D` | 154 | implicit surface `F(x,y,z[,t]) = 0` in a bounding box |
| `Param3D` | 129 | parametric surface `(Fx,Fy,Fz)(u,v,t)` |
| `Param4D` | 6 | 4-D parametric `(Fx,Fy,Fz,Fw)(u,v,t)` (hypercube slice view) |
| `Param3D_C` | 1 | complex-valued surface (uses `Z`, `real`, `psh`/`csd`) |
| `Param4D_C` | 1 | complex 4-D |
| `ParIso` | 2 | **composite**: an array mixing `Param*` and `Iso3D` objects, rendered together (see §6) |

An entry may also carry a top-level `"Name": ["..."]` (the two `ParIso`
entries do; the display name otherwise comes from the surface block).
The loader only *requires* a name to display the model; all surface
fields are read if present (`json_parser/jiso.cpp`, `jpar.cpp`).

## 3. Surface block fields

All array fields are **parallel**: entry *i* of each array describes
component *i* of the model. A single-component model has arrays of
length 1; a two-surface model has length 2 in every parallel array.
(Component counts observed: 1 up to 20; one 6-component Param3D, etc.)

### Iso3D

| Field | Req. | Notes |
|---|---|---|
| `Name` | – | display name (array of 1 string per component, usually shared) |
| `Component` | – | component label(s), e.g. `"Moebius"` |
| `Description` | – | prose, may contain URLs |
| `Const` | – | `["a=2/6", "b=1/250", ...]` named constants available in all expressions |
| `Funct` | – | `["G1=(...)", "Fx=(...)", ...]` user functions, defined in order; may call earlier entries, themselves (recursion), and `Const` values |
| `Import` | – | names of app-internal functions to import, e.g. `["NoiseW"]` (see §5.3) |
| `Fxyz` | **core** | the implicit equation(s) in `x,y,z` (`t` = animation time) |
| `Xmin Xmax Ymin Ymax Zmin Zmax` | **core** | bounding box, one string per component |
| `Cnd` | – | per-component boolean *region* condition in `x,y,z` (keep points where true); `""` = none |
| `Grid` | – | grid resolutions, e.g. `["150"]` |
| `Vect` | – | e.g. `["5"]` (vector/step-related display option) |

### Param3D (and Param3D_C)

| Field | Req. | Notes |
|---|---|---|
| `Name`, `Component`, `Description`, `Const`, `Funct`, `Import`, `Grid`, `Vect` | – | as Iso3D |
| `Fx Fy Fz` | **core** | coordinate functions in `u,v` (`t` = time) |
| `Umin Umax Vmin Vmax` | **core** | parameter domain, one string per component. Bounds may be *expressions* (`"(umax-umin)+umax"`) |
| `Cnd` | – | rarely used |

`Param3D_C` additionally relies on the complex machinery (§5.4):
`Fx="u"`, `Fy="v"`, `Fz="psh((0), real(1/(Z*Z+1))) * if(csd(0)>A, A, ...)"`.

### Param4D / Param4D_C

Same as Param3D plus `Fw` (the 4th coordinate). Used for 4-D slice
visualizations (e.g. `4DTorus`: `Fx=sin(u) Fy=cos(u) Fz=sin(v) Fw=cos(v)`).

## 4. Auxiliary blocks

### `Sliders` (top-level, alongside the surface block)

UI sliders that bind to the model's `Const` names at run time:

```json
"Sliders": {
  "SetNames": ["Lyria", "Wentletrap", "Conus", ...],  // preset sets (optional)
  "Name":     ["alpha", "beta", "N", "umin", ...],    // Const names, one per slider
  "Min":      ["-200", ...], "Max": ["200", ...],
  "Step":     [...], "Position": [...]                // per-slider
}
```

All six keys observed: `SetNames Name Max Min Step Position`, parallel
arrays. `SetNames` is a list of *named value sets* — choosing a set
fills all sliders at once (used for multi-shape models where the same
`Const`s parametrize different animals).

### `Texture` (top-level)

```json
"Texture": {
  "Name": "square",
  "Colors": ["R=...", "G=...", "B=...", "T=1"],   // R/G/B/T channel expressions
  "Noise": "NoiseW(x,y,z,(1),(2),(0))"            // optional scalar field
}
```

`Colors` may use the surface variables *plus* `i_indx` / `j_indx` (grid
line indices — the workhorse of "wireframe/line" textures, e.g.
`R=if((i_indx)%(M)>P|(j_indx)%(M)>P,(8/10),(8/10))`).
`TexturesList[i].Texture` has the same shape (a shared palette of 14).

### `Pigment` (top-level)

Color palette driven by a *gradient* field:

```json
"Pigment": {
  "Name": "Pigment_1",
  "Colors": [ {"Color": {"Name": "Red", "Vrgba": ["V=2/10","R=4/10","G=4/10","B=7/10","A=1"]}}, ... ],
  "Gradient": "3*cos((x*x+y*y)*pi)*sin((y*y+z*z)*pi)",  // scalar field in x,y,z
  "Noise":    "NoiseW(x,y,z,(1),(2),(0))"               // optional
}
```

Each `Vrgba` entry is a control point: `V` = gradient value position,
`R,G,B,A` = color. `PigmentsList[i].Pigment` same shape (5 shared).

## 5. The expression language

Compiled by the fparser engine (`fparser/fparser.cc`, `Parse()` returns
**-1 on success**, `>=0` = error position; do not assume upstream
fparser conventions).

### 5.1 Variables

| var | where | meaning |
|---|---|---|
| `x y z` | Iso3D, textures, pigments | spatial coordinates |
| `u v` | Param3D/4D | parameters (2-D surface); bounds `Umin..Vmax` |
| `t` | everywhere | **animation time**; loop range is model-dependent (idiom `sin(t*pi)` → `t` over `0..2`; `2*t*pi` → `t` over `0..1`) |
| `w` | Param4D | 4th spatial coordinate |
| `Z` | `*_C` models | complex value `u + i*v` (see §5.4) |
| `i_indx j_indx` | Texture `Colors` | integer grid line indices |

Constants the app adds to **every** parser (field parsers and all
`Funct` sub-parsers, before `Parse`): `pi` — the app's own value
`314159265/1e8 = 3.14159265` (`pariso/commun.h:27`, 9 significant
digits, **not** full-precision π — relevant only for sub-ULP
sensitivity) — and `ThreadId` (0-based render thread index; 0 in
single-thread mode). On top of those: every `Const` name and every
`Sliders` name of the model. There are **no other built-in constants**
(`E` is *not* available; `exp(1)` gives e if you need it).

### 5.2 Built-in functions (complete list from the fparser name table)

1-arg: `abs acos asin atan atanh cbrt ceil conj cos cosh cot csd exp
if* int log log2 log10 real sinh sin sqrt tan tanh trunc`

2-arg: `atan2 hypot imag* max min polar* psh*`

(`*` notes: `if(c,a,b)` is the conditional — see §5.5; `conj` = complex
conjugate; `polar` = complex polar form; `psh`/`csd`/`real`/`imag` =
complex store/retrieve/extract, §5.4. `atan2(y,x)`, `hypot(x,y)`.)

### 5.3 Importable app-internal functions

Declared per model via `"Import": ["NoiseW", ...]` (names must match
exactly). Registry: `pariso/commun.h` `InternalFunctions[]`
(name → C++ function, arity):

| name | arity | name | arity |
|---|---|---|---|
| `NoiseW` (turbulent Worley) | 6 | `MarbleP` | 4 |
| `NoiseP` (turbulent Perlin) | 6 | `LegendreA` | 3 |
| `mandelbulb` | 4 | `LaguerreA` | 3 |
| `MandelFractal` | 3 | `JuliaFractal` | 5 |
| `JuliaFractal` | 5 | `CmpId` | 1 |
| `fhelix1` / `fhelix2` | 10 | `f_hex_y` | 4 |
| `fmesh` | 8 | `p_skeletal_int` | 3 |

Typical noise call shape: `NoiseW(x,y,z,(4),(2),(0))` — first 3 args
spatial (often scaled), last 3 control (octaves/seed-style).
`CmpId(i)` returns the *current component id* — used to make each
component of a multi-component model behave differently.

### 5.4 Complex support (`*_C` models)

- `Z` is the complex point `u + i·v`.
- `real(...)` / `imag(...)` / `conj(...)` / `polar(...)` extract/convert.
- `psh(slot, value)` stores `value` into a per-point scratch slot;
  `csd(slot)` reads it back. Idiom for computing one complex value and
  reusing it in several coordinate expressions (e.g.
  `Fz="psh((0), real(1/(Z*Z+1))) * if(csd(0)>A, A, if(csd(0)<-A, -A, csd(0)))"`
  — store Re(f(Z)), then clamp it). Slots are numbered, per point.

### 5.5 Operators

`+ - * /` (binary), unary `-`, `^` (power), `%` (modulo),
comparisons `< > <= >=` and **`=` as equality** (single equals inside
`if` conditions, e.g. `if(M=1, ..., if(M=2, ...))` — chains like this
are the collection's "switch" idiom), `&` (logical and), `|` (logical
or). Comparison results are 1/0 and used multiplicatively
(`(x-y-(3/2)*z<0)` as a mask).

`if(cond, a, b)` — the only conditional. In batch evaluation
(`Eval2`) a condition that varies within a tile forces the scalar
fallback (error code 5 = `IF_FUNCT_ERROR`); a uniform condition runs in
batch.

### 5.6 User-defined functions (`Funct`) and constants (`Const`)

- `Const`: `"name=expr"` — a plain named value (may reference other
  consts, sliders, or built-ins). Added to every parser (field parsers
  *and* all `Funct` sub-parsers) before parsing.
- `Funct`: **`"name=body"` — there is no argument-list syntax.** The
  compiler splits each entry at the *first* `=`
  (`ParMasterThread::HowManyVariables`, Model3D.cpp:1209): the name is
  the raw text before `=`, the body is the rest. All 2749 `Funct`
  entries in the collection are `Name=body`; zero use an
  `name(args)=` form (and such a name could not even be linked —
  parentheses are not valid identifier characters for `AddFunction`).
- The body is parsed against the **surface's variable list**:
  `u,v,t` (Param3D, `ParFunctParameters` Model3D.cpp:42),
  `u,v,t,Z` (`*_C`, Model3D.cpp:43), `x,y,z,t` (Iso3D
  `BasicFunctParameters` Iso3D.cpp:136, used at Iso3D.cpp:909).
  A "function" is thus a *named sub-expression in the surface
  variables*.
- **Calls bind positionally to that list**: `Fx(a,b,c)` evaluates the
  body with `u←a, v←b, t←c`. This is how the finite-difference idiom
  works: after `Fx=u`, the entry
  `DFxu=(Fx(u+c,v,t)-Fx(u,v,t))/c` calls `Fx` twice with shifted `u`.
- **Linking rules** (Model3D.cpp:582-591): entry *i* links to entry
  *j* iff `FunctNames[j]` occurs in body *i* as a **substring**
  (`std::string::find`) and **j < i** (textual order). Callees must be
  defined *before* callers; keep names from being substrings of
  unrelated names (a function named `S` would over-link into `sin`).
  The field→`Funct` link for `Fx/Fy/Fz` uses the same substring test.
- **Name redefinition is allowed** and is the "chained" idiom (e.g.
  `Moebius_Spheres`, `Interlocked_Tori`): a later `Name=...` entry
  updates the binding (fparser `addNewNameData` replaces same-type
  names; links are added in ascending *j*, so the *last* earlier
  definition wins). Thus `Fx=Fx(u, v+shift, t)` creates a *shifted
  copy* of the earlier `Fx` (the body calls the previous definition),
  and entries after it resolve `Fx` to the shifted version.
- **No true self-recursion**: an entry cannot call its own name (the
  link loop is `j < i`); the collection contains none (fparser also
  rejects cyclic parser links via `CheckRecursiveLinking`).
- `pi` and `ThreadId` (plus all `Const` and slider names) are added to
  every sub-parser before `Parse`.
- `Funct` is **optional**: 200 of the 402 surface blocks in the
  collection have none — the fields are then bare expressions (the
  style of `Helicoid_To_Catenoid`).

## 6. `ParIso` composite models

`"ParIso": [ <Param3D object>, <Iso3D object>, ... ]` plus a
top-level `"Name"`. The array holds full surface blocks (each with its
own `Name`/`Fxyz` or `Fx..`/etc.); they are rendered as one combined
scene (e.g. `Pariso_01` = a `Param3D` torus family + implicit
companions; `Pariso_02` = `Param3D` "Blobby_Torus" + `Iso3D`
"Models_Intersection" with `Cnd` masks and `t`-animated bounds like
`"Xmax": ["4+4*sin(t*pi)", "6"]`).

## 7. Recurring idioms (memorize these)

1. **Finite-difference derivatives** — the workhorse of thick surfaces:
   ```
   c=1/10000                       (Const)
   Fx=u ; Fy=v ; Fz=-sin(pi*(u^2+v^2))/3
   DFxu=(Fx(u+c,v,t)-Fx(u,v,t))/c
   DFyv=(Fy(u,v+c,t)-Fy(u,v,t))/c   (and all 6 combos)
   ```
   (calls to the *earlier-defined* `Fx`/`Fy`/… — positional binding,
   §5.6; same pattern with `dv` for v-derivatives, second derivatives
   `DFxv2` for curvature.)
2. **Normal + thick surface** —
   `n1=(DFyu*DFzv-DFzu*DFyv)` (cross product), `R=...norm...`,
   offset `Gx=Fx+T*n1/R`, boundary masking via
   `if(u<umax & (v=vmin|v=vmax|u=umin), Fx, Gx)`.
3. **Noise displacement** — multiply the whole parametric expression by
   `(1-NoiseW(Fx,Fy,Fz,(1),(2),(0)))` (feed the *surface point* into
   the noise so the displacement follows the geometry).
4. **Animation** — everything time-dependent goes through `t`; typical
   loops use `sin(t*pi)` / `cos(t)` so `t∈[0,2]` or `[0,2*pi]` loops
   cleanly; bounds can be animated too (`"Xmax": ["4+4*sin(t*pi)"]`).
5. **Region masks** — implicit regions via `Cnd` (`"sqrt(x^2+y^2+z^2)<4"`)
   or multiplied in via comparisons (`*(atan2(y,x)<(pi/2))`).
6. **Component switch** — `if(M=1, ..., if(M=2, ..., ...))` with `M` a
   `Const`/slider selects among shapes.
7. **Grid-line textures** — `int(i_indx)%(M)>P` style conditions on
   `i_indx`/`j_indx` in `Texture.Colors`.
8. **Fractional literals** — the collection prefers exact-looking
   fractions: `a=2/6`, `T=0.1` → `T=(1/10)`, `c=1/10000`.

## 8. Quirks & gotchas

- **(Historical)** older revisions of the collection carried ~77
  duplicate `"Description "` keys with a trailing space, invisible to
  the loader, which reads only `Description` (no space). These were
  normalized and the file corrected in commit `cdb8c6c` (#180 Code
  cleaning); the current file uses only `"Description"`. If you ever
  diff against old revisions or import third-party files, watch for the
  space-suffixed duplicate and keep the clean key.
- Parallel arrays: if you add a component, **every** parallel array
  (`Component`, `Fxyz`/`Fx..`, all six bounds, `Cnd`...) must grow by
  the same amount; `""` = "none" for `Cnd`.
- `=` inside conditions is *equality*, not assignment; `:=` does not
  exist.
- `Grid` semantics are per-axis resolution ints; for multi-component
  models it can have 1, 2 or per-component entries (observed 2 up to
  338-element arrays — one value per grid line direction, sometimes
  repeated per component).
- `Vect` holds small ints (`"1"`, `"4"`, `"5"`); display/vector option.
- The two `ParIso` entries keep their display name at top level
  (`"Name": ["Pariso_01"]`), not inside the surface block.
- Do not "fix" `DOTSYMBOL` strings in `advancedmodels.js` by hand —
  they are placeholders, not typos.
- The fparser `Eval2` batch interpreter returns: 6 = no error,
  5 = `IF_FUNCT_ERROR`, 7 = `VAR_OVERFLOW`, 1 = division by zero,
  0 = domain errors (2..4); `Vars` are point-major
  (`Vars[e*NbVar+v]`). See `fparser/tests/` for the verification
  harness.

## 9. How the app consumes the file (code map)

| File | Role |
|---|---|
| `mathmodcollection.js` / `advancedmodels.js` | data (embedded Qt resource `:/mathmodcollection.js`) |
| `mathmodcollection_empty.js` | user-file template |
| `json_parser/jiso.{h,cpp}` | parse `Iso3D` block → `jiso` (array fields, all optional) |
| `json_parser/jpar.{h,cpp}` | parse `Param*` block → `jpar` |
| `json_parser/parisodef.{h,cpp}` | `jpariso`, `jcollection` aggregates |
| `ui_modules/parametersoptions.cpp` | `LoadCollectionModels()`: file read (user path or resource), `DOTSYMBOL` replacement, dispatch on block key, texture/pigment list population |
| `ui_modules/drawingoptions.cpp` | model selection into `MathmodRef`, `Import` handling, `ParseIso`/`ParsePar` compilation, `SaveToFile_CurentMathModel` (append path) |
| `pariso/commun.h` | `InternalFunctions[]` import registry; `PI` |
| `fparser/` | expression compiler/interpreter (see `fparser/tests/` harness) |

The loader is *permissive*: missing fields are simply absent; only the
model name is effectively required for the UI list. Expression validity
is enforced at compile/eval time by the fparser, not by the loader.

## 10. Minimal complete examples

**Single-component implicit (Iso3D):**

```json
{ "Iso3D": {
    "Name": ["MySolid"], "Component": ["Sphere"],
    "Fxyz": ["x^2+y^2+z^2-1"],
    "Xmax": ["1"], "Xmin": ["-1"], "Ymax": ["1"], "Ymin": ["-1"],
    "Zmax": ["1"], "Zmin": ["-1"] } }
```

**Parametric with derivative + thickening (Param3D, abridged).**
Note the `Funct` style: every entry is `name=body` with *no argument
list* — bodies are named sub-expressions in the surface variables
`u,v,t`, and call sites like `Fx(u+c,v,t)` bind the arguments
positionally (see §5.6):

```json
{ "Param3D": {
    "Name": ["ThickTorus"], "Component": ["Torus"],
    "Const": ["T=1/10", "c=1/10000", "umin=-2*pi", "umax=2*pi"],
    "Funct": [
      "Fx=(1+1/2*cos(v+t))*cos(u)",
      "Fy=(1+1/2*cos(v+t))*sin(u)",
      "Fz=1/2*sin(v+t)",
      "DFxu=(Fx(u+c,v,t)-Fx(u,v,t))/c", "DFyu=(Fy(u+c,v,t)-Fy(u,v,t))/c",
      "DFzu=(Fz(u+c,v,t)-Fz(u,v,t))/c",
      "DFxv=(Fx(u,v+c,t)-Fx(u,v,t))/c", "DFyv=(Fy(u,v+c,t)-Fy(u,v,t))/c",
      "DFzv=(Fz(u,v+c,t)-Fz(u,v,t))/c",
      "n1=(DFyu*DFzv-DFzu*DFyv)", "n2=(DFzu*DFxv-DFxu*DFzv)",
      "n3=(DFxu*DFyv-DFyu*DFxv)",
      "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)",
      "Gx=Fx(u,v,t)+T*n1(u,v,t)/R(u,v,t)",
      "Gy=Fy(u,v,t)+T*n2(u,v,t)/R(u,v,t)",
      "Gz=Fz(u,v,t)+T*n3(u,v,t)/R(u,v,t)" ],
    "Fx": ["if(v<vmin+1/1000, Gx(u,v,t), Fx(u,v,t))"],
    "Fy": ["if(v<vmin+1/1000, Gy(u,v,t), Fy(u,v,t))"],
    "Fz": ["if(v<vmin+1/1000, Gz(u,v,t), Fz(u,v,t))"],
    "Umin": ["umin"], "Umax": ["umax"],
    "Vmin": ["-pi"], "Vmax": ["pi"] } }
```

**Sliders + texture on an implicit model:**

```json
{ "Iso3D": {
    "Name": ["WobblySphere"],
    "Const": ["A=1"],
    "Import": ["NoiseW"],
    "Fxyz": ["cos(x)+cos(y)+cos(z)-A*NoiseW(x,y,z,(1),(2),(0))"],
    "Xmax": ["2"], "Xmin": ["-2"], "Ymax": ["2"], "Ymin": ["-2"],
    "Zmax": ["2"], "Zmin": ["-2"] },
  "Sliders": { "Name": ["A"], "Min": ["0"], "Max": ["2"],
               "Step": ["1/100"], "Position": ["1"] } }
```
