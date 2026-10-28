# Standalone tests/benchmark for the fparser batch evaluator (Eval2).
# No Qt required: builds a plain console executable.
#
# Build (from this directory):
#   qmake tests.pro CONFIG+=release
#   make -j
#
# Run:
#   ./fparser_eval2_test            # correctness check (default)
#   ./fparser_eval2_test check
#   ./fparser_eval2_test fuzz [seed] [count]
#   ./fparser_eval2_test bench [NB]
#   ./fparser_eval2_test bench_mt [T] [NBtotal]

TEMPLATE = app
TARGET   = fparser_eval2_test
CONFIG  += c++17 console
CONFIG  -= app_bundle   # plain executable, not a macOS .app bundle
QT      -= core gui     # no Qt: drop qmake's default modules

INCLUDEPATH += ..
SOURCES     += eval2_test.cpp \
               ../fparser.cc
