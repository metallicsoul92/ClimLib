#ifndef RENDERABLE2D
#define RENDERABLE2D

#include "MathTypes.h"
#include "irenderable.h"
#include "renderer2d.h"
namespace clim{
    namespace graphics{


    class Renderable2d : public iRenderable{

    private:
        math::vec3<float> m_Position;
        math::vec2<unsigned int> m_Size;
        unsigned int m_Color;
        QVector<math::vec2<float>> m_UV;
        QImage m_Texture;
        bool m_Visible;

    protected:
        Renderable2d(): m_Texture(){
            m_UV = GetDefaultUVs();
        }

       public:
        virtual ~Renderable2d() { }

        virtual void Submit(Renderer2D* renderer) const
        {
            renderer->Submit(this);
        }
        Renderable2d(const math::vec3<float> position, const math::vec2<unsigned int> size, unsigned int color)
            :m_Position(position), m_Size(size),m_Color(color), m_Texture(nullptr){
            m_UV = GetDefaultUVs();
        }
        math::vec2<unsigned int> renderable2d::Size() const
        {
            return m_Size;
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

       m_Color = a << 24 | b << 16 | g << 8 | r;
    }
    QVector<math::vec2<float> > UV() const
    {
    return m_UV;
    }
    QImage Texture() const
    {
    return m_Texture;
    }
    math::vec3<float> Position() const
        {
            return m_Position;
        }




    //Static Functions

    static QVector<math::vec2<float>> GetDefaultUVs()
            {
                static QVector<maths::vec2> results;
                if (!results.size())
                {
                    results.push_back(math::vec2<float>(0, 0));
                    results.push_back(math::vec2<float>(0, 1));
                    results.push_back(math::vec2<float>(1, 1));
                    results.push_back(math::vec2<float>(1, 0));
                }
                return results;
            }





    };


    }
}




#endif // RENDERABLE2D

