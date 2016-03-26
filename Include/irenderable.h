#ifndef IRENDERABLE
#define IRENDERABLE

#include <QOpenGLContext>
#include <QImage>
namespace clim{
    namespace graphics{

    class iRenderable{

    public:
        virtual void Render(QOpenGLContext& context)=0;
    };


    }
}


#endif // IRENDERABLE

