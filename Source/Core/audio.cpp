#include "../../Include/audio.h"
namespace clim{
    namespace core{




    Audio::Audio(QString name,QString path): m_Name(name), m_Path(AUDIOFOLDER+path)
    {
        QString fullFilePath = AUDIOFOLDER;
        fullFilePath +=path;
        m_Sound = new QSound(fullFilePath);
    }

    Audio::Audio(const Audio &copy):
    m_Name(copy.getName()), m_Path(copy.getPath()){
       m_Sound = new QSound(m_Path);
    }

     void Audio::play(){
        QSound::play(this->m_Path);
     }

     void Audio::stop(){
         m_Sound->stop();
     }

     QString Audio::getName() const
     {
         return m_Name;
     }
     \
     QString& Audio::Name(){
         return m_Name;
     }

     QString Audio::getPath() const
     {
         return m_Path;
     }
     \
     QString& Audio::Path(){
         return m_Path;
     }

    }
}
