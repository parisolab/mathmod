# Regression test for the catenoid-helicoid associate family models
# ("Helicoid_To_Catenoid" + strict companion "Minimal_Helicoid_Catenoid").
# No Qt required: builds a plain console executable.
# See strict_minimal_model_test.cpp header for what it verifies.
#
# Build (from this directory):
#   qmake strict_minimal_model_test.pro CONFIG+=release
#   make -j
#
# Run:
#   ./fparser_strict_minimal_model_test    # exit 0 = pass

TEMPLATE = app
TARGET   = fparser_strict_minimal_model_test
CONFIG  += c++17 console
CONFIG  -= app_bundle   # plain executable, not a macOS .app bundle
QT      -= core gui     # no Qt: drop qmake's default modules

# Both TUs must be built without FMA contraction: the test requires
# bit-identical results between the batch interpreter and a closed-form
# C++ reference compiled in the same TU.
QMAKE_CXXFLAGS += -ffp-contract=off

INCLUDEPATH += ..
SOURCES     += strict_minimal_model_test.cpp \
               ../fparser.cc
