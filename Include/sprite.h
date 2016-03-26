#ifndef SPRITE_H
#define SPRITE_H


//Qt Defines
#include <QImage>

//User Defines
#include "vec2.h"
#include "Component.h"
#include "renderable2d.h"


namespace clim{
namespace graphics{

    class Sprite: protected core::Component{


    private:
        QImage *m_sprite;
        math::vec2<int> *m_size;
        bool m_isRendered;

   public:
   Sprite(const QString& filepath,const math::vec2<int>& size);
   Sprite(const QImage& image,const math::vec2<int>& size);
   ~Sprite();



  void setImage(const QString& filepath);
  void setImage(const QImage& image);

  void setSize(const math::vec2<int> size);
  void setSize(int x, int y);

  math::vec2<int> *Size();
  math::vec2<int> *getSize()const;

  QImage *sprite();
  QImage *getSprite()const;




  // Component interface

  void Awake();
  void Destroy();
  void Start();
  void FixUpdate();
  void Update();
  void LateUpdate();
    };






}
}


#endif // SPRITE_H
