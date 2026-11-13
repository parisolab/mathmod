#!/usr/bin/env python3
"""
MathMod MCP server.

Exposes the MathMod model collections (mathmodcollection.js / advancedmodels.js)
plus a faithful mini-implementation of the fparser expression engine, so an AI
agent can list, inspect, validate, numerically evaluate, compare and update
MathMod scripts without running the Qt application.

Transport: stdio JSON-RPC (standard MCP). Run with:
    <venv>/bin/python mathmod_mcp.py

Environment overrides:
    MATHMOD_REPO        repo root (default: parent directory of this file)
    MATHMOD_MAIN_JS     path to mathmodcollection.js
    MATHMOD_ADVANCED_JS path to advancedmodels.js
"""

from __future__ import annotations

import json
import math
import os
import re
from typing import Any, Optional

from mcp.server.fastmcp import FastMCP

# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------
REPO_DIR = os.environ.get(
    "MATHMOD_REPO",
    os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
)
COLLECTIONS: dict[str, str] = {
    "main": os.environ.get("MATHMOD_MAIN_JS", os.path.join(REPO_DIR, "mathmodcollection.js")),
    "advanced": os.environ.get("MATHMOD_ADVANCED_JS", os.path.join(REPO_DIR, "advancedmodels.js")),
}
REFERENCE_DOC = os.path.join(REPO_DIR, "docs", "mathmod-scripts-reference.md")

SURFACE_KEYS = ("Iso3D", "Param3D", "Param4D", "Param3D_C", "Param4D_C", "ParIso")
VARS_BY_TYPE: dict[str, list[str]] = {
    "Iso3D": ["x", "y", "z", "t"],
    "Param3D": ["u", "v", "t"],
    "Param4D": ["u", "v", "w", "t"],
    "Param3D_C": ["u", "v", "Z", "t"],
    "Param4D_C": ["u", "v", "w", "Z", "t"],
}

# Core fields required per surface type (array fields, parallel across components)
CORE_FIELDS: dict[str, list[str]] = {
    "Iso3D": ["Fxyz", "Xmax", "Xmin", "Ymax", "Ymin", "Zmax", "Zmin"],
    "Param3D": ["Fx", "Fy", "Fz", "Umin", "Umax", "Vmin", "Vmax"],
    "Param4D": ["Fx", "Fy", "Fz", "Fw", "Umin", "Umax", "Vmin", "Vmax"],
    "Param3D_C": ["Fx", "Fy", "Fz", "Umin", "Umax", "Vmin", "Vmax"],
    "Param4D_C": ["Fx", "Fy", "Fz", "Fw", "Umin", "Umax", "Vmin", "Vmax"],
}

# fparser built-ins (docs §5.2 + fork additions). Arity used for validation.
BUILTINS_1ARG = {
    "abs", "acos", "acosh", "asin", "asinh", "atan", "atanh", "cbrt", "ceil",
    "cos", "cosh", "cot", "coth", "csc", "csch", "exp", "exp2", "floor", "int",
    "log", "log10", "log2", "round", "sec", "sech", "sin", "sign", "sinh",
    "sqrt", "tan", "tanh", "trunc", "erf",
}
BUILTINS_2ARG = {"atan2", "hypot", "max", "min", "pow", "psh", "get"}
COMPLEX_ONLY = {"real", "imag", "conj", "arg", "polar"}  # *_C parsers only

# App-internal importable functions (pariso/commun.h InternalFunctions[])
IMPORTABLE = {
    "NoiseW": 6, "MarbleP": 4, "LegendreA": 3, "mandelbulb": 4,
    "MandelFractal": 3, "LaguerreA": 3, "JuliaFractal": 5, "CmpId": 1,
    "fhelix1": 10, "f_hex_y": 4, "fmesh": 8, "p_skeletal_int": 3, "NoiseP": 6,
}

# The app's own pi (pariso/commun.h:27) — NOT full-precision math.pi.
APP_PI = 314159265 / 1e8


def _safe(fn):
    def w(*a):
        try:
            r = fn(*a)
            if isinstance(r, complex):
                return float("nan")
            return float(r)
        except (ValueError, OverflowError, ZeroDivisionError, TypeError):
            return float("nan")

    return w


def _round_half_away(x: float) -> float:
    # std::round semantics (fparser int()/round())
    if math.isnan(x):
        return x
    return math.copysign(math.floor(abs(x) + 0.5), x)


BUILTIN_IMPL: dict[str, Any] = {
    "abs": abs, "acos": _safe(math.acos), "acosh": _safe(math.acosh),
    "asin": _safe(math.asin), "asinh": math.asinh, "atan": math.atan,
    "atanh": _safe(math.atanh),
    "cbrt": lambda x: math.copysign(abs(x) ** (1.0 / 3.0), x),
    "ceil": math.ceil, "cos": math.cos, "cosh": math.cosh,
    "cot": _safe(lambda x: 1.0 / math.tan(x)),
    "coth": _safe(lambda x: 1.0 / math.tanh(x)),
    "csc": _safe(lambda x: 1.0 / math.sin(x)),
    "csch": _safe(lambda x: 1.0 / math.sinh(x)),
    "exp": _safe(math.exp), "exp2": lambda x: 2.0 ** x,
    "floor": math.floor, "int": _round_half_away,
    "log": _safe(math.log), "log10": _safe(math.log10), "log2": _safe(math.log2),
    "round": _round_half_away,
    "sec": _safe(lambda x: 1.0 / math.cos(x)),
    "sech": _safe(lambda x: 1.0 / math.cosh(x)),
    "sin": math.sin,
    "sign": lambda x: 0.0 if not (x > 0 or x < 0) else (1.0 if x > 0 else -1.0),
    "sinh": math.sinh, "sqrt": _safe(math.sqrt),
    "tan": math.tan, "tanh": math.tanh, "trunc": math.trunc, "erf": math.erf,
    "atan2": math.atan2, "hypot": math.hypot, "max": max, "min": min,
}


def _pow(a: float, b: float) -> float:
    try:
        r = a ** b
        if isinstance(r, complex):
            return float("nan")
        return float(r)
    except (ValueError, OverflowError, ZeroDivisionError):
        return float("nan")


BUILTIN_IMPL["pow"] = _pow

# ---------------------------------------------------------------------------
# Mini-fparser: tokenizer + parser (grammar mirrors fparser.cc Compile* chain:
#   expr := or ; or := and ('|' and)* ; and := cmp ('&' cmp)* ;
#   cmp  := add (('='|'!='|'<='|'>='|'<'|'>') add)* ;
#   add  := mul (('+'|'-') mul)* ; mul := unary (('*'|'/'|'%') unary)* ;
#   unary:= ('-'|'+') unary | pow ; pow := primary ('^' unary)?
# ---------------------------------------------------------------------------


