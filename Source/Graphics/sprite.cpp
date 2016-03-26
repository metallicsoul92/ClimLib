#include "../../include/Entity.h"
#include "../../include/sprite.h"
#include "../../include/transform.h"

namespace clim{
namespace graphics {


Sprite::Sprite(const QString &filepath, const math::vec2<int> &size)
{
    m_sprite = new QImage(filepath);
    m_size = new math::vec2<int>(size);

   Start();
}

Sprite::Sprite(const QImage &image,const math::vec2<int>& size)
{
 m_sprite = new QImage(image);
 m_size = new math::vec2<int>(size);
}

Sprite::~Sprite()
{
    delete m_sprite;
    delete m_size;
}

void Sprite::setImage(const QString &filepath)
{
   delete m_sprite;
    m_sprite = new QImage(filepath);
}

void Sprite::setImage(const QImage &image)
{
    m_sprite = new QImage(image);
}

void Sprite::setSize(const math::vec2<int> size)
{
    m_size->setX(size.getX());
    m_size->setY(size.getX());
}

void Sprite::setSize(int x, int y)
{
    m_size->setX(x);
    m_size->setY(y);
}

math::vec2<int> *Sprite::Size()
{
    return m_size;
}

math::vec2<int> *Sprite::getSize() const
{
    return m_size;
}

QImage *Sprite::sprite()
{
    return m_sprite;
}

QImage *Sprite::getSprite() const
{
    return m_sprite;
}

void Sprite::Awake()
{

}

void clim::graphics::Sprite::Destroy()
{

}

void clim::graphics::Sprite::Start()
{
    if(!m_parent->findComponentType<core::Transform>()){
        this->m_isRendered = false;
    }
}

void clim::graphics::Sprite::FixUpdate()
{

}

void clim::graphics::Sprite::Update()
{

}

void clim::graphics::Sprite::LateUpdate()
{

}


}
}
