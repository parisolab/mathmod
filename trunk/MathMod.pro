HEADERS    = ui_modules/drawingoptions.h \
             ui_modules/colorsoptions.h \
             ui_modules/about.h \
             ui_modules/mathmod.h \
             ui_modules/ParisoMathObject.h \
             ui_modules/editor.h \
             pariso/parametric/Model3D.h \
             pariso/parametric/ND/Matrix4D.h \
             fparser/fparser.h \
             pariso/isosurface/Iso3D.h \
             gl_viewer/glviewer.h \
             gl_viewer/qglthread.h \
             pariso/objectparameters.h \
             pariso/isosurface/TableMap.h \
             gl_viewer/raster.h \
             json_parser/parisodef.h \
             json_parser/jiso.h \
             json_parser/jpar.h \
             screenshot/video.h \
             ui_modules/parametersoptions.h \
    pariso/commun.h

SOURCES    = ui_modules/drawingoptions.cpp \
             ui_modules/colorsoptions.cpp \
             ui_modules/mathmod.cpp \
             ui_modules/about.cpp \
             ui_modules/ParisoMathObject.cpp \
             ui_modules/editor.cpp \
             fparser/fparser.cpp \
             pariso/parametric/Model3D.cpp \
             pariso/parametric/ND/Matrix4D.cpp \
             pariso/isosurface/Iso3D.cpp \
             gl_viewer/qglthread.cpp \
             gl_viewer/glviewer.cpp \
             pariso/objectparameters.cpp \
             main.cpp \
             json_parser/parisodef.cpp \
             json_parser/jiso.cpp \
             json_parser/jpar.cpp \
             screenshot/video.cpp \
             ui_modules/parametersoptions.cpp \
    pariso/commun.cpp

FORMS      = ui_forms/drawingoptions.ui \
             ui_forms/colorsoptions.ui \
             ui_forms/about.ui \
             ui_forms/mathmod.ui \
             ui_forms/editor.ui \
             ui_forms/parametersoptions.ui
RC_FILE = mm.rc
RESOURCES += myressources.qrc

QT           += opengl widgets

OTHER_FILES += \
             mathmodconf.js \
             mathmodcollection.js \
    mathmodconfig.js

# install
target.path    = $TARGET
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS mathmod.pro
sources.path = $TARGET
INSTALLS += target sources