def tokenize(s: str):
    toks = []
    i, n = 0, len(s)
    while i < n:
        c = s[i]
        if c.isspace():
            i += 1
        elif c in "+-*/^%(),&|":
            toks.append((c, c))
            i += 1
        elif c == "=":
            toks.append(("eq", "=")); i += 1
        elif c == "!":
            if i + 1 < n and s[i + 1] == "=":
                toks.append(("ne", "!=")); i += 2
            else:
                raise ValueError("syntax error: standalone '!' (fparser requires '!=')")
        elif c == "<" and i + 1 < n and s[i + 1] == "=":
            toks.append(("le", "<=")); i += 2
        elif c == ">" and i + 1 < n and s[i + 1] == "=":
            toks.append(("ge", ">=")); i += 2
        elif c == "<":
            toks.append(("lt", "<")); i += 1
        elif c == ">":
            toks.append(("gt", ">")); i += 1
        elif c.isdigit() or (c == "." and i + 1 < n and s[i + 1].isdigit()):
            j = i
            while j < n and (s[j].isdigit() or s[j] == "."):
                j += 1
            if j < n and s[j] in "eE":
                k = j + 1
                if k < n and s[k] in "+-":
                    k += 1
                if k < n and s[k].isdigit():
                    while k < n and s[k].isdigit():
                        k += 1
                    j = k
            toks.append(("num", float(s[i:j]))); i = j
        elif c.isalpha() or c == "_":
            j = i
            while j < n and (s[j].isalnum() or s[j] == "_"):
                j += 1
            toks.append(("id", s[i:j])); i = j
        else:
            raise ValueError(f"bad character {c!r} at position {i}")
    return toks


class _Parser:
    def __init__(self, t):
        self.t = t
        self.i = 0

    def pk(self):
        return self.t[self.i][0] if self.i < len(self.t) else None

    def nx(self):
        x = self.t[self.i]; self.i += 1
        return x

    def expect(self, k):
        k2, v = self.nx()
        if k2 != k:
            raise ValueError(f"expected {k!r} got {k2!r}")
        return v

    def expr(self):
        return self.or_()

    def or_(self):
        node = self.and_()
        while self.pk() == "|":
            self.nx(); r = self.and_(); node = ("bin", "|", node, r)
        return node

    def and_(self):
        node = self.cmp()
        while self.pk() == "&":
            self.nx(); r = self.cmp(); node = ("bin", "&", node, r)
        return node

    def cmp(self):
        node = self.addition()
        while self.pk() in ("eq", "ne", "lt", "le", "gt", "ge"):
            op = self.nx()[0]; r = self.addition(); node = ("cmp", op, node, r)
        return node

    def addition(self):
        node = self.term()
        while self.pk() in ("+", "-"):
            op = self.nx()[1]; r = self.term(); node = ("bin", op, node, r)
        return node

    def term(self):
        node = self.unary()
        while self.pk() in ("*", "/", "%"):
            op = self.nx()[1]; r = self.unary(); node = ("bin", op, node, r)
        return node

    def unary(self):
        if self.pk() == "-":
            self.nx(); return ("neg", self.unary())
        if self.pk() == "+":
            self.nx(); return self.unary()
        return self.pow()

    def pow(self):
        b = self.primary()
        if self.pk() == "^":
            self.nx(); e = self.unary(); return ("bin", "^", b, e)
        return b

    def primary(self):
        k, v = self.nx()
        if k == "num":
            return ("num", v)
        if k == "id":
            if self.pk() == "(":
                self.nx(); args = [self.expr()]
                while self.pk() == ",":
                    self.nx(); args.append(self.expr())
                self.expect(")")
                return ("call", v, args)
            return ("var", v)
        if k == "(":
            node = self.expr(); self.expect(")")
            return node
        raise ValueError(f"unexpected token {k!r}({v!r})")


def parse_expr(s: str):
    p = _Parser(tokenize(s))
    node = p.expr()
    if p.i != len(p.t):
        raise ValueError("trailing tokens after expression end")
    return node


# ---------------------------------------------------------------------------
# AST walking helpers
# ---------------------------------------------------------------------------

def ast_ids(node, out: set[str]):
    """All identifier names (variables and called functions) in the AST."""
    k = node[0]
    if k == "var":
        out.add(node[1])
    elif k == "call":
        out.add(node[1])
        for a in node[2]:
            ast_ids(a, out)
    elif k == "neg":
        ast_ids(node[1], out)
    elif k in ("bin", "cmp"):
        ast_ids(node[2], out); ast_ids(node[3], out)


def walk(node, fn):
    """Depth-first call; fn(node) then children."""
    fn(node)
    if node[0] == "call":
        for a in node[2]:
            walk(a, fn)
    elif node[0] == "neg":
        walk(node[1], fn)
    elif node[0] in ("bin", "cmp"):
        walk(node[2], fn); walk(node[3], fn)


def psh_get_slots(node):
    """Yield (slot_arg_ast, is_psh) for every psh/get call."""
    res = []

    def f(n):
        if n[0] == "call" and n[1] in ("psh", "get"):
            res.append((n[2][0], n[1]))

    walk(node, f)
    return res


def count_ifs(node):
    c = [0]

    def f(n):
        if n[0] == "call" and n[1] == "if":
            c[0] += 1

    walk(node, f)
    return c[0]


# ---------------------------------------------------------------------------
# Code generation (Python source mirroring fparser semantics)
# ---------------------------------------------------------------------------

def _emit(node, env_names: set[str], self_name: str | None):
    k = node[0]
    if k == "num":
        return repr(node[1])
    if k == "var":
        return node[1]
    if k == "neg":
        return f"(-{_emit(node[1], env_names, self_name)})"
    if k in ("bin", "cmp"):
        op = node[1]
        l = _emit(node[2], env_names, self_name)
        r = _emit(node[3], env_names, self_name)
        if k == "cmp":
            m = {"eq": "_eq", "ne": "_ne", "lt": "_lt", "le": "_le",
                 "gt": "_gt", "ge": "_ge"}[op]
            return f"{m}({l},{r})"
        if op == "^":
            return f"_pow({l},{r})"
        if op == "%":
            return f"_fmod({l},{r})"
        if op == "&":
            return f"_and({l},{r})"
        if op == "|":
            return f"_or({l},{r})"
        return f"({l} {op} {r})"
    if k == "call":
        name, args = node[1], node[2]
        a = [_emit(x, env_names, self_name) for x in args]
        if name == "if":
            return f"({a[1]} if _truthy({a[0]}) else {a[2]})"
        if name == "psh":
            return f"_psh({a[0]},{a[1]})"
        if name == "get":
            return f"_get({a[0]})"
        if name == "eval":
            if self_name is None:
                raise ValueError("eval() outside a user function")
            return f"_FUNCTS['{self_name}']({','.join(a)})"
        if name in env_names:
            return f"_env['{name}']({','.join(a)})"
        if name not in BUILTIN_IMPL:
            raise ValueError(f"unknown function {name!r}")
        return _builtin_call(name, a)
    raise ValueError("bad AST node")


