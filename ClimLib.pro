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
    Include/screen.h \
    Include/audio.h \
    Include/console.h \
    Include/engine.h \
    Include/keyboard.h \
    Include/mouse.h \
    Include/shader.h \
    Include/shaderuniform.h \
    Include/stringutils.h \
    Include/vec2.h \
    Include/vec3.h \
    Include/vec4.h \
    Include/mat4.h

SOURCES += \
    Source/Component/Component.cpp \
    Source/System/Buffer.cpp \
    Source/System/Debugger.cpp \
    Source/System/Logger.cpp \
    Source/System/platform.cpp \
    Source/Entity/Entity.cpp \
    Source/Graphics/screen.cpp \
    Source/main.cpp \
    Source/Core/audio.cpp \
    Source/System/console.cpp \
    Source/Core/engine.cpp \
    Source/Math/MathFunctions.cpp \
    Source/System/keyboard.cpp \
    Source/System/mouse.cpp \
    Source/Graphics/shader.cpp \
    Source/Graphics/shaderuniform.cpp

CONFIG += console
CONFIG += c++11
QT += gui widgets
QT += multimedia

FORMS += \
   Source/System/console.ui
