#include "../../include/renderer2d.h"
#include "../../include/sprite.h"

namespace clim{
namespace graphics{

void Renderer2D::push(core::Entity *temp)
{
    m_viewableEntities.push_back(temp);
}

void Renderer2D::pop()
{
    m_viewableEntities.pop_back();
}

void Renderer2D::Render()
{
    for(int i = 0; i < m_viewableEntities.size();i++){
        if(m_viewableEntities.at(i)->findComponentType<graphics::Sprite>() != nullptr){

        }
    }


}









    }
}
