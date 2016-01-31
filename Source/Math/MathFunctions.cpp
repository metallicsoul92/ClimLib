#include "../../Include/MathFunctions.h"

# define M_PI           3.14159265358979323846  /* pi */
#include <iostream>

namespace clim{
	namespace math{

		template<typename t>
		vec2<t> mathFunc::add(vec2<t> *a, vec2<t> b) {
			vec2<t> c;
			c.x = a->x + b.x;
			c.y = a->y + b.y;
			return c;
		}
		template<typename t>
		vec2<t> mathFunc::subtract(vec2<t> *a, vec2<t> b){
			vec2<t> c;
			c.x = a->x - b.x;
			c.y = a->y - b.y;
			return c;
		}
		template<typename t>
		vec2<t> mathFunc::multiply(vec2<t> *a, vec2<t> b){
			vec2<t> c;
			c.x = a->x * b.x;
			c.y = a->y * b.y;
			return c;
		}
		template<typename t>
		vec2<t> mathFunc::divide(vec2<t> *a, vec2<t> b){
			vec2<t> c;
			c.x = a->x / b.x;
			c.y = a->y / b.y;
			return c;
		}

		template <typename t>
		vec2<t> mathFunc::create_vec2(t x, t y)
		{
			vec2<t> temp;
			temp.x = x;
			temp.y = y;
			return temp;
		}

		template<typename t>
		vec2<t> mathFunc::cross(vec2<t> *a, vec2<t> b){
			vec2<t> c;
			c = new vec2<t>(a->x*b.y, -(a->y*b.x));

			return c;
		}


		template<typename t>
		vec3<t> mathFunc::add(vec3<t> *a, vec3<t> b){
			vec3<t> c;
			c.x = a->x + b.x;
			c.y = a->y + b.y;
			c.z = a->z + b.z;
			return c;
		}
		template<typename t>
		vec3<t> mathFunc::subtract(vec3<t> *a, vec3<t> b){
			vec3<t> c;
			c.x = a->x - b.x;
			c.y = a->y - b.y;
			c.z = a->z - b.z;
			return c;
		}
		template<typename t>
		vec3<t> mathFunc::multiply(vec3<t> *a, vec3<t> b){
			vec3<t> c;
			c.x = a->x * b.x;
			c.y = a->y * b.y;
			c.z = a->z * b.z;
			return c;
		}
		template<typename t>
		vec3<t> mathFunc::divide(vec3<t> *a, vec3<t> b){
			vec3<t> c;
			c.x = a->x / b.x;
			c.y = a->y / b.y;
			c.z = a->z / b.z;
			return c;
		}
		template<typename t>
		vec3<t> mathFunc::Lerp(vec3<t> start, vec3<t> end, float percent){
			{
				vec3<t> temp = mathFunc::subtract(end, start);
				vec3<t> *tem = vec3<t> {percent / 100.0f, percent / 100.0f, percent / 100.0f };
				temp = mathFunc::multiply(*tem, temp);
				delete *tem;
				return start + temp;

			}
		}


		template<typename t>
		vec3<t> mathFunc::cross(vec3<t> *a, vec3<t> b){
			vec3<t> c;
			c = new vec3<t>(a->y*b.z, (a->x*b.z) - (a->z*b.x), (a->x*b.y) - (a->y*b.x));
			return c;
		}

		template <typename t>
		vec3<t> mathFunc::create_vec3(t x, t y, t z)
		{
			vec3<t> temp;
			temp.x = x;
			temp.y = y;
			temp.z = z;
			return temp;
		}



		template<typename t>
		vec4<t> mathFunc::add(vec4<t> *a, vec4<t> b){
			vec4<t> c;
			c.x = a->x + b.x;
			c.y = a->y + b.y;
			c.z = a->z + b.z;
			c.w = a->w + b.w;
			return c;
		}
		template<typename t>
		vec4<t> mathFunc::subtract(vec4<t> *a, vec4<t> b){
			vec4<t> c;
			c.x = a->x - b.x;
			c.y = a->y - b.y;
			c.z = a->z - b.z;
			c.w = a->w - b.w;
			return c;
		}
		template<typename t>
		vec4<t> mathFunc::multiply(vec4<t> *a, vec4<t> b){
			vec4<t> c;
			c.x = a->x * b.x;
			c.y = a->y * b.y;
			c.z = a->z * b.z;
			c.w = a->w * b.w;
			return c;
		}
		template<typename t>
		vec4<t> mathFunc::divide(vec4<t> *a, vec4<t> b){
			vec4<t> c;
			c.x = a->x / b.x;
			c.y = a->y / b.y;
			c.z = a->z / b.z;
			c.w = a->w / b.w;
			return c;
		}

