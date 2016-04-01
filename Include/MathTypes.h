#ifndef MATHTYPES
#define MATHTYPES


#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

#include <QMetaType>

Q_DECLARE_METATYPE(clim::math::vec2<int>)
Q_DECLARE_METATYPE(clim::math::vec2<float>)
Q_DECLARE_METATYPE(clim::math::vec2<char>)
Q_DECLARE_METATYPE(clim::math::vec2<bool>)
Q_DECLARE_METATYPE(clim::math::vec2<double>)

Q_DECLARE_METATYPE(clim::math::vec3<int>)
Q_DECLARE_METATYPE(clim::math::vec3<float>)
Q_DECLARE_METATYPE(clim::math::vec3<char>)
Q_DECLARE_METATYPE(clim::math::vec3<bool>)
Q_DECLARE_METATYPE(clim::math::vec3<double>)

Q_DECLARE_METATYPE(clim::math::vec4<int>)
Q_DECLARE_METATYPE(clim::math::vec4<float>)
Q_DECLARE_METATYPE(clim::math::vec4<char>)
Q_DECLARE_METATYPE(clim::math::vec4<bool>)
Q_DECLARE_METATYPE(clim::math::vec4<double>)

Q_DECLARE_METATYPE(clim::math::mat4<int>)
Q_DECLARE_METATYPE(clim::math::mat4<float>)
Q_DECLARE_METATYPE(clim::math::mat4<char>)
Q_DECLARE_METATYPE(clim::math::mat4<bool>)
Q_DECLARE_METATYPE(clim::math::mat4<double>)



#endif