def _builtin_call(name: str, args: list[str]) -> str:
    # Route through a dispatch table so lambdas get stable call sites.
    return f"_BI['{name}']({','.join(args)})"


# ---------------------------------------------------------------------------
# Model compilation + evaluation
# ---------------------------------------------------------------------------

HELPERS_TEMPLATE = '''
import math as _math
REGBOX = {{"r": [0.0] * {nslots}}}
_FUNCTS = {{}}
def _psh(i, v):
    ii = int(round(float(i)))
    if ii < 0 or ii >= {nslots}: raise ValueError("VAR_OVERFLOW: slot index out of range")
    REGBOX["r"][ii] = float(v); return 1.0
def _get(i):
    ii = int(round(float(i)))
    if ii < 0 or ii >= {nslots}: raise ValueError("VAR_OVERFLOW: slot index out of range")
    return REGBOX["r"][ii]
def _eq(a, b): return 1.0 if abs(a - b) <= 1e-12 else 0.0
def _ne(a, b): return 1.0 - _eq(a, b)
def _lt(a, b): return 1.0 if a < b - 1e-12 else 0.0
def _le(a, b): return 1.0 if a <= b + 1e-12 else 0.0
def _gt(a, b): return 1.0 if b < a - 1e-12 else 0.0
def _ge(a, b): return 1.0 if b <= a + 1e-12 else 0.0
def _truthy(c): return abs(c) >= 0.5
def _and(a, b): return 1.0 if (abs(a) >= 0.5 and abs(b) >= 0.5) else 0.0
def _or(a, b): return 1.0 if (abs(a) >= 0.5 or abs(b) >= 0.5) else 0.0
def _fmod(a, b):
    try: return float(_math.fmod(a, b))
    except ZeroDivisionError: raise ValueError("division by zero in %%")
'''


class MathModel:
    """Compiles one model entry (surface block + Sliders) into Python code."""

    def __init__(self, model_dict: dict, source_name: str = "<script>"):
        self.source_name = source_name
        surface_keys = [k for k in model_dict if k in SURFACE_KEYS]
        if len(surface_keys) != 1:
            raise ValueError("model must contain exactly one surface block")
        self.surface_type = surface_keys[0]
        self.block = model_dict[self.surface_type]
        self.sliders = model_dict.get("Sliders", {})

        if self.surface_type == "ParIso":
            raise ValueError("ParIso composite models are not evaluable here")
        self.vars = VARS_BY_TYPE[self.surface_type]
        varlist = ",".join(self.vars)

        consts: list[str] = list(self.block.get("Const", []))
        functs: list[str] = list(self.block.get("Funct", []))
        imports: set[str] = set(self.block.get("Import", []))
        vect = self.block.get("Vect")
        nslots = int(float(vect[0])) if isinstance(vect, list) and vect else 0

        # ---- symbol environment -------------------------------------------
        slider_names = [str(s).strip() for s in self.sliders.get("Name", [])]
        pos_list = list(self.sliders.get("Position", ["0"] * len(slider_names)))

        lines: list[str] = []
        known: set[str] = set(self.vars) | {"pi", "ThreadId", "if", "eval"} \
            | set(slider_names) | BUILTINS_1ARG | BUILTINS_2ARG | imports
        deferred_sliders: list[tuple[str, str]] = []

        # Slider positions that are plain values go in first (so consts may
        # reference them); ones referencing consts are emitted after consts.
        for nm, pv in zip(slider_names, pos_list):
            try:
                val = eval_const_value(str(pv), set())
                lines.append(f"{nm} = {val!r}")
            except Exception:
                deferred_sliders.append((nm, str(pv)))

        for line in consts:
            name, body = split_name_body(line)
            ast = parse_expr(body)
            self._resolve(ast, known - {name}, f"Const {name!r}")
            lines.append(f"{name} = {_emit(ast, set(), None)}")
            known.add(name)  # defined from this point on

        for nm, pv in deferred_sliders:
            ast = parse_expr(pv)
            self._resolve(ast, known - {nm}, f"Sliders Position {nm!r}")
            lines.append(f"{nm} = {_emit(ast, set(), None)}")  # overrides same-named const

        # ---- user functions with per-entry env snapshots ------------------
        funct_env: dict[str, str] = {}  # name -> python def name
        for line in functs:
            name, body = split_name_body(line)
            pyname = f"_f_{re.sub(r'\\W', '_', name)}"
            ast = parse_expr(body)
            self._resolve(ast, known | set(funct_env), f"Funct {name!r}")
            env_names = set(funct_env)
            snap = ", ".join(f"'{n}': {funct_env[n]}" for n in sorted(env_names))
            lines.append(f"_env_{pyname[2:]} = {{{snap}}}")
            lines.append(
                f"def {pyname}({varlist}, _env=_env_{pyname[2:]}):\n"
                f"    return {_emit(ast, env_names, name)}"
            )
            funct_env[name] = pyname
            known.add(name)

        # ---- main field ----------------------------------------------------
        self.field_asts: dict[str, Any] = {}
        for fname in CORE_FIELDS[self.surface_type]:
            arr = self.block.get(fname)
            if not isinstance(arr, list):
                continue
            exprs = [e for e in arr if isinstance(e, str) and e.strip() != ""]
            for idx, ex in enumerate(exprs):
                ast = parse_expr(ex)
                self._resolve(ast, known | set(funct_env), f"{fname}[{idx}]")
                self.field_asts.setdefault(fname, []).append((idx, ast))

        # ---- compile -------------------------------------------------------
        src = HELPERS_TEMPLATE.format(nslots=nslots) + "\n"
        src += "\n".join(lines) + "\n"

        ns: dict[str, Any] = {"_BI": BUILTIN_IMPL, "pi": APP_PI, "ThreadId": 0.0}
        exec(compile(src, f"mathmod:{self.source_name}", "exec"), ns)
        self.ns = ns
        self.nslots = nslots
        self.imports_used = imports & self._all_ids()

        # final env for field expressions (latest binding of every funct name)
        ns["_env"] = {n: ns[p] for n, p in funct_env.items()}
        self.fxyz_code = None
        if "Fxyz" in self.field_asts:
            ast0 = self.field_asts["Fxyz"][0][1]
            self.fxyz_code = compile(
                _emit(ast0, set(funct_env), None), f"mathmod:{self.source_name}:Fxyz", "eval")
        self._bounds_cache: dict[str, Any] = {}

    # -- helpers ------------------------------------------------------------
    def _resolve(self, ast, allowed: set[str], where: str):
        ids: set[str] = set()
        ast_ids(ast, ids)
        unknown = ids - allowed
        if unknown:
            raise ValueError(f"{where}: unknown identifier(s) {sorted(unknown)}")

    def _all_ids(self) -> set[str]:
        out: set[str] = set()
        for v in self.field_asts.values():
            for _, ast in v:
                ast_ids(ast, out)
        return out

    # -- evaluation (Iso3D only) --------------------------------------------
    def F(self, x: float, y: float, z: float, t: float = 0.0) -> float:
        if self.surface_type != "Iso3D":
            raise ValueError("evaluate_model supports Iso3D models only")
        if self.fxyz_code is None:
            raise ValueError("model has no Fxyz field")
        ns = self.ns
        ns["REGBOX"]["r"] = [0.0] * self.nslots
        locals_ = {v: 0.0 for v in self.vars}
        locals_["t"] = t
        return float(eval(self.fxyz_code, ns, locals_))

    def bounds(self, t: float = 0.0) -> tuple[float, float, float, float, float, float]:
        """Evaluate the bounding box (component 0) at time t."""
        ns = self.ns
        vals = {}
        for key in ("Xmin", "Xmax", "Ymin", "Ymax", "Zmin", "Zmax"):
            arr = self.block.get(key, [])
            if not arr:
                raise ValueError(f"missing {key}")
            code = self._bounds_cache.get(key)
            if code is None:
                ast = parse_expr(str(arr[0]))
                # bound expressions may reference functs (rare); use final env
                code = compile(_emit(ast, set(self.ns.get("_env", {})), None),
                               f"<{key}>", "eval")
                self._bounds_cache[key] = code
            locals_ = {v: 0.0 for v in self.vars}
            locals_["t"] = t
            vals[key] = float(eval(code, ns, locals_))
        return (vals["Xmin"], vals["Xmax"], vals["Ymin"], vals["Ymax"],
                vals["Zmin"], vals["Zmax"])


