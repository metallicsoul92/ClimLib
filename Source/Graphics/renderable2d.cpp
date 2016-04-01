#include "../../Include/renderable2d.h"

namespace clim{
    namespace graphics{





    Renderable2d::Renderable2d():iRenderable(){
        m_Color = 0;
        m_UV = GetDefaultUVs();
        m_Visible = false;
        m_vData = nullptr;
    }

    Renderable2d::Renderable2d(const vertexData &data):iRenderable(), m_vData(new vertexData(data))
    {
        m_Visible = false;
        m_UV = GetDefaultUVs();
        m_Color = 0;
    }

    Renderable2d::~Renderable2d()
    {
        delete m_vData;
    }


    unsigned int Renderable2d::Color() const
    {
        return m_Color;
    }

    void Renderable2d::setColor(unsigned int Color)
{
    m_Color = Color;
}

void Renderable2d::setColor(const math::vec4<float> &color){

    unsigned int uicolor[4];
    uicolor[0] = (uint)(color.getX() * 255.0f);
    uicolor[1] = (uint)(color.getY() * 255.0f);
    uicolor[2] = (uint)(color.getZ() * 255.0f);
    uicolor[3] = (uint)(color.getW() * 255.0f);

    m_Color = uicolor[0] << 24 | uicolor[1] << 16 | uicolor[2] << 8 | uicolor[3];
}

QVector<math::vec2<float> > clim::graphics::Renderable2d::UV() const
{
    return m_UV;
}

QVector<math::vec2<float> > Renderable2d::GetDefaultUVs()
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




    }
}