		template <typename t>
		vec4<t> mathFunc::cross(vec2<t>* a, vec2<t> b)
		{
			//TODO REIMPLEMENT
			return;
		}

		template<typename t>
		vec4<t> mathFunc::Slerp(vec4<t> start, vec4<t> end, float percent){
	
			//TODO REIMPLEMENT
			return;
		}
		template <typename t>
		vec4<t> mathFunc::create_vec4(t x, t y, t z, t w)
		{
			vec4<t> temp;
			temp.x = x;
			temp.y = y;
			temp.z = z;
			temp.w = w;
			return temp;
		}

		template<typename t>
		mat4<t> mathFunc::add(mat4<t> *a, mat4<t> b){
			mat4<t> c;
			for (int i = 0; i < 16; i++){
				c.mat4.element[i] = a->element[i] + b.element[i];
			}
			return c;
		}
		template<typename t>
		mat4<t> mathFunc::subtract(mat4<t> *a, mat4<t> b){
			mat4<t> c;
			for (int i = 0; i < 16; i++){
				c.mat4.element[i] = a->element[i] - b.element[i];
			}
			return c;
		}
		template<typename t>
		mat4<t> mathFunc::multiply(mat4<t> *a, mat4<t> b){
			mat4<t> c;
			for (int i = 0; i < 16; i++){
				c.mat4.element[i] = a->element[i] * b.element[i];
			}
			return c;
		}
		template<typename t>
		mat4<t> mathFunc::divide(mat4<t> *a, mat4<t> b){
			mat4<t> c;
			for (int i = 0; i < 16; i++){
				c.mat4.element[i] = a->element[i] / b.element[i];
			}
			return c;
		}

		template<typename t>
		void operator<<(std::ostream& os, vec2<t> &vec2){
			os << "Vec2 : {" << vec2.x << " , " << vec2.y << " }" << std::endl;

		}
		template<typename t>
		void operator<<(std::ostream& os, vec3<t> &vec3){
			os << "Vec3 : {" << vec3.x << " , " << vec3.y << " , " << vec3.z << " }" << std::endl;

		}
		template<typename t>
		void operator<<(std::ostream& os, vec4<t> &vec4){
			os << "Vec4 : {" << vec4.x << " , " << vec4.y << " , " << vec4.z << " , " << vec4.w << " }" << std::endl;
		}