def split_name_body(line: str) -> tuple[str, str]:
    """fparser splits Funct/Const entries at the FIRST '='."""
    i = line.find("=")
    if i < 0:
        raise ValueError(f"missing '=' in entry {line[:60]!r}")
    return line[:i].strip(), line[i + 1:].strip()


def eval_const_value(expr: str, allowed_extra: set[str]) -> float:
    """Evaluate a slider Position / simple constant expression standalone."""
    ast = parse_expr(expr)
    ids: set[str] = set()
    ast_ids(ast, ids)
    base = {"pi", "ThreadId"} | BUILTINS_1ARG | BUILTINS_2ARG | allowed_extra
    unknown = ids - base
    if unknown:
        raise ValueError(f"cannot evaluate {expr!r}: unknown {sorted(unknown)}")
    ns: dict[str, Any] = {"_BI": BUILTIN_IMPL, "pi": APP_PI, "ThreadId": 0.0}
    code = compile(_emit(ast, set(), None), "<const>", "eval")
    return float(eval(code, ns))


# ---------------------------------------------------------------------------
# Validation
# ---------------------------------------------------------------------------

def validate_model_dict(md: dict) -> list[dict]:
    """Validate a model entry against the engine rules. Returns issue dicts."""
    issues: list[dict] = []

    def err(where, msg):
        issues.append({"level": "error", "where": where, "message": msg})

    def warn(where, msg):
        issues.append({"level": "warning", "where": where, "message": msg})

    if not isinstance(md, dict):
        return [{"level": "error", "where": "<top>", "message": "model must be a JSON object"}]

    surface_keys = [k for k in md if k in SURFACE_KEYS]
    unknown_blocks = [k for k in md if k not in SURFACE_KEYS and k not in ("Sliders", "Texture", "Pigment")]
    for k in unknown_blocks:
        warn("<top>", f"unknown block {k!r} (ignored by the loader)")
    if len(surface_keys) != 1:
        err("<top>", f"expected exactly one surface block, found {surface_keys}")
        return issues

    stype = surface_keys[0]
    block = md[stype]

    # ---- ParIso composite --------------------------------------------------
    if stype == "ParIso":
        if not isinstance(block, list) or not block:
            err("ParIso", "must be a non-empty array of surface blocks")
            return issues
        for i, sub in enumerate(block):
            if not isinstance(sub, dict):
                err(f"ParIso[{i}]", "each element must be a surface-block object")
                continue
            sub_issues = validate_model_dict(sub)
            for si in sub_issues:
                issues.append({**si, "where": f"ParIso[{i}].{si['where']}"})
        return issues

    _validate_surface_block(stype, block, md, issues, 0)
    return issues


