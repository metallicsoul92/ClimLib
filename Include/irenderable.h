#ifndef IRENDERABLE
#define IRENDERABLE



#include <QOpenGLContext>
#include <QImage>
namespace clim{
    namespace graphics{


    //foward declare
    class base_Renderer;

    class iRenderable{

       public:
        iRenderable(){}
       ~iRenderable(){}
        virtual void Render(base_Renderer *context)=0;
    };


    }
}


#endif // IRENDERABLE

