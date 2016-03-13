#include "../../Include/vertexdata.h"

namespace clim{
namespace graphics{
vertexData::vertexData(): m_vertex(math::vec3<float>()), m_uv(math::vec2<float>()), m_Tid(0.0f), m_id(0.0f), m_Color(0) {

}

vertexData::vertexData(const vertexData &copy): m_vertex(copy.vertex()), m_uv(copy.uv()), m_Tid(copy.getTid()), m_id(copy.getMid()), m_Color(copy.getColor())
{

}

vertexData::vertexData(vertexData &&move):m_vertex(std::move(move.getVertex())), m_uv(std::move(move.getUV())), m_Tid(std::move(move.Tid())), m_id(std::move(move.Mid())),
m_Color(std::move(move.color()))
{

}

vertexData::vertexData(math::vec3<float> vertex, math::vec2<float> uv, float tid, float id, unsigned int color):
    m_vertex(vertex), m_uv(uv), m_Tid(tid), m_id(id), m_Color(color)
{

}

vertexData &vertexData::operator=(const vertexData &copy)
{
    m_vertex = copy.vertex();
    m_uv = copy.uv();
    m_Tid = copy.getTid();
    m_id = copy.getMid();
    m_Color = copy.getColor();

    return *this;
}

vertexData &vertexData::operator=(vertexData&& move){

    m_vertex = std::move(move.getVertex());
    m_uv = std::move(move.getUV());
    m_Tid = std::move(move.Tid());
    m_id = std::move(move.Mid());
    m_Color = std::move(move.color());

    return *this;
}


math::vec2<float> vertexData::uv() const
{
    return m_uv;
}

math::vec2<float> &vertexData::getUV()
{
    return m_uv;
}

void vertexData::setUv(const math::vec2<float> &uv)
{
    m_uv = uv;
}



float vertexData::getTid() const
{
    return m_Tid;
}

void vertexData::setTid(float value)
{
    m_Tid = value;
}

float vertexData::getMid() const
{
    return m_id;
}

void vertexData::setMid(float value)
{
    m_id = value;
}

unsigned int vertexData::getColor() const
{
    return m_Color;
}

void vertexData::setColor(unsigned int value)
{
    m_Color = value;
}


math::vec3<float> vertexData::vertex() const
{
    return m_vertex;
}

math::vec3<float>& vertexData::getVertex()
{
    return m_vertex;
}

void vertexData::setVertex(const math::vec3<float> &vertex)
{
    m_vertex = vertex;
}







}
}