def _validate_surface_block(stype: str, block: Any, md: dict, issues: list[dict], idx: int):
    def err(where, msg):
        issues.append({"level": "error", "where": where, "message": msg})

    def warn(where, msg):
        issues.append({"level": "warning", "where": where, "message": msg})

    if not isinstance(block, dict):
        err(stype, "surface block must be a JSON object")
        return

    vars_ = VARS_BY_TYPE[stype]
    core = CORE_FIELDS[stype]

    # required fields + parallel lengths
    lens: dict[str, int] = {}
    for f in core:
        arr = block.get(f)
        if not isinstance(arr, list) or len(arr) == 0:
            err(stype, f"missing/empty required field {f!r}")
            continue
        lens[f] = len(arr)
    parallel = [l for l in lens.values()]
    if parallel and len(set(parallel)) > 1:
        err(stype, f"parallel arrays have inconsistent lengths: "
                   + ", ".join(f"{f}={lens[f]}" for f in sorted(lens)))

    name_arr = block.get("Name") or md.get("Name")
    if not (isinstance(name_arr, list) and name_arr):
        warn(stype, "no Name field — the app needs a display name")

    # sliders: integer-only values
    sliders = md.get("Sliders", {})
    slider_names = [str(s).strip() for s in sliders.get("Name", [])]
    for key in ("Min", "Max", "Step", "Position"):
        arr = sliders.get(key, [])
        for i, v in enumerate(arr):
            try:
                val = eval_const_value(str(v), set())
            except Exception as e:
                err(f"Sliders.{key}[{i}]", f"unparseable value {v!r}: {e}")
                continue
            if not math.isfinite(val) or abs(val - round(val)) > 1e-9:
                err(f"Sliders.{key}[{i}]",
                    f"value {v!r} is not an integer — UI sliders are QScrollBar-based; "
                    f"use integers and scale inside the expression (e.g. Cx/20)")
    if slider_names:
        for key in ("Min", "Max", "Step", "Position"):
            arr = sliders.get(key, [])
            if len(arr) != len(slider_names):
                err(f"Sliders.{key}", f"length {len(arr)} != number of sliders {len(slider_names)}")

    # Vect / psh-get / eval checks (AST level)
    vect = block.get("Vect")
    nslots: Optional[int] = None
    if isinstance(vect, list) and vect:
        try:
            nslots = int(float(str(vect[0])))
            if nslots < 1:
                err(stype, f"Vect value {vect[0]!r} must be a positive integer")
                nslots = None
        except ValueError:
            err(stype, f"Vect entry {vect[0]!r} is not an integer")

    consts = [str(c) for c in block.get("Const", [])]
    functs = [str(f) for f in block.get("Funct", [])]
    imports = set(block.get("Import", []))
    bad_imports = imports - set(IMPORTABLE)
    if bad_imports:
        err(stype, f"unknown Import name(s): {sorted(bad_imports)} "
                   f"(registry: {sorted(IMPORTABLE)})")

    known_extra = BUILTINS_1ARG | BUILTINS_2ARG \
        | ({COMPLEX_ONLY} if stype.endswith("_C") else set()) \
        | {"pi", "ThreadId", "if", "eval"} | imports | set(slider_names)

    # Consts: parse + ordered resolution
    const_known = set(vars_) | known_extra
    for line in consts:
        try:
            name, body = split_name_body(line)
        except ValueError as e:
            err("Const", str(e)); continue
        ast = _try_parse(body, "Const", issues)
        if ast is None:
            continue
        ids: set[str] = set(); ast_ids(ast, ids)
        unknown = ids - (const_known | {name})
        if unknown:
            err(f"Const {name!r}", f"unknown identifier(s): {sorted(unknown)}")
        const_known.add(name)

    # Functs: parse + j<i linking rule + substring-collision warnings
    funct_names: list[str] = []
    for line in functs:
        try:
            name, body = split_name_body(line)
        except ValueError as e:
            err("Funct", str(e)); continue
        ast = _try_parse(body, "Funct", issues)
        if ast is None:
            continue
        ids: set[str] = set(); ast_ids(ast, ids)
        unknown = ids - (const_known | set(funct_names))
        if unknown:
            err(f"Funct {name!r}",
                f"unknown identifier(s): {sorted(unknown)} — callees must be defined "
                f"BEFORE callers (fparser links only to earlier entries)")
        # eval arity + placement
        ev_ok = [True]

        def _ev(n, under_if):
            if n[0] == "call":
                if n[1] == "if":
                    for a in n[2]:
                        _ev(a, True)
                    return
                if n[1] == "eval":
                    if len(n[2]) != len(vars_):
                        ev_ok[0] = False
                        err(f"Funct {name!r}",
                            f"eval() takes exactly {len(vars_)} arguments ({','.join(vars_)})")
                    if not under_if:
                        warn(f"Funct {name!r}",
                             "eval() outside if(): batch mode aborts (error 5) unless every "
                             "point recurses to the same depth — wrap in if() as usual")
            elif n[0] == "call" and n[1] != "if":
                for a in n[2]:
                    _ev(a, under_if)
            elif n[0] == "neg":
                _ev(n[1], under_if)
            elif n[0] in ("bin", "cmp"):
                _ev(n[2], under_if); _ev(n[3], under_if)

        _ev(ast, False)
        # psh/get slot bounds
        for slot_ast, kind in psh_get_slots(ast):
            if slot_ast[0] == "num":
                si = int(round(slot_ast[1]))
                if nslots is None:
                    err(f"Funct {name!r}",
                        f"{kind}() used but no Vect declared — the engine allocates 0 slots "
                        f"and aborts with VAR_OVERFLOW (7)")
                elif si < 0 or si >= nslots:
                    err(f"Funct {name!r}",
                        f"{kind}({si}) out of range: Vect declares {nslots} slot(s) (0..{nslots - 1})")
            else:
                warn(f"Funct {name!r}",
                     f"dynamic slot index in {kind}() — ensure the runtime value stays in 0..{(nslots or 0) - 1}")
        funct_names.append(name)

    # core fields: parse + resolution against everything
    field_known = const_known | set(funct_names)
    for f in core:
        arr = block.get(f, [])
        if not isinstance(arr, list):
            continue
        for i, ex in enumerate(arr):
            if not isinstance(ex, str) or ex.strip() == "":
                continue
            ast = _try_parse(ex, f"{f}[{i}]", issues)
            if ast is None:
                continue
            ids: set[str] = set(); ast_ids(ast, ids)
            unknown = ids - field_known
            if unknown:
                err(f"{f}[{i}]", f"unknown identifier(s): {sorted(unknown)}")

    # Grid sanity
    grid = block.get("Grid", [])
    if isinstance(grid, list):
        for i, g in enumerate(grid):
            try:
                val = eval_const_value(str(g), set())
                if not (math.isfinite(val) and abs(val - round(val)) < 1e-9 and val > 0):
                    err(f"Grid[{i}]", f"value {g!r} should be a positive integer")
            except Exception:
                err(f"Grid[{i}]", f"unparseable value {g!r}")

    # bounding box sanity (numeric, component 0)
    try:
        vals = {}
        for key in ("Xmin", "Xmax", "Ymin", "Ymax", "Zmin", "Zmax"):
            arr = block.get(key, [])
            if isinstance(arr, list) and arr:
                ast = parse_expr(str(arr[0]))
                ids: set[str] = set(); ast_ids(ast, ids)
                if not (ids <= field_known):
                    continue  # already reported as unknown identifier
                vals[key] = eval_const_value(str(arr[0]), field_known - set(vars_))
        for a, b in (("Xmin", "Xmax"), ("Ymin", "Ymax"), ("Zmin", "Zmax")):
            if a in vals and b in vals and vals[a] >= vals[b]:
                err(stype, f"{a} ({vals[a]}) >= {b} ({vals[b]}) — empty/degenerate box")
    except Exception:
        pass  # bounds referencing t or unresolved names are checked above


def _try_parse(expr: str, where: str, issues: list[dict]):
    try:
        return parse_expr(expr)
    except ValueError as e:
        issues.append({"level": "error", "where": where,
                       "message": f"parse error in {expr[:60]!r}: {e}"})
        return None


# ---------------------------------------------------------------------------
# Cost model (trig units/point; same weights used for #407/#408/#409 analysis)
# ---------------------------------------------------------------------------

W_TRIG1 = BUILTINS_1ARG - {"abs", "floor", "int", "ceil", "trunc", "round", "sign"}


def _cost(node, bodies: dict[str, Any], lazy: bool):
    k = node[0]
    if k in ("num", "var"):
        return 0.0
    if k == "neg":
        return _cost(node[1], bodies, lazy) + 0.1
    if k in ("bin", "cmp"):
        w = 0.5 if (k == "bin" and node[1] == "^") else 0.1
        return _cost(node[2], bodies, lazy) + _cost(node[3], bodies, lazy) + w
    if k == "call":
        name, args = node[1], node[2]
        base = sum(_cost(a, bodies, lazy) for a in args)
        if name == "if":
            c = _cost(args[0], bodies, lazy)
            a = _cost(args[1], bodies, lazy)
            b = _cost(args[2], bodies, lazy)
            return c + 0.1 + (max(a, b) if lazy else (a + b))
        if name in ("psh", "get"):
            return base + 0.1
        if name in W_TRIG1:
            return base + 1.0
        if name in {"sqrt", "hypot"}:
            return base + 0.5
        if name in {"floor", "int", "ceil", "trunc", "min", "max", "abs", "%"}:
            return base + 0.2
        if name in bodies:
            return base + _cost(bodies[name], bodies, lazy)
        return base


