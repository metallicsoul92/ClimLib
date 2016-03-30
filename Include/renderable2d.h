#ifndef RENDERABLE2D
#define RENDERABLE2D

#include "MathTypes.h"
#include "irenderable.h"
#include "renderer2d.h"


namespace clim{
    namespace graphics{


    class Renderable2d : public iRenderable{

    private:
        unsigned int m_Color;
        QVector<math::vec2<float>> m_UV;
        bool m_Visible;

    protected:
        Renderable2d(){
            m_UV = GetDefaultUVs();
        }

       public:
        virtual ~Renderable2d() { }

        virtual void Submit(Renderer2D* renderer) const
        {
            //renderer->submit(this);
        }
        Renderable2d(unsigned int color)
            :m_Color(color){
            m_UV = GetDefaultUVs();
        }

    unsigned int Color() const
    {
    return m_Color;
    }
    void setColor(unsigned int Color)
    {
    m_Color = Color;
    }
    void setColor(const math::vec4<float>& color){

        unsigned int uicolor[4];
        uicolor[0] = (uint)(color.getX() * 255.0f);
        uicolor[1] = (uint)(color.getY() * 255.0f);
        uicolor[2] = (uint)(color.getZ() * 255.0f);
        uicolor[3] = (uint)(color.getW() * 255.0f);

       m_Color = uicolor[0] << 24 | uicolor[1] << 16 | uicolor[2] << 8 | uicolor[3];
    }
    QVector<math::vec2<float> > UV() const
    {
    return m_UV;
    }




    //Static Functions

    static QVector<math::vec2<float>> GetDefaultUVs()
            {
                static QVector<math::vec2<float>> results;
                if (!results.size())
                {
                    results.push_back(math::vec2<float>(0, 0));
                    results.push_back(math::vec2<float>(0, 1));
                    results.push_back(math::vec2<float>(1, 1));
                    results.push_back(math::vec2<float>(1, 0));
                }
                return results;
            }






    // iRenderable interface
    public:
    void Render(base_Renderer *context);
    };


    }
}




#endif // RENDERABLE2D

