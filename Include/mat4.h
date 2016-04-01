#ifndef MAT4
#define MAT4

#include "MathTypes.h"
#include <GL/gl.h>
#include <string>
#include <iostream>
namespace clim{
namespace math{

template<typename T>
struct mat4{

public:
    //Constructors
    mat4(){
    }

    mat4(const mat4<T>  &other);
    mat4(const T& t);

    //Deconstructor
    ~mat4(){

    }

    // Getters
    T getElement(int index)const;


    //Setters
    void setElement(int index, const T &other);

    //Math Functions
    mat4<T>& add(mat4<T> &other);
    mat4<T>& sub(mat4<T> &other);
    mat4<T>& mul(const mat4<T> &other){
        for(int x = 0; x < 16; x++){
            this->m_elements[x] *= other.getElement(x);
        }
        return *this;
    }
    mat4<T>& mul(const vec4<T> &other);


    mat4<T>& div(mat4<T> &other);


    //Operator Overloads
    mat4<T> operator+(mat4<T> right);
    mat4<T> operator-(mat4<T> right);
    mat4<T> operator*(mat4<T>& right);
    mat4<T> operator/(mat4<T> right);
    bool operator==(mat4<T> right);


    //Inverting
    mat4<T>& invert(mat4<T> &mat4);


    //float only functions
    mat4<float> orthographic(float left, float right, float bottom, float top, float onear, float ofar);
    mat4<float> perspective(float fov, float aspectRatio, float pnear, float pfar);
    mat4<float> identity();

    //Graphics Based Functions
    mat4<T> translation(vec3<T>& translation);
    mat4<float> rotation(float angle, vec3<float> axis);
    mat4<T> scale(vec3<T>& scale);

    //Conversions
    const char* toCString();

private:
    T m_elements[16];

};

  GLfloat *toFloat(mat4<float> &matrix);

}
}

#include "mat4.tcc"


#endif // MAT4