def estimate_cost_dict(md: dict) -> dict:
    issues = validate_model_dict(md)
    errors = [i for i in issues if i["level"] == "error"]
    if errors:
        return {"status": "error", "errors": errors}
    stype = next(k for k in md if k in SURFACE_KEYS)
    block = md[stype]
    bodies: dict[str, Any] = {}
    for line in block.get("Funct", []):
        name, body = split_name_body(str(line))
        try:
            bodies[name] = parse_expr(body)
        except ValueError:
            pass
    core_field = "Fxyz" if stype == "Iso3D" else "Fx"
    total = 0.0
    for f in CORE_FIELDS[stype]:
        arr = block.get(f, [])
        if isinstance(arr, list):
            for ex in arr:
                if isinstance(ex, str) and ex.strip():
                    try:
                        total += _cost(parse_expr(ex), bodies, True)
                    except ValueError:
                        pass
    n_ifs = 0
    for ast in bodies.values():
        n_ifs += count_ifs(ast)
    return {
        "status": "ok",
        "model": (block.get("Name") or ["?"])[0],
        "cost_units_per_point": round(total, 1),
        "per_function": {n: round(_cost(a, bodies, True), 1) for n, a in bodies.items()},
        "if_count": n_ifs,
        "batch_note": ("contains if(): conditions that vary within a batch tile force the "
                       "scalar fallback (error 5); uniform conditions stay batched"
                       if n_ifs else "no if() — stays on the fast batched/vectorized path"),
    }


# ---------------------------------------------------------------------------
# Collection I/O
# ---------------------------------------------------------------------------

def load_collection(name: str) -> tuple[str, dict]:
    path = COLLECTIONS.get(name)
    if not path or not os.path.exists(path):
        raise ValueError(f"collection {name!r} not found at {path}")
    with open(path, encoding="utf-8") as fh:
        text = fh.read()
    data = json.loads(text.replace("DOTSYMBOL", "."), strict=False)
    return path, data


def model_name_of(entry: dict) -> Optional[str]:
    for k in SURFACE_KEYS:
        if k in entry and isinstance(entry[k], dict):
            nm = entry[k].get("Name")
            if isinstance(nm, list) and nm:
                return str(nm[0])
    nm = entry.get("Name")
    if isinstance(nm, list) and nm:
        return str(nm[0])
    return None


def find_array_bounds(text: str, key: str = '"MathModels"') -> tuple[int, int]:
    i = text.index(key)
    j = text.index("[", i)
    depth = 0
    k = j
    in_str = False
    esc = False
    while True:
        c = text[k]
        if in_str:
            if esc:
                esc = False
            elif c == "\\":
                esc = True
            elif c == '"':
                in_str = False
        else:
            if c == '"':
                in_str = True
            elif c == "[":
                depth += 1
            elif c == "]":
                depth -= 1
                if depth == 0:
                    return j, k
        k += 1


def iter_top_level_objects(text: str, start: int, end: int):
    """Yield (obj_start, obj_end) spans of direct {...} children of the array."""
    i = start + 1
    in_str = False
    esc = False
    while i < end:
        c = text[i]
        if in_str:
            if esc:
                esc = False
            elif c == "\\":
                esc = True
            elif c == '"':
                in_str = False
            i += 1
            continue
        if c == '"':
            in_str = True
        elif c == "{":
            depth = 0
            j = i
            s2 = False
            e2 = False
            while True:
                cj = text[j]
                if s2:
                    if e2:
                        e2 = False
                    elif cj == "\\":
                        e2 = True
                    elif cj == '"':
                        s2 = False
                else:
                    if cj == '"':
                        s2 = True
                    elif cj == "{":
                        depth += 1
                    elif cj == "}":
                        depth -= 1
                        if depth == 0:
                            yield i, j + 1
                            break
                j += 1
            i = j + 1
            continue
        i += 1


def format_entry(md: dict) -> str:
    dumped = json.dumps(md, indent=2, ensure_ascii=False)
    return "\n".join("    " + ln for ln in dumped.split("\n"))


# ---------------------------------------------------------------------------
# Sampling / comparison
# ---------------------------------------------------------------------------

def _grid_points(x0, x1, y0, y1, z0, z1, n_points: int):
    n = max(3, min(40, round(n_points ** (1.0 / 3.0))))
    xs = [x0 + (x1 - x0) * i / (n - 1) for i in range(n)] if x1 > x0 else [x0]
    ys = [y0 + (y1 - y0) * i / (n - 1) for i in range(n)] if y1 > y0 else [y0]
    zs = [z0 + (z1 - z0) * i / (n - 1) for i in range(n)] if z1 > z0 else [z0]
    return [(x, y, z) for x in xs for y in ys for z in zs]


def _compile_model(md: dict) -> MathModel:
    return MathModel(md, source_name="mcp")


# ---------------------------------------------------------------------------
# MCP tools
# ---------------------------------------------------------------------------

mcp = FastMCP(
    "mathmod",
    instructions=(
        "Tools for working with MathMod model collections (mathmodcollection.js / "
        "advancedmodels.js): list and inspect models, validate scripts against the "
        "fparser engine rules, numerically evaluate and compare implicit surfaces, "
        "estimate render cost, fetch the script reference doc, and safely add or "
        "update models in a collection file."
    ),
)


def _j(obj: Any) -> str:
    return json.dumps(obj, indent=1, ensure_ascii=False)


@mcp.tool()
def list_models(collection: str = "main", filter: Optional[str] = None) -> str:
    """List models in a collection.

    Args:
        collection: "main" (mathmodcollection.js) or "advanced" (advancedmodels.js).
        filter: optional case-insensitive substring to match against name/component/description.
    Returns JSON array of {index, name, type, components}.
    """
    _, data = load_collection(collection)
    out = []
    for i, m in enumerate(data.get("MathModels", [])):
        nm = model_name_of(m) or f"<unnamed #{i}>"
        stype = next((k for k in SURFACE_KEYS if k in m), "?")
        blk = m.get(stype)
        comps = 1
        hay_parts = [nm]
        if isinstance(blk, dict):
            arrs = [blk.get(f) for f in CORE_FIELDS.get(stype, [])]
            lens = [len(a) for a in arrs if isinstance(a, list)]
            comps = max(lens) if lens else 1
            hay_parts += [str(blk.get("Component", [""])), str(blk.get("Description", [""]))]
        elif isinstance(blk, list):
            comps = len(blk)
        hay = " ".join(hay_parts)
        if filter and filter.lower() not in hay.lower():
            continue
        out.append({"index": i, "name": nm, "type": stype, "components": comps})
    return _j(out)


