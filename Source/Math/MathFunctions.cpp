#include "../../Include/MathFunctions.h"
#include "../../Include/mat4.h"
#include "../../Include/vec3.h"


namespace clim{
	namespace math{

    float toRadians(float degrees){
        return degrees * (M_PI / 180);
    }

    GLfloat *toFloat(mat4<float> &matrix){
        GLfloat *temp = new GLfloat[16];

        for(int i = 0; i< 16; ++i){
            temp[i]= matrix.getElement(i);
        }
        return temp;
    }

    mat4<float> orthographic(float left, float right, float bottom, float top, float onear, float ofar){

         mat4<float> result(1.0f);

        result.setElement(0+0*4, 2/(right-left));
        result.setElement(1+1*4,2/(top-bottom));
        result.setElement(2+2*4, 2/(onear-ofar));

        result.setElement(0+3*4, (left+right)/(left-right));
        result.setElement(1+3*4 , (bottom+top)/(bottom-top));
        result.setElement(2+3*4,(ofar+onear)/(ofar- onear));


         return result;
     }

    mat4<float> perspective(float fov, float aspectRatio, float pnear, float pfar)
{
    mat4<float> result(1.0f);

    float q = 1 / tan(toRadians(0.5 * fov));
    float a = q / aspectRatio;


    float b = ( pnear + pfar ) / ( pnear - pfar );
    float c = (2.0f * pnear * pfar) / (pnear - pfar);

    result.setElement(0 + 0 * 4 , a);
    result.setElement(1 + 1 * 4 , q);
    result.setElement(2 + 2 * 4 , b);
    result.setElement(3 + 2 * 4 , -1);
    result.setElement(2 + 3 * 4, c);

    return result;
}

    mat4<float> identity(){
           return mat4<float>(1.0f);
    }
    }
}
