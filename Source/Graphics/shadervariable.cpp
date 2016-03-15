#include "../../Include/shadervariable.h"

namespace clim{
namespace graphics{

GLint ShaderVariable::getLocation() const
{
    return m_location;
}

void ShaderVariable::setLocation(const GLint &location)
{
    m_location = location;
}

ShaderUniformType ShaderVariable::getType() const
{
    return m_type;
}

void ShaderVariable::setType(const ShaderUniformType &type)
{
    m_type = type;
}
GLsizei ShaderVariable::getSize() const
{
    return m_size;
}

void ShaderVariable::setSize(const GLsizei &value)
{
    m_size = value;
}


}
}