@mcp.tool()
def get_model(name_or_index: str, collection: str = "main") -> str:
    """Fetch one full model entry (JSON) by display name or 0-based index."""
    _, data = load_collection(collection)
    models = data.get("MathModels", [])
    if name_or_index.isdigit():
        i = int(name_or_index)
        if not (0 <= i < len(models)):
            return _j({"status": "error", "message": f"index {i} out of range (0..{len(models)-1})"})
        return json.dumps(models[i], indent=1, ensure_ascii=False)
    for m in models:
        if model_name_of(m) == name_or_index:
            return json.dumps(m, indent=1, ensure_ascii=False)
    return _j({"status": "error", "message": f"no model named {name_or_index!r}"})


@mcp.tool()
def search_models(query: str, collection: str = "main") -> str:
    """Search models by substring in name, component label or description."""
    return list_models(collection=collection, filter=query)


@mcp.tool()
def validate_script(script_json: str) -> str:
    """Validate a MathMod model entry (JSON object with one surface block).

    Checks: top-level shape, required/parallel fields, expression syntax, unknown
    identifiers/functions, Funct ordering (callees before callers), psh/get slot
    bounds vs Vect (missing Vect is an error — the engine aborts with VAR_OVERFLOW),
    eval() arity/placement, integer-only slider values, Grid and bounding-box sanity.

    Args:
        script_json: JSON text of a model entry, e.g. {"Iso3D": {...}} optionally
            with "Sliders"/"Texture"/"Pigment".
    Returns JSON report {status, errors[], warnings[]}.
    """
    try:
        md = json.loads(script_json.replace("DOTSYMBOL", "."), strict=False)
    except Exception as e:
        return _j({"status": "error", "errors": [{"level": "error", "where": "<json>",
                                                  "message": f"invalid JSON: {e}"}]})
    issues = validate_model_dict(md)
    errors = [i for i in issues if i["level"] == "error"]
    warnings = [i for i in issues if i["level"] == "warning"]
    return _j({"status": "ok" if not errors else "rejected",
               "errors": errors, "warnings": warnings})


@mcp.tool()
def validate_model(name_or_index: str, collection: str = "main") -> str:
    """Validate an existing model from a collection (same checks as validate_script)."""
    _, data = load_collection(collection)
    models = data.get("MathModels", [])
    target = None
    if name_or_index.isdigit():
        i = int(name_or_index)
        if 0 <= i < len(models):
            target = models[i]
    else:
        for m in models:
            if model_name_of(m) == name_or_index:
                target = m
    if target is None:
        return _j({"status": "error", "message": f"model {name_or_index!r} not found"})
    issues = validate_model_dict(target)
    errors = [i for i in issues if i["level"] == "error"]
    warnings = [i for i in issues if i["level"] == "warning"]
    return _j({"status": "ok" if not errors else "rejected",
               "model": model_name_of(target),
               "errors": errors, "warnings": warnings})


@mcp.tool()
def evaluate_model(name_or_index: str, n_points: int = 200, t: float = 0.0,
                   collection: str = "main") -> str:
    """Numerically sample an Iso3D model's field F(x,y,z,t) over its bounding box.

    Uses a faithful mini-fparser (app pi=314159265/1e8, 1e-12 comparison tolerance,
    psh/get scratch slots per Vect). Models using app-internal imports (NoiseW etc.)
    cannot be evaluated outside the app and are reported as such.

    Args:
        name_or_index: model display name or 0-based index.
        n_points: approximate number of sample points (grid is cubic).
        t: animation time value.
        collection: "main" or "advanced".
    Returns JSON with min/max/mean/std, fraction negative, and whether the field
    changes sign inside the box (surface likely present).
    """
    _, data = load_collection(collection)
    models = data.get("MathModels", [])
    target = None
    if name_or_index.isdigit():
        i = int(name_or_index)
        if 0 <= i < len(models):
            target = models[i]
    else:
        for m in models:
            if model_name_of(m) == name_or_index:
                target = m
    if target is None:
        return _j({"status": "error", "message": f"model {name_or_index!r} not found"})
    stype = next((k for k in SURFACE_KEYS if k in target), None)
    if stype != "Iso3D":
        return _j({"status": "error",
                   "message": f"{stype} models are parametric — evaluation supports Iso3D only"})
    try:
        model = _compile_model(target)
    except ValueError as e:
        return _j({"status": "error", "message": str(e)})
    if model.imports_used:
        return _j({"status": "error",
                   "message": f"model uses app-internal import(s) {sorted(model.imports_used)}; "
                              f"cannot evaluate outside the MathMod app"})
    x0, x1, y0, y1, z0, z1 = model.bounds(t)
    vals = []
    nan_count = 0
    for (x, y, z) in _grid_points(x0, x1, y0, y1, z0, z1, n_points):
        try:
            v = model.F(x, y, z, t)
        except ValueError:
            nan_count += 1
            continue
        if math.isnan(v):
            nan_count += 1
            continue
        vals.append(v)
    if not vals:
        return _j({"status": "error", "message": "no finite values obtained"})
    mean = sum(vals) / len(vals)
    std = math.sqrt(sum((v - mean) ** 2 for v in vals) / len(vals))
    neg = sum(1 for v in vals if v < 0)
    sign_change = any(a * b < 0 for a, b in zip(vals, vals[1:])) or \
        (min(vals) < 0 < max(vals))
    return _j({
        "status": "ok", "model": model_name_of(target),
        "box": [x0, x1, y0, y1, z0, z1], "t": t,
        "n_evaluated": len(vals), "n_nan_or_error": nan_count,
        "min": min(vals), "max": max(vals), "mean": mean, "std": std,
        "fraction_negative": neg / len(vals),
        "sign_change_in_box": sign_change,
    })


