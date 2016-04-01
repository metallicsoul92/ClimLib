#ifndef RENDERABLE2D
#define RENDERABLE2D

#include "MathTypes.h"
#include "irenderable.h"
#include "renderer2d.h"
#include "vertexdata.h"

namespace clim{
    namespace graphics{


    class Renderable2d : iRenderable{

    private:
        unsigned int m_Color;
        QVector<math::vec2<float>> m_UV;
        bool m_Visible;
        vertexData *m_vData;
    protected:


       public:

        Renderable2d();
        Renderable2d(const Renderable2d &copy);
        Renderable2d(const vertexData& data);

        ~Renderable2d();



    unsigned int Color() const;
    void setColor(unsigned int Color);
    void setColor(const math::vec4<float>& color);
    QVector<math::vec2<float> > UV() const;

    //Static Functions

    static QVector<math::vec2<float>> GetDefaultUVs();

    // iRenderable interface

    void Render(base_Renderer *context)const;
    };


    }
}




#endif // RENDERABLE2D

