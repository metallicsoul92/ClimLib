#ifndef SHADERUNIFORM
#define SHADERUNIFORM

//QT Headers
#include <QString>
#include <QVariant>

//User Defined Headers

namespace clim{
    namespace graphics{

    enum ShaderUniformType{ SUT_BOOL, SUT_INT,SUT_UINT,
                            SUT_FLOAT,SUT_DOUBLE, SUT_BVEC2,SUT_BVEC3,
                            SUT_BVEC4,SUT_IVEC2, SUT_IVEC3,SUT_IVEC4,
                            SUT_UVEC2,SUT_UVEC3,SUT_UVEC4,SUT_VEC2,SUT_VEC3,
                            SUT_VEC4,SUT_DVEC2,SUT_DVEC3,SUT_DVEC4,SUT_MAT2,
                            SUT_MAT3,SUT_MAT4 };


    class ShaderUniform{

        private:
        QString m_name;
        ShaderUniformType m_type;
        QVariant m_value;

    public:
        ShaderUniform(QString name,ShaderUniformType type,QVariant data)
            : m_name(name),m_type(type),m_value(data)
        {

        }
        ~ShaderUniform()
        {

        }
        ShaderUniform *getUniform()
        {
            return this;
        }


        QString getName() const
        {
            return m_name;
        }
        void setName(const QString &name)
        {
            m_name = name;
        }
        QVariant getValue() const
        {
            return m_value;
        }
        void setValue(const QVariant &value)
        {
            m_value = value;
        }
    };


    }
}




#endif // SHADERUNIFORM

