#!/usr/bin/env python3
"""
Test client for mathmod_ui_mcp.py — drives the UI-control MCP server over
stdio JSON-RPC without needing an MCP client. The MathMod app must be
running (its control API must answer on http://127.0.0.1:61234 or
MATHMOD_UI_URL). Usage:

    .venv/bin/python test_ui_client.py         # uses sibling venv if present
    <python> test_ui_client.py                 # uses current interpreter
"""

import json
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
SERVER_PY = os.path.join(HERE, "mathmod_ui_mcp.py")


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

    def call_tool(self, tool_name, **kwargs):
        resp = self.request("tools/call", {"name": tool_name, "arguments": kwargs})
        if "error" in resp:
            return f"RPC ERROR: {resp['error']}"
        content = resp["result"].get("content", [])
        return "".join(c.get("text", "") for c in content)

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
            "protocolVersion": "2024-11-05",
            "capabilities": {},
            "clientInfo": {"name": "mathmod-ui-test", "version": "0.1"},
        })
        print("initialize:", "ok" if "result" in init else init.get("error"))

        tools = c.request("tools/list")
        names = [t["name"] for t in tools.get("result", {}).get("tools", [])]
        print(f"tools ({len(names)}):", ", ".join(names))

        # Full round trip against the running app:
        show("ui_state", c.call_tool("ui_state"), limit=1200)
        show("ui_select_model(Apple)", c.call_tool("ui_select_model", name="Apple"))
        show("ui_set_t(7)", c.call_tool("ui_set_t", value=7))
        shot = c.call_tool("ui_screenshot",
                           path=os.path.join(HERE, "ui_test_screenshot.png"))
        show("ui_screenshot", shot)
        show("ui_action(unknown)", c.call_tool("ui_action", action="nope"))
    finally:
        c.close()


if __name__ == "__main__":
    main()
