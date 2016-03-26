#ifndef MATHFUNCTIONS_H_
#define MATHFUNCTIONS_H_
//Normal Math Functions
#include <math.h>

//QT Related files

//QT Defines
#include <QString>
#include <QMetaType>

//C++ Defines
#include <iostream>

//User Defines
#include "../Dependencies/glm/glm/glm.hpp"
#include "../Dependencies/glm/glm/gtc/matrix_transform.hpp"
#include "../Dependencies/glm/glm/mat4x4.hpp"


#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif //M_PI
namespace clim{
	namespace math{



    float toRadians(float degrees);




		}

}



#endif // end math functions
