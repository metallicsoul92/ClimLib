#ifndef CAMERA2D_H
#define CAMERA2D_H

//User Defines
#include "Component.h"
#include "renderer2d.h"
#include "renderable2d.h"
#include "MathFunctions.h"
#include "vertexdata.h"
#include "shader.h"

//QT Defines
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLFramebufferObject>



typedef QOpenGLVertexArrayObject VertexArray;
typedef QOpenGLFramebufferObject FrameBuffer;



namespace clim{
    namespace core{

    class Camera2D : protected Component{

    private:
    protected:
    public:




        // Component interface
    public:
        void Awake();
        void Destroy();
        void Start();
        void FixUpdate();
        void Update();
        void LateUpdate();
    };
    }
}




#endif // CAMERA2D_H
