#!/usr/bin/env python3
"""
MathMod UI control MCP server.

Wraps the loopback HTTP control API embedded in the *running* MathMod
Qt application (UiControlServer, see ui_modules/uicontrolserver.h).
Unlike mathmod_mcp.py (which works headlessly on the collection .js
files), this server drives the live UI: read its state, load models,
move sliders, run calculations, and grab screenshots of the viewport.

Requirements:
    * The MathMod app must be running (it prints
      "[MathMod UI control] API listening on http://127.0.0.1:<port>"
      on startup).
    * The API binds to 127.0.0.1 only (default port 61234, override
      with MATHMOD_UI_PORT when starting the app).

Transport: stdio JSON-RPC (standard MCP). Run with:
    <venv>/bin/python mathmod_ui_mcp.py

Environment overrides:
    MATHMOD_UI_URL     base URL (default http://127.0.0.1:61234)
    MATHMOD_UI_TIMEOUT request timeout in seconds (default 30)
"""

from __future__ import annotations

import json
import os
import urllib.error
import urllib.request
from typing import Any, Optional

from mcp.server.fastmcp import FastMCP

BASE_URL = os.environ.get("MATHMOD_UI_URL", "http://127.0.0.1:61234").rstrip("/")
TIMEOUT_SECONDS = float(os.environ.get("MATHMOD_UI_TIMEOUT", "30"))

mcp = FastMCP(
    "mathmod-ui",
    instructions=(
        "Tools for controlling the running MathMod desktop app through its "
        "loopback HTTP control API. Read the UI state (ui_state), load "
        "models (ui_select_model/ui_load_file), run/stop calculations "
        "(ui_run/ui_stop), move sliders (ui_set_slider) and apply slider "
        "presets (ui_apply_slider_set), edit the script editor text "
        "(ui_fill_editor), control the view (render mode, axes, planes, "
        "bounding box, uv, component selection, scale, grid resolution), "
        "use undo/redo history, and capture the 3D viewport as a PNG "
        "(ui_screenshot). The app must be running; if it is not, tools "
        "return a connection error."
    ),
)


def _request(method: str, path: str, payload: Optional[dict] = None) -> dict:
    """Perform one HTTP request against the app's control API."""
    data = json.dumps(payload).encode("utf-8") if payload is not None else None
    req = urllib.request.Request(
        BASE_URL + path,
        data=data,
        headers={"Content-Type": "application/json"} if data else {},
        method=method,
    )
    try:
        with urllib.request.urlopen(req, timeout=TIMEOUT_SECONDS) as resp:
            return json.loads(resp.read().decode("utf-8"))
    except urllib.error.HTTPError as e:
        body = e.read().decode("utf-8", "replace")
        try:
            return json.loads(body)
        except json.JSONDecodeError:
            return {"status": "error", "error": f"HTTP {e.code}: {body[:500]}"}
    except urllib.error.URLError as e:
        return {
            "status": "error",
            "error": (
                f"cannot reach MathMod at {BASE_URL} ({e.reason}). Is the "
                "MathMod app running with its UI control API enabled? "
                "(It prints the listening URL on startup.)"
            ),
        }
    except TimeoutError:
        return {
            "status": "error",
            "error": (
                f"request to {BASE_URL} timed out after {TIMEOUT_SECONDS:.0f}s. "
                "The app's GUI thread may be blocked by a modal dialog "
                "(e.g. an error message box) — check the MathMod window."
            ),
        }


def _fmt(obj: Any) -> str:
    return json.dumps(obj, indent=2, ensure_ascii=False)


def _post_action(action: str, params: Optional[dict] = None) -> str:
    return _fmt(_request("POST", "/action", {"action": action, "params": params or {}}))


# ---------------------------------------------------------------------------
# State
# ---------------------------------------------------------------------------


@mcp.tool()
def ui_state() -> str:
    """Snapshot of the MathMod UI: current model, available models, script
    editor text, model sliders (name/value/min/max), parameters list,
    message area, computation flags + progress, t slider, thread count,
    viewport grid/box info, and currently visible windows."""
    return _fmt(_request("GET", "/state"))


# ---------------------------------------------------------------------------
# Model / collection
# ---------------------------------------------------------------------------


