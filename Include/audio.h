#ifndef AUDIO
#define AUDIO


#include <QSound>


namespace clim{
    namespace core{


    class Audio {

    public:
        Audio(QString name,QString path);

         void play();
         void stop();

    private:

        QString m_Name;
        QString m_Path;
        QSound *m_Sound;
    };


    }
}




#endif // AUDIO

