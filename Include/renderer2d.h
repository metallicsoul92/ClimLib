#ifndef RENDERER2D
#define RENDERER2D

#include "MathTypes.h"
#include <QVector>
namespace clim{
namespace graphics{

    enum GlTarget{ GT_SCREEN, GT_BUFFER};

    class Renderer2D{

        protected:
        QVector<math::mat4<float>> m_Transformation;
        const math::mat4<float>* m_transformBack;
        GlTarget m_target;

        Renderer2D(){
            m_Transformation.push_back(math::mat4<float>(1.0f));
            m_transformBack = &m_Transformation.back();
            m_target = GlTarget::GT_SCREEN;
        }

    public:

        virtual ~Renderer2D(){ }
        void push(const math::mat4<float>& matrix, bool override = false){
            if(override)
                m_Transformation.push_back(matrix);
            else{
                math::mat4<float> trans = *m_transformBack;
                math::mat4<float> newTransform = trans.mul(matrix);
                m_Transformation.push_back(newTransform);
            }
            m_transformBack = &m_Transformation.back();

        }
        void pop(){
            if(m_Transformation.size()>1)
                m_Transformation.pop_back();

            m_transformBack = &m_Transformation.back();
        }

        inline void SetGlTarget(GlTarget target){
            m_target = target;}

        virtual void begin(){}
        virtual void submit() =0;
        virtual void End() {}
        virtual void Present() = 0;



    };

}
}



#endif // RENDERER2D

