#include "../../Include/MathFunctions.h"
#include "../../Include/mat4.h"
#include "../../Include/vec3.h"

namespace clim{
	namespace math{

    float toRadians(float degrees){
        return degrees * (M_PI / 180);
    }

    mat4<float> orthographic(float left, float right, float bottom, float top, float near, float far){

         mat4<float> result(1);

        result.setElement(0+0*4, 2/(right-left));
        result.setElement(1+1*4,2/(top-bottom));
        result.setElement(2+2*4, 2/(near-far));

        result.setElement(0+3*4, (left+right)/(left-right));
        result.setElement(1+3*4 , (bottom+top)/(bottom-top));
        result.setElement(2+3*4,(far+near)/(far- near));


         return result;
     }

    mat4<float> perspective(float fov, float aspectRatio, float near, float far)
{
    mat4<float> result;

    float q = 1 / tan(toRadians(0.5 * fov));
    float a = q / aspectRatio;


    float b = ( near + far ) / ( near - far );
    float c = (2 * near * far) / (near - far);

    result.setElement(0 + 0 * 4 , a);
    result.setElement(1 + 1 * 4 , q);
    result.setElement(2 + 2 * 4 , b);
    result.setElement(3 + 2 * 4 , -1);
    result.setElement(2 + 3 * 4, c);

    return result;
}


    }
}
