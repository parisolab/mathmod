# MathMod MCP Servers

Two [MCP](https://modelcontextprotocol.io) servers for AI agents:

1. **`mathmod_mcp.py`** — works *headlessly* on your MathMod model collections
   (`mathmodcollection.js` / `advancedmodels.js`) without running the Qt app. It
   ships a faithful mini-implementation of the fparser expression engine so
   scripts can be validated, evaluated and compared numerically outside the
   application.
2. **`mathmod_ui_mcp.py`** — drives the *running* MathMod UI through the
   loopback HTTP control API embedded in the app (`UiControlServer` in
   `ui_modules/uicontrolserver.h`): read the UI state, load models, move
   sliders, run calculations, capture viewport screenshots.

---

# Script server (`mathmod_mcp.py`)


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

- **Command:** `/pathTo_mcp_server/mcp_server/.venv/bin/python`
- **Args:** `/pathTo_mcp_server/mcp_server/mathmod_mcp.py`

No environment variables are required — the server defaults to the collection files in the
repo root. To point it elsewhere, set:

| Variable | Default |
|---|---|
| `MATHMOD_REPO` | parent directory of this folder (the repo root) |
| `MATHMOD_MAIN_JS` | `$MATHMOD_REPO/mathmodcollection.js` |
| `MATHMOD_ADVANCED_JS` | `$MATHMOD_REPO/advancedmodels.js` |

---

# UI control server (`mathmod_ui_mcp.py`)

A thin wrapper around a small HTTP API that is **embedded in the MathMod app**
itself (`ui_modules/uicontrolserver.h/.cpp`). The app prints on startup:

```
[MathMod UI control] API listening on http://127.0.0.1:61234
```

The API binds to **127.0.0.1 only** (loopback; no authentication — local
processes only). The MCP server forwards each tool call as one HTTP request:

| Endpoint | Purpose |
|---|---|
| `GET /` | health / info |
| `GET /state` | UI snapshot (model, sliders, messages, progress, windows, …) |
| `POST /action` | `{"action":"...","params":{...}}` |

## Tools (32)

### State & models

| Tool | Purpose |
|---|---|
| `ui_state` | Snapshot: current model + available models, script editor text, sliders, message area, `computing_iso/par`, progress, t slider, threads, viewport, components, predefined sets, view-toggle states, grid resolution, scale, undo history, visible windows |
| `ui_select_model(name)` | Load a model from the current collection (like the model combo) |
| `ui_load_file(path)` | Load a `.js` collection file directly (like File > Load json script, no dialog) |

### Script editor & computation

| Tool | Purpose |
|---|---|
| `ui_fill_editor(text)` | Replace the script editor text (does not run) |
| `ui_run` | Run the calculation (Calculate button) |
| `ui_stop` | Stop calculations (Stop button) |

### Sliders, presets & animation

| Tool | Purpose |
|---|---|
| `ui_set_slider(name, value)` | Move a model slider by parameter name |
| `ui_apply_slider_set(name)` | Apply a predefined slider set (name or 1-based number) and redraw |
| `ui_set_t(value)` / `ui_reset_t` | Set / reset the t time slider (4D/morph) |
| `ui_set_threads(value)` | Set worker thread count |
| `ui_set_iso_grid(value)` | Isosurface grid resolution (triggers recomputation) |
| `ui_set_param_grid(value)` | Parametric (u,v) grid resolution (triggers recomputation) |
| `ui_animate` / `ui_morph` | Start rotation / t-morph animation |

### View & display

| Tool | Purpose |
|---|---|
| `ui_set_render_mode(mode)` | `triangles` / `normals` / `fill` / `mesh` |
| `ui_toggle_axes` / `ui_toggle_planes` / `ui_toggle_bounding_box` | Show/hide axes, bounding planes, bounding box |
| `ui_toggle_uv` / `ui_toggle_uv4d` | Show/hide (u,v) parameter coordinates |
| `ui_set_scale(x, y, z)` | Display scale factors (app's Scale tool) |
| `ui_init_matrix` | Reset the 4D rotation matrix + re-run |
| `ui_select_component(name, side?)` | Select a component (name or index; `side` = `iso`/`param` for ParIso models) |
| `ui_toggle_component_visibility` | Show/hide the current component |
| `ui_toggle_object_tree` | Show/hide the current-object tree |

### History

| Tool | Purpose |
|---|---|
| `ui_undo` / `ui_redo` | Walk the model-state history (index/size in `ui_state.undo_history`) |
| `ui_clear_history` | Clear the undo/redo history |

### Output & escape hatch

| Tool | Purpose |
|---|---|
| `ui_screenshot(path?)` | Save the 3D viewport as PNG; returns the file path |
| `ui_open_dialog(which)` | Open `editor` / `select_options` / `add_param` / `about` window |
| `ui_action(action, params_json)` | Generic escape hatch for any of the 30 actions |

## Setup

No extra dependencies — it reuses the same `mcp` virtualenv as the script
server. The app must be **running** (rebuild after adding the control server
source, e.g. via Qt Creator or `qmake && make`).

## Registering in LM Studio Bionic

Add a **second** stdio MCP entry next to `MathMod_MCP`:

- **Command:** `/pathTo_mcp_server/mcp_server/.venv/bin/python`
- **Args:** `/pathTo_mcp_server/mcp_server/mathmod_ui_mcp.py`

No environment variables are required (defaults to `http://127.0.0.1:61234`).
If you change the app's port with `MATHMOD_UI_PORT`, set `MATHMOD_UI_URL`
accordingly here.

## Example agent workflow

1. `ui_state()` → see current model and sliders.
2. Edit/validate the script headlessly with the script server (`upsert_model`).
3. `ui_load_file(...)` or `ui_select_model(...)`.
4. `ui_set_slider(...)` / `ui_apply_slider_set(...)` / `ui_set_iso_grid(...)` etc.
5. `ui_run()` → poll `ui_state()` until `computing_*` is false.
6. `ui_set_render_mode("triangles")` or `ui_set_scale(...)` to inspect the geometry.
7. `ui_screenshot()` → inspect the PNG to verify the rendered surface.
8. `ui_undo()` if the experiment changed something you don't want.

## Caveats

- **Modal dialogs block the API.** The app's error reporting uses modal
  `QMessageBox.exec()`, which stalls the GUI event loop — while such a box is
  open, HTTP requests time out. Close the dialog in the app window, then
  retry. A malformed collection file passed to `ui_load_file` can trigger
  one.
- Actions run on the GUI thread; heavy ones (loading a huge collection,
  grabbing a large framebuffer, `ui_init_matrix` which re-runs the
  calculation) briefly delay UI responsiveness.
- `ui_set_iso_grid` / `ui_set_param_grid` while a computation is running:
  the app's own handler may discard the value until the computation
  finishes — re-issue after `computing_*` is false.
- Component combos can retain entries from the previously loaded model
  type (app behavior); trust `ui_state.components` for the current
  model's component names when calling `ui_select_component`.
- The API has no authentication by design; it only listens on loopback.
  Don't forward port 61234 to other interfaces.

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
