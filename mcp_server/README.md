# MathMod MCP Server

An [MCP](https://modelcontextprotocol.io) (Model Context Protocol) server that lets AI
agents work with your MathMod model collections — `mathmodcollection.js` and
`advancedmodels.js` — without running the Qt app. It ships a faithful mini-implementation
of the fparser expression engine so scripts can be validated, evaluated and compared
numerically outside the application.

## Tools

| Tool | Purpose |
|---|---|
| `list_models` | List models (index, name, type, component count); optional substring filter |
| `get_model` | Fetch one full model entry by display name or 0-based index |
| `search_models` | Substring search over name / component / description |
| `validate_script` | Validate a script (JSON) against the engine rules — see below |
| `validate_model` | Same checks, applied to an existing collection model |
| `evaluate_model` | Sample an Iso3D field F(x,y,z,t) over its box: min/max/mean/std, sign change |
| `compare_models` | Compare two Iso3D models: max/mean \|ΔF\| and sign changes (geometry equivalence check) |
| `estimate_cost` | Per-point cost in "trig units" + per-function breakdown + batch-mode risk note |
| `upsert_model` | Add a model, or replace an existing one with the same name; validates first, writes a rolling `.bak`, supports `dry_run` |
| `reference` | Fetch sections of `docs/mathmod-scripts-reference.md` (e.g. topic `"Vect"`) |

### What `validate_script` checks

- top-level shape: exactly one surface block (`Iso3D` / `Param3D` / `Param4D` / `*_C` / `ParIso`)
- required fields and parallel-array length consistency per component
- expression syntax (full fparser grammar, including `&`, `|`, `%`, chained comparisons)
- unknown identifiers/functions; **Funct ordering** — callees must be defined before callers
  (fparser links only to earlier entries); `eval()` arity = number of surface variables and
  placement inside `if()` (batch-mode requirement)
- **`psh`/`get` vs `Vect`**: using slots without `"Vect"` is an error — the engine allocates
  zero slots and aborts with VAR_OVERFLOW (7); literal slot indices are range-checked against
  `Vect[0]`
- **integer-only slider values** (`Min`/`Max`/`Step`/`Position`) — fractional entries don't work
  in the QScrollBar-based UI; scale inside the expression instead
- `Grid` positive integers, bounding-box sanity (Xmin < Xmax, …)

## Setup

The server is a single Python file with one dependency (`mcp`, pinned `<2`). A ready-to-use
virtualenv already exists:

```
mcp_server/
├── mathmod_mcp.py     # the server (stdio transport)
├── test_client.py     # drives it over raw JSON-RPC — no MCP client needed
└── .venv/             # virtualenv with mcp installed
```

To recreate the venv from scratch:

```sh
cd mcp_server
python3 -m venv .venv
.venv/bin/pip install "mcp<2"
```

Run it standalone (it speaks MCP over stdin/stdout):

```sh
.venv/bin/python mathmod_mcp.py
```

Smoke-test without any MCP client:

```sh
.venv/bin/python test_client.py
```

## Registering in LM Studio Bionic

Add a new **stdio** MCP server in the app's MCP settings with:

- **Command:** `/Users/abderrahmantaha/Documents/GitHub/mathmodAI/mcp_server/.venv/bin/python`
- **Args:** `/Users/abderrahmantaha/Documents/GitHub/mathmodAI/mcp_server/mathmod_mcp.py`

No environment variables are required — the server defaults to the collection files in the
repo root. To point it elsewhere, set:

| Variable | Default |
|---|---|
| `MATHMOD_REPO` | parent directory of this folder (the repo root) |
| `MATHMOD_MAIN_JS` | `$MATHMOD_REPO/mathmodcollection.js` |
| `MATHMOD_ADVANCED_JS` | `$MATHMOD_REPO/advancedmodels.js` |

## Fidelity notes (mini-fparser vs the real engine)

- Same grammar and operator semantics as `fparser.cc`: `^` right-assoc above unary minus,
  `%` = `fmod`, comparisons with the engine's 1e-12 tolerance returning 1/0, `&`/`|` via
  truthiness (|x| ≥ 0.5), lazy `if`.
- The app's own constants: `pi = 314159265/1e8` (not full-precision π) and `ThreadId = 0`.
- `Const` entries resolve in listed order; slider `Position` values override same-named
  consts, matching the engine's add-order.
- Funct redefinition ("chained" idiom) is honored: each entry captures the bindings that
  existed when it was defined (per-entry environment snapshots).
- `eval()` recurses into the defining function; `psh`/`get` use per-evaluation scratch slots
  sized by `Vect`, mirroring scalar-mode semantics. Batch-mode specifics (tile-uniform
  conditions, per-tile slot layout) are not simulated — validation flags the risk instead.
- Models using app-internal imports (`NoiseW`, …) can be validated but not evaluated outside
  the app; the tools report this explicitly.

## Caveats

- `upsert_model` writes a rolling backup `<file>.bak` (overwritten on each write). If you do
  several upserts in one session and want to roll back to the state *before all of them*,
  keep your own snapshot first.
- `evaluate_model` / `compare_models` support Iso3D only; parametric models are reported as
  not evaluable here.
- The collection files are JS-flavored JSON (raw control characters inside strings); the
  server always parses leniently and handles `DOTSYMBOL` in `advancedmodels.js`.
