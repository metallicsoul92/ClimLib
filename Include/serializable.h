#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <QJsonDocument>


namespace clim{
    namespace system{

    class serializable{

    public:

        QJsonDocument *getFile()const;
        QJsonDocument *File();

        QJsonObject *getObject()const;
        QJsonObject *Object();

        void setFile(QJsonDocument *file);
        void setObject(QJsonObject *object);

        virtual void read(const QJsonObject &object);
        virtual void write(QJsonObject &object)const;


    protected:
        QJsonDocument *m_file;
        QJsonObject *m_object;




    };




    }
}



#endif // SERIALIZABLE_H
