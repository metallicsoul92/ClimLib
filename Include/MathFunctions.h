#ifndef MATHFUNCTIONS_H_
#define MATHFUNCTIONS_H_



#include "MathTypes.h"


//QT Defines
#include <QString>
#include <QMetaType>

//C++ Defines
#include <iostream>



#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif //M_PI
namespace clim{
	namespace math{






    mat4<float> lookAt(const vec3<float>& camPos, const vec3<float>& , const vec3<float>& up = vec3<float>(0.0f,0.0f,1.0f));

    float toRadians(float degrees);




		}

}



#endif // end math functions
