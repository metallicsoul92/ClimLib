#include "../../Include/shaderuniform.h"

namespace clim{
namespace graphics{

GLint ShaderUniform::getLocation() const
{
    return m_location;
}

void ShaderUniform::setLocation(const GLint &location)
{
    m_location = location;
}

ShaderUniformType ShaderUniform::getType() const
{
    return m_type;
}

void ShaderUniform::setType(const ShaderUniformType &type)
{
    m_type = type;
}
GLsizei ShaderUniform::getSize() const
{
    return m_size;
}

void ShaderUniform::setSize(const GLsizei &value)
{
    m_size = value;
}


}
}
