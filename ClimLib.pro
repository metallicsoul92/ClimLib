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
    Include/stringutils.h \
    Include/vec2.h \
    Include/vec3.h \
    Include/vec4.h \
    Include/mat4.h \
    Include/irenderable.h \
    Include/renderer2d.h \
    Include/renderable2d.h \
    Include/vertexdata.h \
    Include/transform.h \
    Include/shadervariable.h \
    Include/serializable.h \
    Include/sprite.h \
    Include/camera2d.h \
    Include/singleton.h

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
    Source/Graphics/vertexdata.cpp \
    Source/Component/transform.cpp \
    Source/Graphics/shadervariable.cpp \
    Source/System/serializable.cpp \
    Source/Graphics/sprite.cpp \
    Source/Component/camera2d.cpp

CONFIG += console
CONFIG += c++14
QT += gui widgets opengl
QT += multimedia

FORMS += \
   Source/System/console.ui

unix|win32: LIBS += -L$$PWD/Dependencies/lua-5.3.2/builds/mingw/lib/ -llua

INCLUDEPATH += $$PWD/Dependencies/lua-5.3.2/builds/mingw/include
INCLUDEPATH += $$PWD/Dependencies/glm/glm
DEPENDPATH += $$PWD/Dependencies/lua-5.3.2/builds/mingw/include

DISTFILES +=
