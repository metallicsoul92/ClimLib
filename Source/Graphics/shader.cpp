#include "../../Include/shader.h"
#include "../../Include/Logger.h"
#include <QOpenGLFunctions>
namespace clim{
namespace graphics{
    QOpenGLFunctions oglfunc;





    QVector<ShaderUniform> Shader::getUniforms() const
    {
        return uniforms;
    }

    quint32 Shader::load() const
    {
        auto program = oglfunc.glCreateProgram();
        auto vertex = oglfunc.glCreateShader(GL_VERTEX_SHADER);
        auto tessalation1 = oglfunc.glCreateShader(GL_TESS_CONTROL_SHADER);
    auto tessalation2 = oglfunc.glCreateShader(GL_TESS_EVALUATION_SHADER);
    auto geometry = oglfunc.glCreateShader(GL_GEOMETRY_SHADER);
    auto fragment = oglfunc.glCreateShader(GL_FRAGMENT_SHADER);

    auto source = m_sources[0].toStdString().c_str();

    oglfunc.glShaderSource(vertex,1, &source,nullptr);
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

    if(m_sources[1] != NULL){
        source = NULL;
        source = m_sources[1].toStdString().c_str();
    oglfunc.glShaderSource(tessalation1,1, &source,nullptr);
    oglfunc.glCompileShader(tessalation1);

    int result;
    oglfunc.glGetShaderiv(tessalation1,GL_COMPILE_STATUS, &result);
    if(result ==GL_FALSE){
        int length;
        oglfunc.glGetShaderiv(tessalation1,GL_INFO_LOG_LENGTH,&length);
        QVector<char> error(length);
        oglfunc.glGetShaderInfoLog(tessalation1,length,&length,&error[0]);
        system::logger.writeToGELog("Failed to initialize Vertex Shader! ");
        system::logger.writeToGELog(&error[0]);
        oglfunc.glDeleteShader(tessalation1);
        return 0;
    }
    }
   if(m_sources[2] != NULL){
       source = NULL;
       source = m_sources[2].toStdString().c_str();
    oglfunc.glShaderSource(tessalation2,1, &source,nullptr);
    oglfunc.glCompileShader(tessalation2);

    int result;
    oglfunc.glGetShaderiv(tessalation2,GL_COMPILE_STATUS, &result);
    if(result ==GL_FALSE){
        int length;
        oglfunc.glGetShaderiv(tessalation2,GL_INFO_LOG_LENGTH,&length);
        QVector<char> error(length);
        oglfunc.glGetShaderInfoLog(tessalation2,length,&length,&error[0]);
        system::logger.writeToGELog("Failed to initialize Vertex Shader! ");
        system::logger.writeToGELog(&error[0]);
        oglfunc.glDeleteShader(tessalation2);
        return 0;
    }
   }
   if(m_sources[3] != NULL){
       source = NULL;
       source = m_sources[3].toStdString().c_str();
    oglfunc.glShaderSource(geometry,1, &source,nullptr);
    oglfunc.glCompileShader(tessalation2);

    int result;
    oglfunc.glGetShaderiv(geometry,GL_COMPILE_STATUS, &result);
    if(result ==GL_FALSE){
        int length;
        oglfunc.glGetShaderiv(geometry,GL_INFO_LOG_LENGTH,&length);
        QVector<char> error(length);
        oglfunc.glGetShaderInfoLog(geometry,length,&length,&error[0]);
        system::logger.writeToGELog("Failed to initialize Vertex Shader! ");
        system::logger.writeToGELog(&error[0]);
        oglfunc.glDeleteShader(geometry);
        return 0;
    }
   }
   source = NULL;
   source = m_sources[4].toStdString().c_str();
    oglfunc.glShaderSource(fragment,1, &source,nullptr);
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

int Shader::getUniformLocation(const GLchar *name) const
{
    auto result = oglfunc.glGetUniformLocation(m_ShaderID, name);
    if (result == -1){
        QString log;
        log += this->m_name;
        log.append(" : couldnt find uniform ");
        log.append(name);
        log.append(" in shader!");
        system::logger.writeToGELog(log.toStdString());
    }
    return result;
}

Shader::Shader(const QString &name, const QString *vertSource, const QString *fragSource)  : m_name(name)
{
       m_sources = QVector<QString>(5);
        m_sources[0] = vertSource->toStdString().c_str();
        m_sources[2] = fragSource->toStdString().c_str();
        m_ShaderID = load();
}

Shader::~Shader()
{

}

void Shader::addSource(SHADER_TYPE type,const QString& source)
{
    int temp = (int)type;
    m_sources.insert(temp,source);
}

void Shader::setUniform1f(const QString &name, float value)
{

    oglfunc.glUniform1f( getUniformLocation((GLchar *)name.toStdString().c_str()), value);
}

void Shader::setUniform1fv(const QString &name, float *value, int count)
{

    oglfunc.glUniform1fv(getUniformLocation((GLchar *)name.toStdString().c_str()),count,value);
}

void Shader::setUniform1i(const QString &name, int value)
{

  oglfunc.glUniform1i(getUniformLocation((GLchar *)name.toStdString().c_str()),value);
}

void Shader::setUniform1iv(const QString &name, int *value, int count)
{

    oglfunc.glUniform1iv(getUniformLocation((GLchar *)name.toStdString().c_str()),count, value);
}

void Shader::setUniform2f(const QString &name, const math::vec2<float> &vector)
{

    oglfunc.glUniform2f(getUniformLocation((GLchar *)name.toStdString().c_str()),vector.x,vector.y);
}

void Shader::setUniform3f(const QString &name, const math::vec3<float> &vector)
{

    oglfunc.glUniform3f(getUniformLocation((GLchar *)name.toStdString().c_str()),vector.x,vector.y,vector.z);
}

void Shader::setUniform4f(const QString &name, const math::vec4<float> &vector)
{

    oglfunc.glUniform4f(getUniformLocation((GLchar *)name.toStdString().c_str()),vector.x,vector.y,vector.z,vector.w);
}

void Shader::setUniformMat4(const QString &name, const math::mat4<float> &matrix)
{

    oglfunc.glUniformMatrix4fv(getUniformLocation((GLchar *)name.toStdString().c_str()),1,GL_FALSE,matrix.element);
}

void Shader::bind()
{
    this->m_ShaderID = load();
    oglfunc.glUseProgram(m_ShaderID);
}

void Shader::unbind() const
{
    oglfunc.glUseProgram(0);
}

bool Shader::hasUniform(const QString &name) const
{

}


}
}
