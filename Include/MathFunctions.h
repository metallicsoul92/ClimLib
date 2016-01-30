#ifndef MATHFUNCTIONS_H_
#define MATHFUNCTIONS_H_


#include "MathTypes.h"
#include <iostream>


namespace clim{
	namespace math{
		class mathFunc{
		public:
			template<typename t>
			vec2<t> add(vec2<t> *a, vec2<t> b);
			template<typename t>
			vec2<t> subtract(vec2<t> *a, vec2<t> b);
			template<typename t>
			vec2<t> multiply(vec2<t> *a, vec2<t> b);
			template<typename t>
			vec2<t> divide(vec2<t> *a, vec2<t> b);
			template<typename t>
			vec2<t> cross(vec2<t> *a, vec2<t> b);
			template<typename t>
			vec2<t> create_vec2(t x, t y);


			template<typename t>
			vec3<t> add(vec3<t> *a, vec3<t> b);
			template<typename t>
			vec3<t> subtract(vec3<t> *a, vec3<t> b);
			template<typename t>
			vec3<t> multiply(vec3<t> *a, vec3<t> b);
			template<typename t>
			vec3<t> divide(vec3<t> *a, vec3<t> b);
			template<typename t>
			vec3<t> cross(vec3<t> *a, vec3<t> b);
			template<typename t>
			vec3<t> Lerp(vec3<t> start, vec3<t> end, float percent);
			template <typename t>
			vec3<t> create_vec3(t x, t y, t z);

			template<typename t>
			vec4<t> add(vec4<t> *a, vec4<t> b);
			template<typename t>
			vec4<t> subtract(vec4<t> *a, vec4<t> b);
			template<typename t>
			vec4<t> multiply(vec4<t> *a, vec4<t> b);
			template<typename t>
			vec4<t> divide(vec4<t> *a, vec4<t> b);
			template<typename t>
			vec4<t> cross(vec2<t> *a, vec2<t> b);
			template <typename t>
			vec4<t> Slerp(vec4<t> start, vec4<t> end, float percent);
			template <typename t>
			vec4<t> create_vec4(t x, t y, t z, t w);

			template<typename t>
			mat4<t> add(mat4<t> *a, mat4<t> b);
			template<typename t>
			mat4<t> subtract(mat4<t> *a, mat4<t> b);
			template<typename t>
			mat4<t> multiply(mat4<t> *a, mat4<t> b);
			template<typename t>
			mat4<t> divide(mat4<t> *a, mat4<t> b);

			template<typename t>
			friend void operator<<(std::ostream &os,vec2<t> &vec2);
			template<typename t>
			friend void operator<<(std::ostream &os, vec3<t> &vec3);
			template<typename t>
			friend void operator<<(std::ostream &os, vec4<t> &vec4);

			template<typename t>
			mat4<t>& invert(mat4<t> &mat4);
			template<typename t>
			static mat4<t> orthographic(float left, float right, float bottom, float top, float near, float far);
			template<typename t>
			static mat4<t> perspective(float fov, float aspectRatio, float near, float far);

			template<typename t>
			static mat4<t> translation(vec3<t>& translation);
			static float toRadians(float degrees);
			template<typename t>
			static mat4<t> rotation(float angle, vec3<t>& axis);
			template<typename t>
			static mat4<t> scale(vec3<t>& scale);


		};
		}
}

#endif // end math functions