@mcp.tool()
def ui_select_model(name: str) -> str:
    """Load a model from the app's current collection into the UI (same as
    picking it in the model combo box). Name matching is exact, then
    case-insensitive. On failure the list of available models is returned."""
    return _post_action("select_model", {"name": name})


@mcp.tool()
def ui_load_file(path: str) -> str:
    """Load a .js collection file into the app directly (no file dialog),
    replacing the current collection — same effect as File > Load json
    script. `path` must be an absolute or working-relative path readable
    by the app."""
    return _post_action("load_file", {"path": path})


# ---------------------------------------------------------------------------
# Script editor / computation
# ---------------------------------------------------------------------------


@mcp.tool()
def ui_fill_editor(text: str) -> str:
    """Replace the main script editor content with the given JSON script
    text. This does NOT run the calculation; call ui_run afterwards."""
    return _post_action("fill_editor", {"text": text})


@mcp.tool()
def ui_run() -> str:
    """Run the calculation for the current script editor content (same as
    the Calculate button). The computation runs on worker threads; poll
    ui_state for progress and completion."""
    return _post_action("run")


@mcp.tool()
def ui_stop() -> str:
    """Stop running calculations (same as the Stop button)."""
    return _post_action("stop")


# ---------------------------------------------------------------------------
# Sliders / animation
# ---------------------------------------------------------------------------


@mcp.tool()
def ui_set_slider(name: str, value: int) -> str:
    """Set one of the current model's sliders by parameter name (e.g.
    'Grid'). Slider values are integers in [min, max] from the model's
    Sliders block. On failure the available slider names are returned."""
    return _post_action("set_slider", {"name": name, "value": value})


@mcp.tool()
def ui_set_t(value: int) -> str:
    """Set the t time slider (4D / morph animation parameter)."""
    return _post_action("set_t", {"value": value})


@mcp.tool()
def ui_set_threads(value: int) -> str:
    """Set the worker thread count slider."""
    return _post_action("set_threads", {"value": value})


@mcp.tool()
def ui_animate() -> str:
    """Start the camera rotation animation (View > Animation_Rotation)."""
    return _post_action("animate")


@mcp.tool()
def ui_morph() -> str:
    """Start the t-parameter morph animation (View > Morph_use_t_parameter)."""
    return _post_action("morph")


@mcp.tool()
def ui_apply_slider_set(name: str) -> str:
    """Apply a predefined slider set of the current model (the app's "
    "'Predefined Sets' combo) by set name or 1-based set number. Moves all "
    "sliders to that set's values and redraws the surface."""
    return _post_action("apply_slider_set", {"name": name})


@mcp.tool()
def ui_reset_t() -> str:
    """Reset the t time slider back to its minimum value."""
    return _post_action("reset_t")


@mcp.tool()
def ui_set_iso_grid(value: int) -> str:
    """Set the isosurface grid resolution (Grid slider, e.g. 64 or 128). "
    "Triggers recomputation of the current isosurface model. Useless for "
    "purely parametric models."""
    return _post_action("set_iso_grid", {"value": value})


@mcp.tool()
def ui_set_param_grid(value: int) -> str:
    """Set the parametric (u,v) grid resolution (Grid(u,v) slider). "
    "Triggers recomputation of the current parametric model."""
    return _post_action("set_param_grid", {"value": value})


# ---------------------------------------------------------------------------
# View / display
# ---------------------------------------------------------------------------


@mcp.tool()
def ui_toggle_axes() -> str:
    """Show/hide the coordinate axes (View > Axe). Returns the new state."""
    return _post_action("toggle_axes")


@mcp.tool()
def ui_toggle_planes() -> str:
    """Show/hide the bounding planes (View > Plan). Returns the new state."""
    return _post_action("toggle_planes")


@mcp.tool()
def ui_toggle_bounding_box() -> str:
    """Show/hide the model's bounding box (View > box). Returns the new state."""
    return _post_action("toggle_bounding_box")


@mcp.tool()
def ui_set_render_mode(mode: str) -> str:
    """Set the OpenGL render mode. `mode` is one of: triangles (wireframe "
    "triangles), normals (surface normals), fill (filled polygons), mesh "
    "(mesh lines)."""
    return _post_action("render_mode", {"mode": mode})


@mcp.tool()
def ui_toggle_uv() -> str:
    """Show/hide the (u,v) parameter coordinates on parametric surfaces."""
    return _post_action("toggle_uv")


