#include "../../Include/transform.h"


namespace clim{
namespace core{

int Transform::getChildCount() const
{
    return m_childCount;
}

void Transform::setChildCount(int childCount)
{
    m_childCount = childCount;
}

math::vec3<float> Transform::getEulerAngles() const
{
    return m_eulerAngles;
}

void Transform::setEulerAngles(const clim::math::vec3<float> &eulerAngles)
{
    m_eulerAngles = eulerAngles;
}

math::vec3<float> Transform::getLocalEulerAngles() const
{
    return m_localEulerAngles;
}

void Transform::setLocalEulerAngles(const clim::math::vec3<float> &localEulerAngles)
{
    m_localEulerAngles = localEulerAngles;
}

math::vec3<float> Transform::getFoward() const
{
    return m_foward;
}

void Transform::setFoward(const math::vec3<float> &foward)
{
    m_foward = foward;
}

math::vec3<float> Transform::getUp() const
{
    return m_up;
}

void Transform::setUp(const math::vec3<float> &up)
{
    m_up = up;
}

math::vec3<float> Transform::getRight() const
{
    return m_right;
}

void Transform::setRight(const math::vec3<float> &right)
{
    m_right = right;
}

math::mat4<float> Transform::getLtwMatrix() const
{
    return m_ltwMatrix;
}

math::mat4<float> Transform::getWtlMatrix() const
{
    return m_wtlMatrix;
}

math::vec3<float> Transform::getPosition() const
{
    return m_position;
}

void Transform::setPosition(const math::vec3<float> &position)
{
    m_position = position;
}

math::vec3<float> Transform::getLocalPosition() const
{
    return m_localPosition;
}

void Transform::setLocalPosition(const math::vec3<float> &localPosition)
{
    m_localPosition = localPosition;
}

math::vec3<float> Transform::getScale() const
{
    return m_scale;
}

void Transform::setScale(const math::vec3<float> &scale)
{
    m_scale = scale;
}

math::vec3<float> Transform::getLocalScale() const
{
    return m_localScale;
}

void Transform::setLocalScale(const math::vec3<float> &localScale)
{
    m_localScale = localScale;
}

math::vec4<float> Transform::getRotation() const
{
    return m_rotation;
}

void Transform::setRotation(const math::vec4<float> &rotation)
{
    m_rotation = rotation;
}

math::vec4<float> Transform::getLocalRotation() const
{
    return m_localRotation;
}

void Transform::setLocalRotation(const math::vec4<float> &localRotation)
{
    m_localRotation = localRotation;
}

Transform *Transform::getParentTransform() const
{
    return m_parentTransform;
}

void Transform::setParentTransform(Transform *parentTransform)
{
    m_parentTransform = parentTransform;
}

std::vector<Transform *> Transform::getChildren() const
{
    return m_children;
}

void Transform::setChildren(const std::vector<Transform *> &children)
{
    m_children = children;
}

Transform *Transform::getRoot() const
{
    return root;
}
bool Transform::getChanged() const
{
    return changed;
}

void Transform::setChanged(bool value)
{
    changed = value;
}



















}
}
