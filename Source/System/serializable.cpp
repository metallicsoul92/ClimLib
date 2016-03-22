#include "../../include/serializable.h"



namespace clim{
namespace system{

QJsonDocument *serializable::getFile() const
{
    return m_file;
}

QJsonDocument *system::serializable::File()
{
    return m_file;
}

QJsonObject *system::serializable::getObject() const
{
    return m_object;
}

QJsonObject *system::serializable::Object()
{
    return m_object;
}

void serializable::setFile(QJsonDocument *file)
{
    m_file = file;
}

void clim::system::serializable::setObject(QJsonObject *object)
{
    m_object = object;
}





}
}
