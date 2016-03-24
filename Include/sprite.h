#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include <QImage>
#include "vec2.h"
namespace clim{
namespace graphics{

    class Sprite: protected core::Component{


    private:
        QImage *m_Sprite;
        math::vec2<int> *m_size;


   public:
   Sprite(const QString& filepath,const math::vec2<int>& size);
   Sprite(const QImage& image,const math::vec2<int>& size);

  void setImage(const QString& filepath);
  void setImage(const QImage& image);

  void setSize(const math::vec2<int> size);
  void setSize(int x, int y);

  math::vec2<int> Size();
  math::vec2<int> getSize()const;

  QImage sprite();
  QImage& getSprite()const;




    };






}
}


#endif // SPRITE_H
