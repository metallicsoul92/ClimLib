#ifndef TRANSFORM
#define TRANSFORM

#include "Component.h"
#include "MathTypes.h"

namespace clim{
    namespace core{

    class Transform : public Component{

    private:
        bool changed;
        int m_childCount;
        clim::math::vec3<float> m_eulerAngles;
        clim::math::vec3<float> m_localEulerAngles;

        //Determining Direction
        math::vec3<float> m_foward;
        math::vec3<float> m_up;
        math::vec3<float> m_right;

        math::mat4<float> m_ltwMatrix;
        math::mat4<float> m_wtlMatrix;

        math::vec3<float> m_position;
        math::vec3<float> m_localPosition;
        math::vec3<float> m_scale;
        math::vec3<float> m_localScale;
        math::vec4<float> m_rotation;
        math::vec4<float> m_localRotation;
        Transform *m_parentTransform;
        std::vector<Transform *> m_children;
        Transform *root;

        // Component interface
    public:

        Transform(const math::vec3<float> &position, const math::vec3<float> &scale, math::vec4<float> &rotation);
        Transform(Entity *parent, const math::vec3<float> &position, const math::vec3<float> &scale, math::vec4<float> &rotation);


        void Awake();
        void Destroy();
        void Start();
        void FixUpdate();
        void Update();
        void LateUpdate();
        bool getChanged() const;
        void setChanged(bool value);
        int getChildCount() const;
        void setChildCount(int childCount);
        clim::math::vec3<float> getEulerAngles() const;
        void setEulerAngles(const clim::math::vec3<float> &eulerAngles);
        clim::math::vec3<float> getLocalEulerAngles() const;
        void setLocalEulerAngles(const clim::math::vec3<float> &localEulerAngles);
        math::vec3<float> getFoward() const;
        void setFoward(const math::vec3<float> &foward);
        math::vec3<float> getUp() const;
        void setUp(const math::vec3<float> &up);
        math::vec3<float> getRight() const;
        void setRight(const math::vec3<float> &right);
        math::mat4<float> getLtwMatrix() const;
        math::mat4<float> getWtlMatrix() const;
        math::vec3<float> getPosition() const;
        void setPosition(const math::vec3<float> &position);
        math::vec3<float> getLocalPosition() const;
        void setLocalPosition(const math::vec3<float> &localPosition);
        math::vec3<float> getScale() const;
        void setScale(const math::vec3<float> &scale);
        math::vec3<float> getLocalScale() const;
        void setLocalScale(const math::vec3<float> &localScale);
        math::vec4<float> getRotation() const;
        void setRotation(const math::vec4<float> &rotation);
        math::vec4<float> getLocalRotation() const;
        void setLocalRotation(const math::vec4<float> &localRotation);
        Transform *getParentTransform() const;
        void setParentTransform(Transform *parentTransform);
        std::vector<Transform *> getChildren() const;
        void setChildren(const std::vector<Transform *> &children);
        Transform *getRoot() const;
    };


    }

}


#endif // TRANSFORM

