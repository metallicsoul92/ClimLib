#ifndef RENDERER2D
#define RENDERER2D

#include "MathTypes.h"
#include "base_renderer.h"
#include "Entity.h"
#include <QVector>
namespace clim{
namespace graphics{

    enum GlTarget{ GT_SCREEN, GT_BUFFER};

    class Renderer2D : public base_Renderer{

    private:


    public:
       void push();
       void pop();
       // base_Renderer interface
       void Render();

    };

}
}



#endif // RENDERER2D

