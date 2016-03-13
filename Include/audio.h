#ifndef AUDIO
#define AUDIO


#include <QSound>

#define AUDIOFOLDER "../../../../Assets/Audio/"


namespace clim{
    namespace core{

    /**
     * @brief clim::core::Audio
     *      The Audio class is the object in which a sound file is held.
     *      The user will be able to play and stop on command. It uses
     *      QT's built in audio library to wrap a QSound to the object
     *
     *     @var m_Name is the QString in which holds the name of the Sound.
     *     @var m_Path is the QString in which holds the filepath.
     *     @var m_Sound is the QSound object, in which holds the information
     *     Of the file trying to be played.
     *
     */

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

