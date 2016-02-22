#include "../../Include/shader.h"
#include "../../Include/Logger.h"
#include <QOpenGLFunctions>
namespace clim{
namespace graphics{
    QOpenGLFunctions oglfunc;

quint32 Shader::load(const char *vertSrc, const char *fragSrc) const
{
    auto program = oglfunc.glCreateProgram();
    auto vertex = oglfunc.glCreateShader(GL_VERTEX_SHADER);
    auto fragment = oglfunc.glCreateShader(GL_FRAGMENT_SHADER);

    oglfunc.glShaderSource(vertex,1, &vertSrc,nullptr);
    oglfunc.glCompileShader(vertex);

    int result;
    oglfunc.glGetShaderiv(vertex,GL_COMPILE_STATUS, &result);
    if(result ==GL_FALSE){
        int length;
        oglfunc.glGetShaderiv(vertex,GL_INFO_LOG_LENGTH,&length);
        QVector<char> error(length);
        oglfunc.glGetShaderInfoLog(vertex,length,&length,&error[0]);
        system::logger.writeToGELog("Failed to initialize Vertex Shader! ");
        system::logger.writeToGELog(&error[0]);
        oglfunc.glDeleteShader(vertex);
        return 0;
    }

    oglfunc.glShaderSource(fragment,1, &fragSrc,nullptr);
    oglfunc.glCompileShader(fragment);

     oglfunc.glGetShaderiv(fragment,GL_COMPILE_STATUS, &result);
                if (result == GL_FALSE)
                {
                    int length;
                    oglfunc.glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
                    std::vector<char> error(length);
                    oglfunc.glGetShaderInfoLog(fragment, length, &length, &error[0]);
                    system::logger.writeToGELog("Failed to initialize Fragment Shader!");
                    system::logger.writeToGELog(&error[0]);
          oglfunc.glDeleteShader(fragment);
                    return 0;
                }

                oglfunc.glAttachShader(program, vertex);
                oglfunc.glAttachShader(program, fragment);

               oglfunc.glLinkProgram(program);
                oglfunc.glValidateProgram(program);

                oglfunc.glDeleteShader(vertex);
                oglfunc.glDeleteShader(fragment);

                return program;



}

Shader::Shader(const QString &name, const QString *vertSource, const QString *fragSource)
{
       m_sources = QVector<QString>(5);
        m_sources[0] = vertSource->toStdString().c_str();
        m_sources[2] = fragSource->toStdString().c_str();
        m_ShaderID = load(vertSource->toStdString().c_str(),fragSource->toStdString().c_str());
}

Shader::~Shader()
{

}


}
}