		template<typename t>
		mat4<t>& mathFunc::invert(mat4<t> &mat4)   {
			double temp[16];

			temp[0] = mat4.element[5] * mat4.element[10] * mat4.element[15] -
				mat4.element[5] * mat4.element[11] * mat4.element[14] -
				mat4.element[9] * mat4.element[6] * mat4.element[15] +
				mat4.element[9] * mat4.element[7] * mat4.element[14] +
				mat4.element[13] * mat4.element[6] * mat4.element[11] -
				mat4.element[13] * mat4.element[7] * mat4.element[10];

			temp[4] = -mat4.element[4] * mat4.element[10] * mat4.element[15] +
				mat4.element[4] * mat4.element[11] * mat4.element[14] +
				mat4.element[8] * mat4.element[6] * mat4.element[15] -
				mat4.element[8] * mat4.element[7] * mat4.element[14] -
				mat4.element[12] * mat4.element[6] * mat4.element[11] +
				mat4.element[12] * mat4.element[7] * mat4.element[10];

			temp[8] = mat4.element[4] * mat4.element[9] * mat4.element[15] -
				mat4.element[4] * mat4.element[11] * mat4.element[13] -
				mat4.element[8] * mat4.element[5] * mat4.element[15] +
				mat4.element[8] * mat4.element[7] * mat4.element[13] +
				mat4.element[12] * mat4.element[5] * mat4.element[11] -
				mat4.element[12] * mat4.element[7] * mat4.element[9];

			temp[12] = -mat4.element[4] * mat4.element[9] * mat4.element[14] +
				mat4.element[4] * mat4.element[10] * mat4.element[13] +
				mat4.element[8] * mat4.element[5] * mat4.element[14] -
				mat4.element[8] * mat4.element[6] * mat4.element[13] -
				mat4.element[12] * mat4.element[5] * mat4.element[10] +
				mat4.element[12] * mat4.element[6] * mat4.element[9];

			temp[1] = -mat4.element[1] * mat4.element[10] * mat4.element[15] +
				mat4.element[1] * mat4.element[11] * mat4.element[14] +
				mat4.element[9] * mat4.element[2] * mat4.element[15] -
				mat4.element[9] * mat4.element[3] * mat4.element[14] -
				mat4.element[13] * mat4.element[2] * mat4.element[11] +
				mat4.element[13] * mat4.element[3] * mat4.element[10];

			temp[5] = mat4.element[0] * mat4.element[10] * mat4.element[15] -
				mat4.element[0] * mat4.element[11] * mat4.element[14] -
				mat4.element[8] * mat4.element[2] * mat4.element[15] +
				mat4.element[8] * mat4.element[3] * mat4.element[14] +
				mat4.element[12] * mat4.element[2] * mat4.element[11] -
				mat4.element[12] * mat4.element[3] * mat4.element[10];

			temp[9] = -mat4.element[0] * mat4.element[9] * mat4.element[15] +
				mat4.element[0] * mat4.element[11] * mat4.element[13] +
				mat4.element[8] * mat4.element[1] * mat4.element[15] -
				mat4.element[8] * mat4.element[3] * mat4.element[13] -
				mat4.element[12] * mat4.element[1] * mat4.element[11] +
				mat4.element[12] * mat4.element[3] * mat4.element[9];

			temp[13] = mat4.element[0] * mat4.element[9] * mat4.element[14] -
				mat4.element[0] * mat4.element[10] * mat4.element[13] -
				mat4.element[8] * mat4.element[1] * mat4.element[14] +
				mat4.element[8] * mat4.element[2] * mat4.element[13] +
				mat4.element[12] * mat4.element[1] * mat4.element[10] -
				mat4.element[12] * mat4.element[2] * mat4.element[9];

			temp[2] = mat4.element[1] * mat4.element[6] * mat4.element[15] -
				mat4.element[1] * mat4.element[7] * mat4.element[14] -
				mat4.element[5] * mat4.element[2] * mat4.element[15] +
				mat4.element[5] * mat4.element[3] * mat4.element[14] +
				mat4.element[13] * mat4.element[2] * mat4.element[7] -
				mat4.element[13] * mat4.element[3] * mat4.element[6];

			temp[6] = -mat4.element[0] * mat4.element[6] * mat4.element[15] +
				mat4.element[0] * mat4.element[7] * mat4.element[14] +
				mat4.element[4] * mat4.element[2] * mat4.element[15] -
				mat4.element[4] * mat4.element[3] * mat4.element[14] -
				mat4.element[12] * mat4.element[2] * mat4.element[7] +
				mat4.element[12] * mat4.element[3] * mat4.element[6];

			temp[10] = mat4.element[0] * mat4.element[5] * mat4.element[15] -
				mat4.element[0] * mat4.element[7] * mat4.element[13] -
				mat4.element[4] * mat4.element[1] * mat4.element[15] +
				mat4.element[4] * mat4.element[3] * mat4.element[13] +
				mat4.element[12] * mat4.element[1] * mat4.element[7] -
				mat4.element[12] * mat4.element[3] * mat4.element[5];

			temp[14] = -mat4.element[0] * mat4.element[5] * mat4.element[14] +
				mat4.element[0] * mat4.element[6] * mat4.element[13] +
				mat4.element[4] * mat4.element[1] * mat4.element[14] -
				mat4.element[4] * mat4.element[2] * mat4.element[13] -
				mat4.element[12] * mat4.element[1] * mat4.element[6] +
				mat4.element[12] * mat4.element[2] * mat4.element[5];

			temp[3] = -mat4.element[1] * mat4.element[6] * mat4.element[11] +
				mat4.element[1] * mat4.element[7] * mat4.element[10] +
				mat4.element[5] * mat4.element[2] * mat4.element[11] -
				mat4.element[5] * mat4.element[3] * mat4.element[10] -
				mat4.element[9] * mat4.element[2] * mat4.element[7] +
				mat4.element[9] * mat4.element[3] * mat4.element[6];

			temp[7] = mat4.element[0] * mat4.element[6] * mat4.element[11] -
				mat4.element[0] * mat4.element[7] * mat4.element[10] -
				mat4.element[4] * mat4.element[2] * mat4.element[11] +
				mat4.element[4] * mat4.element[3] * mat4.element[10] +
				mat4.element[8] * mat4.element[2] * mat4.element[7] -
				mat4.element[8] * mat4.element[3] * mat4.element[6];

			temp[11] = -mat4.element[0] * mat4.element[5] * mat4.element[11] +
				mat4.element[0] * mat4.element[7] * mat4.element[9] +
				mat4.element[4] * mat4.element[1] * mat4.element[11] -
				mat4.element[4] * mat4.element[3] * mat4.element[9] -
				mat4.element[8] * mat4.element[1] * mat4.element[7] +
				mat4.element[8] * mat4.element[3] * mat4.element[5];

			temp[15] = mat4.element[0] * mat4.element[5] * mat4.element[10] -
				mat4.element[0] * mat4.element[6] * mat4.element[9] -
				mat4.element[4] * mat4.element[1] * mat4.element[10] +
				mat4.element[4] * mat4.element[2] * mat4.element[9] +
				mat4.element[8] * mat4.element[1] * mat4.element[6] -
				mat4.element[8] * mat4.element[2] * mat4.element[5];

			double determinant = mat4.element[0] * temp[0] + mat4.element[1] * temp[4] + mat4.element[2] * temp[8] + mat4.element[3] * temp[12];
			determinant = 1.0 / determinant;

			for (int i = 0; i < 4 * 4; i++)
				mat4.element[i] = temp[i] * determinant;

			return this;
		}
		template<typename t>
		 mat4<t> mathFunc::orthographic(float left, float right, float bottom, float top, float near, float far){
			{
				mat4<t> result;
				result.element[0 + 0 * 4] = 1;
				result.element[1 + 1 * 4] = 1;
				result.element[2 + 2 * 4] = 1;
				result.element[3 + 3 * 4] = 1;

				result.element[0 + 0 * 4] = 2 / (right - left);

				result.element[1 + 1 * 4] = 2 / (top - bottom);

				result.element[2 + 2 * 4] = 2 / (near - far);

				result.element[0 + 3 * 4] = (left + right) / (left - right);
				result.element[1 + 3 * 4] = (bottom + top) / (bottom - top);
				result.element[2 + 3 * 4] = (far + near) / (far - near);

				return result;
			}
		}
		template<typename t>
		mat4<t> mathFunc::perspective(float fov, float aspectRatio, float near, float far)
		{
			mat4<t> result(1);

			float q = 1 / tan(toRadians(0.5 * fov));
			float a = q / aspectRatio;

			float b = (near + far) / (near - far);
			float c = (2 * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[3 + 2 * 4] = -1;
			result.elements[2 + 3 * 4] = c;

			return result;
		}


		template<typename t>
		 mat4<t> mathFunc::translation(vec3<t>& translation)
		{
			mat4<t> result(1);

			result.elements[0 + 3 * 4] = translation.getX();
			result.elements[1 + 3 * 4] = translation.getY();
			result.elements[2 + 3 * 4] = translation.getZ();

			return result;
		}

		template<typename t>
		mat4<t> mathFunc::rotation(float angle, vec3<t>& axis)
		{
			mat4<t> result(1);

			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1 - c;

			float x = axis.getX();
			float y = axis.getY();
			float z = axis.getZ();

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[1 + 0 * 4] = y * x * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;

			result.elements[0 + 1 * 4] = x * y * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc + x * s;

			result.elements[0 + 2 * 4] = x * z * omc + y * s;
			result.elements[1 + 2 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		}
		template<typename t>
		 mat4<t> mathFunc::scale(vec3<t>& scale)
		{
			mat4<t> result(1);

			result.elements[0 + 0 * 4] = scale.getX();
			result.elements[1 + 1 * 4] = scale.getY();
			result.elements[2 + 2 * 4] = scale.getZ();

			return result;
		}


		float mathFunc::toRadians(float degrees)
		{

			return degrees * (M_PI / 180);
		}
	}
}
