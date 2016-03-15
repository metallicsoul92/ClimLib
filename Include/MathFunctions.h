#ifndef MATHFUNCTIONS_H_
#define MATHFUNCTIONS_H_
//Normal Math Functions
#include <math.h>

//QT Related files
#include <QString>
#include <QMetaType>
#include <iostream>




#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif //M_PI
namespace clim{
	namespace math{



    float toRadians(float degrees);


//                    template<typename t>
//                   vec2<t> add(vec2<t> *a, vec2<t> b) {
//                        vec2<t> c;
//                        c.x = a->x + b.x;
//                        c.y = a->y + b.y;
//                        return c;
//                    }
//                    template<typename t>
//                      vec2<t> subtract(vec2<t> *a, vec2<t> b){
//                        vec2<t> c;
//                        c.x = a->x - b.x;
//                        c.y = a->y - b.y;
//                        return c;
//                    }
//                    template<typename t>
//                     vec2<t> multiply(vec2<t> *a, vec2<t> b){
//                        vec2<t> c;
//                        c.x = a->x * b.x;
//                        c.y = a->y * b.y;
//                        return c;
//                    }
//                    template<typename t>
//                      vec2<t> divide(vec2<t> *a, vec2<t> b){
//                        vec2<t> c;
//                        c.x = a->x / b.x;
//                        c.y = a->y / b.y;
//                        return c;
//                    }

//                    template <typename t>
//                      vec2<t> create_vec2(t x, t y)
//                    {
//                        vec2<t> temp;
//                        temp.x = x;
//                        temp.y = y;
//                        return temp;
//                    }

//                    template<typename t>
//                      vec2<t> cross(vec2<t> *a, vec2<t> b){
//                        vec2<t> c;
//                        c = new vec2<t>(a->x*b.y, -(a->y*b.x));

//                        return c;
//                    }


//                    template<typename t>
//                      vec3<t> add(vec3<t> *a, vec3<t> b){
//                        vec3<t> c;
//                        c.x = a->x + b.x;
//                        c.y = a->y + b.y;
//                        c.z = a->z + b.z;
//                        return c;
//                    }
//                    template<typename t>
//                      vec3<t> subtract(vec3<t> *a, vec3<t> b){
//                        vec3<t> c;
//                        c.x = a->x - b.x;
//                        c.y = a->y - b.y;
//                        c.z = a->z - b.z;
//                        return c;
//                    }
//                    template<typename t>
//                      vec3<t> multiply(vec3<t> *a, vec3<t> b){
//                        vec3<t> c;
//                        c.x = a->x * b.x;
//                        c.y = a->y * b.y;
//                        c.z = a->z * b.z;
//                        return c;
//                    }
//                    template<typename t>
//                      vec3<t> divide(vec3<t> *a, vec3<t> b){
//                        vec3<t> c;
//                        c.x = a->x / b.x;
//                        c.y = a->y / b.y;
//                        c.z = a->z / b.z;
//                        return c;
//                    }
//                    template<typename t>
//                      vec3<t> Lerp(vec3<t> start, vec3<t> end, float percent){
//                        {
//                            vec3<t> temp = subtract(end, start);
//                            vec3<t> *tem = vec3<t> {percent / 100.0f, percent / 100.0f, percent / 100.0f };
//                            temp = multiply(*tem, temp);
//                            delete *tem;
//                            return start + temp;

//                        }
//                    }
//                    template<typename t>
//                      QString toQString(vec2<t> vec){
//                          QString temp = " Vec 2:";
//                          temp.append("\nX: ");
//                          temp.append(vec.x);
//                          temp.append("\nY: ");
//                          temp.append(vec.y);
//                          temp.append("\n");
//                          return temp;
//                      }

//                    template<typename t>
//                      vec3<t> cross(vec3<t> *a, vec3<t> b){
//                        vec3<t> c;
//                        c = new vec3<t>(a->y*b.z, (a->x*b.z) - (a->z*b.x), (a->x*b.y) - (a->y*b.x));
//                        return c;
//                    }

//                    template <typename t>
//                      vec3<t> create_vec3(t x, t y, t z)
//                    {
//                        vec3<t> temp;
//                        temp.x = x;
//                        temp.y = y;
//                        temp.z = z;
//                        return temp;
//                    }



//                    template<typename t>
//                      vec4<t> add(vec4<t> *a, vec4<t> b){
//                        vec4<t> c;
//                        c.x = a->x + b.x;
//                        c.y = a->y + b.y;
//                        c.z = a->z + b.z;
//                        c.w = a->w + b.w;
//                        return c;
//                    }
//                    template<typename t>
//                      vec4<t> subtract(vec4<t> *a, vec4<t> b){
//                        vec4<t> c;
//                        c.x = a->x - b.x;
//                        c.y = a->y - b.y;
//                        c.z = a->z - b.z;
//                        c.w = a->w - b.w;
//                        return c;
//                    }
//                    template<typename t>
//                      vec4<t> multiply(vec4<t> *a, vec4<t> b){
//                        vec4<t> c;
//                        c.x = a->x * b.x;
//                        c.y = a->y * b.y;
//                        c.z = a->z * b.z;
//                        c.w = a->w * b.w;
//                        return c;
//                    }
//                    template<typename t>
//                      vec4<t> divide(vec4<t> *a, vec4<t> b){
//                        vec4<t> c;
//                        c.x = a->x / b.x;
//                        c.y = a->y / b.y;
//                        c.z = a->z / b.z;
//                        c.w = a->w / b.w;
//                        return c;
//                    }

//                    template <typename t>
//                      vec4<t> cross(vec2<t>* a, vec2<t> b)
//                    {
//                        //TODO REIMPLEMENT
//                        return;
//                    }

//                    template<typename t>
//                      vec4<t> Slerp(vec4<t> start, vec4<t> end, float percent){

//                        //TODO REIMPLEMENT
//                        return;
//                    }
//                    template <typename t>
//                      vec4<t> create_vec4(t x, t y, t z, t w)
//                    {
//                        vec4<t> temp;
//                        temp.x = x;
//                        temp.y = y;
//                        temp.z = z;
//                        temp.w = w;
//                        return temp;
//                    }

//                    template<typename t>
//                      mat4<t> add(mat4<t> *a, mat4<t> b){
//                        mat4<t> c;
//                        for (int i = 0; i < 16; i++){
//                            c.mat4.element[i] = a->element[i] + b.element[i];
//                        }
//                        return c;
//                    }
//                    template<typename t>
//                      mat4<t> subtract(mat4<t> *a, mat4<t> b){
//                        mat4<t> c;
//                        for (int i = 0; i < 16; i++){
//                            c.mat4.element[i] = a->element[i] - b.element[i];
//                        }
//                        return c;
//                    }
//                    template<typename t>
//                      mat4<t> multiply(mat4<t> *a, mat4<t> b){
//                        mat4<t> c;
//                        for (int i = 0; i < 16; i++){
//                            c.mat4.element[i] = a->element[i] * b.element[i];
//                        }
//                        return c;
//                    }
//                    template<typename t>
//                      mat4<t> divide(mat4<t> *a, mat4<t> b){
//                        mat4<t> c;
//                        for (int i = 0; i < 16; i++){
//                            c.mat4.element[i] = a->element[i] / b.element[i];
//                        }
//                        return c;
//                    }


//                     template<typename t>
//                      mat4<t>& invert(mat4<t> &mat4)   {
//                        double temp[16];

//                        temp[0] = mat4.element[5] * mat4.element[10] * mat4.element[15] -
//                            mat4.element[5] * mat4.element[11] * mat4.element[14] -
//                            mat4.element[9] * mat4.element[6] * mat4.element[15] +
//                            mat4.element[9] * mat4.element[7] * mat4.element[14] +
//                            mat4.element[13] * mat4.element[6] * mat4.element[11] -
//                            mat4.element[13] * mat4.element[7] * mat4.element[10];

//                        temp[4] = -mat4.element[4] * mat4.element[10] * mat4.element[15] +
//                            mat4.element[4] * mat4.element[11] * mat4.element[14] +
//                            mat4.element[8] * mat4.element[6] * mat4.element[15] -
//                            mat4.element[8] * mat4.element[7] * mat4.element[14] -
//                            mat4.element[12] * mat4.element[6] * mat4.element[11] +
//                            mat4.element[12] * mat4.element[7] * mat4.element[10];

//                        temp[8] = mat4.element[4] * mat4.element[9] * mat4.element[15] -
//                            mat4.element[4] * mat4.element[11] * mat4.element[13] -
//                            mat4.element[8] * mat4.element[5] * mat4.element[15] +
//                            mat4.element[8] * mat4.element[7] * mat4.element[13] +
//                            mat4.element[12] * mat4.element[5] * mat4.element[11] -
//                            mat4.element[12] * mat4.element[7] * mat4.element[9];

//                        temp[12] = -mat4.element[4] * mat4.element[9] * mat4.element[14] +
//                            mat4.element[4] * mat4.element[10] * mat4.element[13] +
//                            mat4.element[8] * mat4.element[5] * mat4.element[14] -
//                            mat4.element[8] * mat4.element[6] * mat4.element[13] -
//                            mat4.element[12] * mat4.element[5] * mat4.element[10] +
//                            mat4.element[12] * mat4.element[6] * mat4.element[9];

//                        temp[1] = -mat4.element[1] * mat4.element[10] * mat4.element[15] +
//                            mat4.element[1] * mat4.element[11] * mat4.element[14] +
//                            mat4.element[9] * mat4.element[2] * mat4.element[15] -
//                            mat4.element[9] * mat4.element[3] * mat4.element[14] -
//                            mat4.element[13] * mat4.element[2] * mat4.element[11] +
//                            mat4.element[13] * mat4.element[3] * mat4.element[10];

//                        temp[5] = mat4.element[0] * mat4.element[10] * mat4.element[15] -
//                            mat4.element[0] * mat4.element[11] * mat4.element[14] -
//                            mat4.element[8] * mat4.element[2] * mat4.element[15] +
//                            mat4.element[8] * mat4.element[3] * mat4.element[14] +
//                            mat4.element[12] * mat4.element[2] * mat4.element[11] -
//                            mat4.element[12] * mat4.element[3] * mat4.element[10];

//                        temp[9] = -mat4.element[0] * mat4.element[9] * mat4.element[15] +
//                            mat4.element[0] * mat4.element[11] * mat4.element[13] +
//                            mat4.element[8] * mat4.element[1] * mat4.element[15] -
//                            mat4.element[8] * mat4.element[3] * mat4.element[13] -
//                            mat4.element[12] * mat4.element[1] * mat4.element[11] +
//                            mat4.element[12] * mat4.element[3] * mat4.element[9];

//                        temp[13] = mat4.element[0] * mat4.element[9] * mat4.element[14] -
//                            mat4.element[0] * mat4.element[10] * mat4.element[13] -
//                            mat4.element[8] * mat4.element[1] * mat4.element[14] +
//                            mat4.element[8] * mat4.element[2] * mat4.element[13] +
//                            mat4.element[12] * mat4.element[1] * mat4.element[10] -
//                            mat4.element[12] * mat4.element[2] * mat4.element[9];

//                        temp[2] = mat4.element[1] * mat4.element[6] * mat4.element[15] -
//                            mat4.element[1] * mat4.element[7] * mat4.element[14] -
//                            mat4.element[5] * mat4.element[2] * mat4.element[15] +
//                            mat4.element[5] * mat4.element[3] * mat4.element[14] +
//                            mat4.element[13] * mat4.element[2] * mat4.element[7] -
//                            mat4.element[13] * mat4.element[3] * mat4.element[6];

//                        temp[6] = -mat4.element[0] * mat4.element[6] * mat4.element[15] +
//                            mat4.element[0] * mat4.element[7] * mat4.element[14] +
//                            mat4.element[4] * mat4.element[2] * mat4.element[15] -
//                            mat4.element[4] * mat4.element[3] * mat4.element[14] -
//                            mat4.element[12] * mat4.element[2] * mat4.element[7] +
//                            mat4.element[12] * mat4.element[3] * mat4.element[6];

//                        temp[10] = mat4.element[0] * mat4.element[5] * mat4.element[15] -
//                            mat4.element[0] * mat4.element[7] * mat4.element[13] -
//                            mat4.element[4] * mat4.element[1] * mat4.element[15] +
//                            mat4.element[4] * mat4.element[3] * mat4.element[13] +
//                            mat4.element[12] * mat4.element[1] * mat4.element[7] -
//                            mat4.element[12] * mat4.element[3] * mat4.element[5];

//                        temp[14] = -mat4.element[0] * mat4.element[5] * mat4.element[14] +
//                            mat4.element[0] * mat4.element[6] * mat4.element[13] +
//                            mat4.element[4] * mat4.element[1] * mat4.element[14] -
//                            mat4.element[4] * mat4.element[2] * mat4.element[13] -
//                            mat4.element[12] * mat4.element[1] * mat4.element[6] +
//                            mat4.element[12] * mat4.element[2] * mat4.element[5];

//                        temp[3] = -mat4.element[1] * mat4.element[6] * mat4.element[11] +
//                            mat4.element[1] * mat4.element[7] * mat4.element[10] +
//                            mat4.element[5] * mat4.element[2] * mat4.element[11] -
//                            mat4.element[5] * mat4.element[3] * mat4.element[10] -
//                            mat4.element[9] * mat4.element[2] * mat4.element[7] +
//                            mat4.element[9] * mat4.element[3] * mat4.element[6];

//                        temp[7] = mat4.element[0] * mat4.element[6] * mat4.element[11] -
//                            mat4.element[0] * mat4.element[7] * mat4.element[10] -
//                            mat4.element[4] * mat4.element[2] * mat4.element[11] +
//                            mat4.element[4] * mat4.element[3] * mat4.element[10] +
//                            mat4.element[8] * mat4.element[2] * mat4.element[7] -
//                            mat4.element[8] * mat4.element[3] * mat4.element[6];

//                        temp[11] = -mat4.element[0] * mat4.element[5] * mat4.element[11] +
//                            mat4.element[0] * mat4.element[7] * mat4.element[9] +
//                            mat4.element[4] * mat4.element[1] * mat4.element[11] -
//                            mat4.element[4] * mat4.element[3] * mat4.element[9] -
//                            mat4.element[8] * mat4.element[1] * mat4.element[7] +
//                            mat4.element[8] * mat4.element[3] * mat4.element[5];

//                        temp[15] = mat4.element[0] * mat4.element[5] * mat4.element[10] -
//                            mat4.element[0] * mat4.element[6] * mat4.element[9] -
//                            mat4.element[4] * mat4.element[1] * mat4.element[10] +
//                            mat4.element[4] * mat4.element[2] * mat4.element[9] +
//                            mat4.element[8] * mat4.element[1] * mat4.element[6] -
//                            mat4.element[8] * mat4.element[2] * mat4.element[5];

//                        double determinant = mat4.element[0] * temp[0] + mat4.element[1] * temp[4] + mat4.element[2] * temp[8] + mat4.element[3] * temp[12];
//                        determinant = 1.0 / determinant;

//                        for (int i = 0; i < 4 * 4; i++)
//                            mat4.element[i] = temp[i] * determinant;

//                        return mat4;
//                    }

//                       mat4<float> orthographic(float left, float right, float bottom, float top, float near, float far);


//                        mat4<float> perspective(float fov, float aspectRatio, float near, float far);



//                    template<typename t>
//                       mat4<t> translation(vec3<t>& translation)
//                    {
//                        mat4<t> result(1);

//                        result.elements[0 + 3 * 4] = translation.getX();
//                        result.elements[1 + 3 * 4] = translation.getY();
//                        result.elements[2 + 3 * 4] = translation.getZ();

//                        return result;
//                    }

//                    template<typename t>
//                      mat4<t> rotation(float angle, vec3<t>& axis)
//                    {
//                        mat4<t> result(1);

//                        float r = toRadians(angle);
//                        float c = cos(r);
//                        float s = sin(r);
//                        float omc = 1 - c;

//                        float x = axis.getX();
//                        float y = axis.getY();
//                        float z = axis.getZ();

//                        result.elements[0 + 0 * 4] = x * omc + c;
//                        result.elements[1 + 0 * 4] = y * x * omc + z * s;
//                        result.elements[2 + 0 * 4] = x * z * omc - y * s;

//                        result.elements[0 + 1 * 4] = x * y * omc - z * s;
//                        result.elements[1 + 1 * 4] = y * omc + c;
//                        result.elements[2 + 1 * 4] = y * z * omc + x * s;

//                        result.elements[0 + 2 * 4] = x * z * omc + y * s;
//                        result.elements[1 + 2 * 4] = y * z * omc - x * s;
//                        result.elements[2 + 2 * 4] = z * omc + c;

//                        return result;
//                    }
//                    template<typename t>
//                   mat4<t> scale(vec3<t>& scale)
//                    {
//                        mat4<t> result(1);

//                        result.elements[0 + 0 * 4] = scale.getX();
//                        result.elements[1 + 1 * 4] = scale.getY();
//                        result.elements[2 + 2 * 4] = scale.getZ();

//                        return result;
//                    }




		}

}



#endif // end math functions
