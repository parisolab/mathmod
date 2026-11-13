#!/usr/bin/env python3
"""
Test client for mathmod_mcp.py — drives the server over stdio JSON-RPC
without needing an MCP client. Usage:

    .venv/bin/python test_client.py            # uses sibling venv if present
    <python> test_client.py                    # uses current interpreter
"""

import json
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
SERVER_PY = os.path.join(HERE, "mathmod_mcp.py")


def server_cmd():
    venv_py = os.path.join(HERE, ".venv", "bin", "python")
    return [venv_py if os.path.exists(venv_py) else sys.executable, SERVER_PY]


class Client:
    def __init__(self):
        self.proc = subprocess.Popen(
            server_cmd(), stdin=subprocess.PIPE, stdout=subprocess.PIPE,
            stderr=subprocess.PIPE, text=True, bufsize=1)
        self.next_id = 0

    def _send(self, obj):
        self.proc.stdin.write(json.dumps(obj) + "\n")
        self.proc.stdin.flush()

    def request(self, method, params=None):
        self.next_id += 1
        msg = {"jsonrpc": "2.0", "id": self.next_id, "method": method}
        if params is not None:
            msg["params"] = params
        self._send(msg)
        while True:
            line = self.proc.stdout.readline()
            if not line:
                err = self.proc.stderr.read()
                raise RuntimeError(f"server died: {err[-2000:]}")
            try:
                resp = json.loads(line)
            except json.JSONDecodeError:
                continue  # log lines etc.
            if resp.get("id") == self.next_id:
                return resp

    def notify(self, method):
        self._send({"jsonrpc": "2.0", "method": method})

    def call_tool(self, name, **kwargs):
        resp = self.request("tools/call", {"name": name, "arguments": kwargs})
        if "error" in resp:
            return f"RPC ERROR: {resp['error']}"
        content = resp["result"].get("content", [])
        text = "".join(c.get("text", "") for c in content)
        if resp["result"].get("isError"):
            return "TOOL ERROR:\n" + text
        return text

    def close(self):
        try:
            self.proc.stdin.close()
            self.proc.wait(timeout=5)
        except Exception:
            self.proc.kill()


def show(title, text, limit=None):
    print(f"\n=== {title} ===")
    if limit and len(text) > limit:
        print(text[:limit] + f"\n... [{len(text)} chars total]")
    else:
        print(text)


def main():
    c = Client()
    try:
        init = c.request("initialize", {
            "protocolVersion": "2025-06-18",
            "capabilities": {},
            "clientInfo": {"name": "mathmod-test-client", "version": "1.0"},
        })
        print("initialize ->", json.dumps(init.get("result", {}).get("serverInfo", {})))
        c.notify("notifications/initialized")

        tools = c.request("tools/list", {})
        names = [t["name"] for t in tools["result"]["tools"]]
        show(f"tools ({len(names)})", ", ".join(names))

        show("list_models(filter=Gyroid_Voronoi)",
             c.call_tool("list_models", filter="Gyroid_Voronoi"))

        show("validate_model(Mandelbulb_eval)",
             c.call_tool("validate_model", name_or_index="Mandelbulb_eval"), 1500)

        show("validate_model(Gyroid_Voronoi_Honeycomb_Psh)",
             c.call_tool("validate_model", name_or_index="Gyroid_Voronoi_Honeycomb_Psh"), 1500)

        show("compare_models(#407 vs #408, n=200)",
             c.call_tool("compare_models", a="Gyroid_Voronoi_Honeycomb",
                         b="Gyroid_Voronoi_Honeycomb_Fast", n_points=200))

        show("compare_models(#407 vs #409, n=200)",
             c.call_tool("compare_models", a="Gyroid_Voronoi_Honeycomb",
                         b="Gyroid_Voronoi_Honeycomb_Psh", n_points=200))

        show("estimate_cost(Gyroid_Voronoi_Honeycomb_Psh)",
             c.call_tool("estimate_cost", name_or_index="Gyroid_Voronoi_Honeycomb_Psh"), 1500)

        show("evaluate_model(Mandelbulb_eval, n=64)",
             c.call_tool("evaluate_model", name_or_index="Mandelbulb_eval", n_points=64))

        bad = json.dumps({"Iso3D": {
            "Name": ["BadModel"], "Component": ["test"],
            "Funct": ["A=psh(0, x)"],
            "Fxyz": ["A(x,y,z,t)"],
            "Xmax": ["1"], "Xmin": ["-1"], "Ymax": ["1"], "Ymin": ["-1"],
            "Zmax": ["1"], "Zmin": ["-1"]}})
        show("validate_script(psh without Vect -> must reject)",
             c.call_tool("validate_script", script_json=bad), 1500)

        bad2 = json.dumps({"Iso3D": {
            "Name": ["BadSliders"], "Component": ["test"],
            "Fxyz": ["x^2+y^2+z^2-1"],
            "Xmax": ["1"], "Xmin": ["-1"], "Ymax": ["1"], "Ymin": ["-1"],
            "Zmax": ["1"], "Zmin": ["-1"]},
            "Sliders": {"Name": ["A"], "Min": ["0"], "Max": ["2/3"],
                        "Step": ["1"], "Position": ["1"]}})
        show("validate_script(fractional slider Max -> must reject)",
             c.call_tool("validate_script", script_json=bad2), 1500)

        sphere = json.dumps({"Iso3D": {
            "Name": ["MCP_Test_Sphere"], "Component": ["Sphere"],
            "Fxyz": ["x^2+y^2+z^2-1"],
            "Xmax": ["1"], "Xmin": ["-1"], "Ymax": ["1"], "Ymin": ["-1"],
            "Zmax": ["1"], "Zmin": ["-1"]}})
        show("upsert_model(dry_run sphere)",
             c.call_tool("upsert_model", script_json=sphere, dry_run=True))

        ref = c.call_tool("reference", topic="Vect")
        show("reference(topic=Vect)", ref[:600])
    finally:
        c.close()


if __name__ == "__main__":
    main()