@mcp.tool()
def ui_toggle_uv4d() -> str:
    """Show/hide the (u,v) parameter coordinates on 4D surfaces."""
    return _post_action("toggle_uv4d")


@mcp.tool()
def ui_set_scale(x: float, y: float, z: float) -> str:
    """Set the display scale factors for the x, y and z axes (the app's "
    "Scale tool). Values are multipliers (1.0 = no scaling)."""
    return _post_action("set_scale", {"x": x, "y": y, "z": z})


@mcp.tool()
def ui_init_matrix() -> str:
    """Reset the 4D rotation matrix to the identity and re-run the "
    "calculation (the app's 'Init Matrix' button)."""
    return _post_action("init_matrix")


# ---------------------------------------------------------------------------
# Undo / redo history
# ---------------------------------------------------------------------------


@mcp.tool()
def ui_undo() -> str:
    """Restore the previous model state (Edits > Undo). The app keeps a "
    "history of model states; ui_state reports undo_history.index/size."""
    return _post_action("undo")


@mcp.tool()
def ui_redo() -> str:
    """Re-apply the next model state (Edits > Redo)."""
    return _post_action("redo")


@mcp.tool()
def ui_clear_history() -> str:
    """Clear the undo/redo history (Edits > Clear)."""
    return _post_action("clear_history")


# ---------------------------------------------------------------------------
# Components (multi-component models)
# ---------------------------------------------------------------------------


@mcp.tool()
def ui_select_component(name: str, side: str = "") -> str:
    """Select a component of the current multi-component model (the app's "
    "Component combo) by component name or 0-based index. `side` optionally "
    "restricts the search to 'iso' or 'param' (useful for ParIso models). "
    "ui_state lists the available components in 'components'."""
    params: dict = {"name": name}
    if side:
        params["side"] = side
    return _post_action("select_component", params)


@mcp.tool()
def ui_toggle_component_visibility() -> str:
    """Show/hide the currently selected component of a multi-component "
    "model (the app's Show/Hide component button)."""
    return _post_action("toggle_component_visibility")


# ---------------------------------------------------------------------------
# Windows / output
# ---------------------------------------------------------------------------


@mcp.tool()
def ui_screenshot(path: str = "") -> str:
    """Save a PNG of the 3D viewport (OpenGL framebuffer). If `path` is
    empty the app writes to its temp directory
    (e.g. /var/folders/.../T/mathmod_ui_screenshot.png on macOS).
    Returns the saved file path — open it with your image tools to see
    the rendered surface."""
    return _post_action("screenshot", {"path": path} if path else {})


@mcp.tool()
def ui_open_dialog(which: str) -> str:
    """Open a dialog window of the app. `which` is one of:
    editor (standalone script file editor), select_options (scripts
    selection dialog), add_param (add a new slider parameter),
    about (About window)."""
    return _post_action("open_dialog", {"which": which})


@mcp.tool()
def ui_toggle_object_tree() -> str:
    """Show/hide the current-object tree panel (components, fields)."""
    return _post_action("toggle_object_tree")


@mcp.tool()
def ui_action(action: str, params_json: str = "{}") -> str:
    """Generic escape hatch: POST any action to the app's control API.
    Actions: select_model{name}, run{}, stop{}, set_slider{name,value},
    set_t{value}, set_threads{value}, fill_editor{text}, load_file{path},
    screenshot{path?}, open_dialog{which}, toggle_object_tree{},
    animate{}, morph{}, toggle_axes{}, toggle_planes{},
    toggle_bounding_box{}, render_mode{mode}, toggle_uv{}, toggle_uv4d{},
    undo{}, redo{}, clear_history{}, select_component{name,side?},
    toggle_component_visibility{}, apply_slider_set{name},
    set_iso_grid{value}, set_param_grid{value}, reset_t{},
    set_scale{x,y,z}, init_matrix{}. `params_json` is the JSON object for
    'params'. Prefer the dedicated ui_* tools when one exists."""
    try:
        params = json.loads(params_json or "{}")
        if not isinstance(params, dict):
            raise ValueError("params_json must be a JSON object")
    except (json.JSONDecodeError, ValueError) as e:
        return _fmt({"status": "error", "error": f"params_json is not a valid JSON object: {e}"})
    return _post_action(action, params)


if __name__ == "__main__":
    mcp.run()
