HEADERS += \
    Include/Buffer.h \
    Include/Component.h \
    Include/Debugger.h \
    Include/Entity.h \
    Include/fileutils.h \
    Include/Logger.h \
    Include/MathFunctions.h \
    Include/MathTypes.h \
    Include/platform.h \
    Include/screen.h

SOURCES += \
    Source/Component/Component.cpp \
    Source/Math/MathFunctions.cpp \
    Source/System/Buffer.cpp \
    Source/System/Debugger.cpp \
    Source/System/Logger.cpp \
    Source/System/platform.cpp \
    Source/Entity/Entity.cpp \
    Source/Graphics/screen.cpp \
    Source/main.cpp


CONFIG += c++11
QT += opengl
QT += gui

FORMS +=
