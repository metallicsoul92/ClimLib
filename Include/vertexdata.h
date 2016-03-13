#ifndef VERTEXDATA
#define VERTEXDATA

#include "MathTypes.h"

namespace clim{
    namespace graphics{

    class vertexData{

    private:
            math::vec3<float> m_vertex;
            math::vec2<float> m_uv;
            float m_Tid;
            float m_id;
            unsigned int m_Color;
    public:
            vertexData();
            vertexData(const vertexData& copy);
            vertexData(vertexData&& move);
            vertexData(math::vec3<float> vertex, math::vec2<float> uv, float tid, float id, unsigned int color);

            vertexData &operator=(const vertexData& copy);
            vertexData &operator=(vertexData&& move);


            math::vec3<float> vertex() const;
            math::vec3<float> &getVertex();
            void setVertex(const math::vec3<float> &vertex);

            math::vec2<float> uv() const;
            math::vec2<float> &getUV();
            void setUv(const math::vec2<float> &uv);

            float getTid() const;
            float &Tid() {return m_Tid;}
            void setTid(float value);

            float getMid() const;
            float &Mid(){ return m_id;}
            void setMid(float value);

            unsigned int getColor() const;
            unsigned int &color(){return m_Color;}
            void setColor(unsigned int value);
    };





}
}


#endif // VERTEXDATA