@mcp.tool()
def compare_models(a: str, b: str, n_points: int = 400, t: float = 0.0,
                   collection: str = "main") -> str:
    """Compare two Iso3D models' fields over the intersection of their boxes.

    Reports max/mean |ΔF| and sign changes — the standard geometry-equivalence
    check (differences at ~1e-16 mean identical to machine precision).

    Args:
        a, b: model display names or 0-based indices.
        n_points: approximate number of sample points.
        t: animation time value.
        collection: "main" or "advanced".
    """
    _, data = load_collection(collection)
    models = data.get("MathModels", [])

    def find(key):
        if key.isdigit():
            i = int(key)
            return models[i] if 0 <= i < len(models) else None
        for m in models:
            if model_name_of(m) == key:
                return m
        return None

    ma, mb = find(a), find(b)
    if ma is None or mb is None:
        return _j({"status": "error", "message": f"model(s) not found: {a!r}, {b!r}"})
    try:
        model_a = _compile_model(ma)
        model_b = _compile_model(mb)
    except ValueError as e:
        return _j({"status": "error", "message": str(e)})
    for m, key in ((model_a, a), (model_b, b)):
        if m.imports_used:
            return _j({"status": "error",
                       "message": f"model {key!r} uses app-internal imports; cannot compare outside the app"})
    ba = model_a.bounds(t)
    bb = model_b.bounds(t)
    x0, x1 = max(ba[0], bb[0]), min(ba[1], bb[1])
    y0, y1 = max(ba[2], bb[2]), min(ba[3], bb[3])
    z0, z1 = max(ba[4], bb[4]), min(ba[5], bb[5])
    if x0 >= x1 or y0 >= y1 or z0 >= z1:
        return _j({"status": "error", "message": "bounding boxes do not overlap"})
    max_d = 0.0
    sum_d = 0.0
    n = 0
    sign_changes = 0
    worst = None
    for (x, y, z) in _grid_points(x0, x1, y0, y1, z0, z1, n_points):
        va = model_a.F(x, y, z, t)
        vb = model_b.F(x, y, z, t)
        if math.isnan(va) or math.isnan(vb):
            continue
        d = abs(va - vb)
        sum_d += d
        n += 1
        if d > max_d:
            max_d = d
            worst = [x, y, z]
        if (va < 0) != (vb < 0):
            sign_changes += 1
    if n == 0:
        return _j({"status": "error", "message": "no finite sample points"})
    return _j({
        "status": "ok",
        "a": model_name_of(ma), "b": model_name_of(mb),
        "n_points": n, "t": t,
        "max_abs_diff": max_d, "mean_abs_diff": sum_d / n,
        "sign_changes": sign_changes,
        "worst_point": worst,
        "verdict": ("identical to machine precision" if max_d < 1e-9 else
                    "geometrically equivalent (rounding-level differences)" if max_d < 1e-6 else
                    "DIFFERENT geometry"),
    })


@mcp.tool()
def estimate_cost(name_or_index: str, collection: str = "main") -> str:
    """Estimate per-point evaluation cost in 'trig units' (sin/cos=1, sqrt=0.5,
    floor/min/max=0.2, arithmetic=0.1, psh/get=0.1; user calls fully expanded —
    fparser has no common-subexpression elimination). Also reports if() count and
    batch-mode risk."""
    _, data = load_collection(collection)
    models = data.get("MathModels", [])
    target = None
    if name_or_index.isdigit():
        i = int(name_or_index)
        if 0 <= i < len(models):
            target = models[i]
    else:
        for m in models:
            if model_name_of(m) == name_or_index:
                target = m
    if target is None:
        return _j({"status": "error", "message": f"model {name_or_index!r} not found"})
    return _j(estimate_cost_dict(target))


@mcp.tool()
def upsert_model(script_json: str, collection: str = "main", dry_run: bool = False) -> str:
    """Add a new model to a collection file, or replace an existing model with the
    same display name. The script is fully validated first; nothing is written if
    validation reports errors. A rolling backup <file>.bak is created before writing.

    Args:
        script_json: JSON text of a complete model entry (must include a Name).
        collection: "main" or "advanced".
        dry_run: validate and report the planned action without writing.
    Returns JSON {status, action, backup, models_before, models_after}.
    """
    try:
        md = json.loads(script_json.replace("DOTSYMBOL", "."), strict=False)
    except Exception as e:
        return _j({"status": "error", "message": f"invalid JSON: {e}"})
    issues = validate_model_dict(md)
    errors = [i for i in issues if i["level"] == "error"]
    name = model_name_of(md)
    if not name:
        return _j({"status": "rejected",
                   "message": "model has no Name field — required to upsert",
                   "errors": errors,
                   "warnings": [i for i in issues if i["level"] == "warning"]})
    if errors:
        return _j({"status": "rejected", "errors": errors,
                   "warnings": [i for i in issues if i["level"] == "warning"]})

    path = COLLECTIONS.get(collection)
    with open(path, encoding="utf-8") as fh:
        text = fh.read()
    data = json.loads(text.replace("DOTSYMBOL", "."), strict=False)
    models_before = len(data.get("MathModels", []))

    arr_start, arr_end = find_array_bounds(text)
    existing_span = None
    for (s, e) in iter_top_level_objects(text, arr_start, arr_end):
        try:
            obj = json.loads(text[s:e].replace("DOTSYMBOL", "."), strict=False)
        except Exception:
            continue
        if model_name_of(obj) == name:
            existing_span = (s, e)
            break

    entry_text = format_entry(md)
    if existing_span is not None:
        new_text = text[:existing_span[0]] + entry_text + text[existing_span[1]:]
        action = "updated"
    else:
        inner = text[arr_start + 1:arr_end].strip()
        sep = "" if not inner else ",\n"
        new_text = text[:arr_end] + sep + "\n" + entry_text + text[arr_end:]
        action = "added"

    # verify before writing
    check = json.loads(new_text.replace("DOTSYMBOL", "."), strict=False)
    names_after = [model_name_of(m) for m in check.get("MathModels", [])]
    if len(names_after) != models_before + (0 if action == "updated" else 1):
        return _j({"status": "error", "message": "post-splice model count mismatch"})
    if names_after.count(name) != 1:
        return _j({"status": "error", "message": f"name {name!r} not unique after splice"})

    if dry_run:
        return _j({"status": "dry-run ok", "action": action, "model": name,
                   "collection_file": path,
                   "models_before": models_before,
                   "warnings": [i for i in issues if i["level"] == "warning"]})

    backup = path + ".bak"
    with open(backup, "w", encoding="utf-8") as fh:
        fh.write(text)
    with open(path, "w", encoding="utf-8") as fh:
        fh.write(new_text)
    return _j({"status": "ok", "action": action, "model": name,
               "collection_file": path, "backup": backup,
               "models_before": models_before,
               "models_after": len(names_after),
               "warnings": [i for i in issues if i["level"] == "warning"]})


@mcp.tool()
def reference(topic: Optional[str] = None) -> str:
    """Return the MathMod script reference doc (docs/mathmod-scripts-reference.md).

    Args:
        topic: optional section keyword (e.g. "Vect", "Sliders", "Funct", "eval") —
            returns matching sections; omit for the full document.
    """
    if not os.path.exists(REFERENCE_DOC):
        return _j({"status": "error", "message": f"reference doc not found at {REFERENCE_DOC}"})
    with open(REFERENCE_DOC, encoding="utf-8") as fh:
        text = fh.read()
    if not topic:
        return text
    sections = re.split(r"(?m)^(?=## )", text)
    hits = [s for s in sections if topic.lower() in s.lower()]
    if not hits:
        return _j({"status": "error", "message": f"no section matching {topic!r}"})
    return "".join(hits)


def main():
    mcp.run()


if __name__ == "__main__":
    main()
