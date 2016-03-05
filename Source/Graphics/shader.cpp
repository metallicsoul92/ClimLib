#include "../../Include/shader.h"
#include "../../Include/Logger.h"
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_3_Core>
namespace clim{
namespace graphics{
    QOpenGLFunctions_4_3_Core oglfunc;





    QVector<ShaderUniform*> Shader::getUniforms()
    {
        return uniforms;
    }

    quint32 Shader::load()
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

                //attach all shaders to the program
                oglfunc.glAttachShader(program, vertex);
                oglfunc.glAttachShader(program, tessalation1);
                oglfunc.glAttachShader(program, tessalation2);
                oglfunc.glAttachShader(program, geometry);
                oglfunc.glAttachShader(program, fragment);
                //Link the program
                oglfunc.glLinkProgram(program);
                oglfunc.glValidateProgram(program);

                //set shader uniforms
                GLint count;
                oglfunc.glGetProgramInterfaceiv(program, GL_UNIFORM, GL_ACTIVE_RESOURCES, &count);

                for(int i = 0; i < count; i++){
                 ShaderUniform *temp = new ShaderUniform();
                        GLsizei actualLength =0;
                    GLchar *nameData;
                    GLint arraySize = 0;
                    GLenum type = 0;
                    std::string tempstr;
                    int maxSize = tempstr.max_size();
                    oglfunc.glGetActiveUniform(program,i,maxSize,&actualLength, &arraySize, &type, nameData);
                    temp->setName(nameData);
                    temp->setSize(actualLength);
                    temp->setLocation(oglfunc.glGetUniformLocation(program,nameData));
                    union{
                        float *fvalue;
                        int *ivalue;
                        double *dvalue;
                    };
                    switch(type){
                    case GL_FLOAT:
                        temp->setType(SUT_FLOAT);
                        oglfunc.glGetUniformfv(program,temp->getLocation(),fvalue);
                        temp->setValue<float>(*fvalue);
                          break;
                    case GL_INT:
                        temp->setType(SUT_INT);
                        oglfunc.glGetUniformiv(program,temp->getLocation(),ivalue);
                        temp->setValue<int>(*ivalue);
                          break;
                    case GL_FLOAT_VEC2:
                        temp->setType(SUT_VEC2);
                        oglfunc.glGetUniformfv(program,temp->getLocation(),fvalue);
                        //temp->setValue<math::vec2<float>>(math::vec2<float>(fvalue[0],fvalue[1]));
                        temp->setValue<math::vec2<float>>(math::vec2<float>(fvalue[0],fvalue[1]));
                          break;
                    case GL_FLOAT_VEC3:
                        temp->setType(SUT_VEC3);
                        oglfunc.glGetUniformfv(program,temp->getLocation(),fvalue);
                       // temp->setValue<math::vec3<float>>(math::vec3<float>(fvalue[0],fvalue[1],fvalue[2]));
                        temp->setValue<math::vec3<float>>(math::vec3<float>(fvalue[0],fvalue[1],fvalue[2]));
                          break;
                    case GL_FLOAT_VEC4:
                        temp->setType(SUT_VEC4);
                        oglfunc.glGetUniformfv(program,temp->getLocation(),fvalue);
                        //temp->setValue<math::vec4<float>>(math::vec4<float>(fvalue[0],fvalue[1],fvalue[2],fvalue[3]));
                        temp->setValue<math::vec4<float>>(math::vec4<float>(fvalue[0],fvalue[1],fvalue[2],fvalue[3]));
                        break;
                    case GL_INT_VEC2:
                        temp->setType(SUT_IVEC2);
                        oglfunc.glGetUniformiv(program,temp->getLocation(),ivalue);
                        temp->setValue<math::vec2<int>>(math::vec2<int>(ivalue[0],ivalue[1]));
                          break;
                    case GL_INT_VEC3:
                        temp->setType(SUT_IVEC3);
                        oglfunc.glGetUniformiv(program,temp->getLocation(),ivalue);
                        temp->setValue<math::vec3<int>>(math::vec3<int>(ivalue[0],ivalue[1],ivalue[2]));
                          break;
                    case GL_INT_VEC4:
                        temp->setType(SUT_IVEC4);
                        oglfunc.glGetUniformiv(program,temp->getLocation(),ivalue);
                        temp->setValue<math::vec4<int>>(math::vec4<int>(ivalue[0],ivalue[1],ivalue[2],ivalue[3]));
                        break;
                    }
                uniforms.push_back(temp);
                }


                oglfunc.glDeleteShader(vertex);
                oglfunc.glDeleteShader(tessalation1);
                oglfunc.glDeleteShader(tessalation2);
                oglfunc.glDeleteShader(geometry);
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

Shader::Shader(const QString &name):m_name(name)
{
    m_sources = QVector<QString>(5);
    isInitialized = false;
}

Shader::Shader(const QString &name, const QString *vertSource, const QString *fragSource)  : m_name(name)
{
       m_sources = QVector<QString>(5);
        m_sources[0] = vertSource->toStdString().c_str();
        m_sources[2] = fragSource->toStdString().c_str();
        isInitialized = false;
}

Shader::~Shader()
{
    delete this;
}

bool Shader::initialize()
{
    if(!isInitialized){
    m_ShaderID = load();
    isInitialized = true;
    return true;
    }else
        return false;
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

void Shader::setUniform2f(const QString &name, math::vec2<float> &vector)
{

    oglfunc.glUniform2f(getUniformLocation((GLchar *)name.toStdString().c_str()),(GLfloat)vector.getX(),(GLfloat)vector.getY());

}

void Shader::setUniform3f(const QString &name, math::vec3<float> &vector)
{


    oglfunc.glUniform3f(getUniformLocation((GLchar *)name.toStdString().c_str()),vector.getX(),vector.getY(),vector.getZ());
}

void Shader::setUniform4f(const QString &name, math::vec4<float> &vector)
{

    oglfunc.glUniform4f(getUniformLocation((GLchar *)name.toStdString().c_str()),vector.getX(),vector.getY(),vector.getZ(),vector.getW());
}

void Shader::setUniformMat4(const QString &name, math::mat4<float> &matrix)
{
    GLfloat elements[16];

    for(int i = 0;i < 16; i++){
        elements[i] = matrix.getElement(i);
    }

    oglfunc.glUniformMatrix4fv(getUniformLocation((GLchar *)name.toStdString().c_str()),1,GL_FALSE,elements);
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
        for(int i = 0; i < uniforms.size();i++){
            if (uniforms[i]->getName().contains(name)){
                return true;
            }
        }
        return false;
}


}
}
