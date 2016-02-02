#include "../../Include/audio.h"
namespace clim{
    namespace core{




    Audio::Audio(QString name,QString path): m_Name(name), m_Path(AUDIOFOLDER+path)
    {
        QString fullFilePath = AUDIOFOLDER;
        fullFilePath +=path;
        m_Sound = new QSound(fullFilePath);
    }

     void Audio::play(){
        QSound::play(this->m_Path);
     }

     void Audio::stop(){
        m_Sound->stop();
     }
    }
}
