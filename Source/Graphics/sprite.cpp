#include "../../include/sprite.h"


namespace clim{
namespace graphics {


Sprite::Sprite(const QString &filepath, const math::vec2<int> &size)
{
    m_Sprite = new QImage(filepath);
    m_size = new math::vec2<int>(size);
}

Sprite::Sprite(const QImage &image,const math::vec2<int>& size)
{
 m_Sprite = new QImage(image);
 m_size = new math::vec2<int>(size);
}

void Sprite::setImage(const QString &filepath)
{
   delete m_Sprite;
    m_Sprite = new QImage(filepath);
}

void Sprite::setImage(const QImage &image)
{
    m_Sprite = image;
}

void Sprite::setSize(const math::vec2<int> size)
{
    m_size = size;
}

void Sprite::setSize(int x, int y)
{
    m_size->setX(x);
    m_size->setY(y);
}

math::vec2<int> Sprite::Size()
{
    return m_size;
}

math::vec2<int> Sprite::getSize() const
{
    return m_size;
}

QImage Sprite::sprite()
{
    return m_Sprite;
}

QImage& Sprite::getSprite() const
{
    return m_Sprite;
}


}
}
