#ifndef VEC3
#define VEC3
#include <math.h>

namespace clim{
    namespace math{

    template<typename T>
    struct vec3{

    public:
        //constructors
        vec3();
        vec3(const T &x,const T &y, const T &z);
        vec3(const vec3<T> &other);

        //destructor
        ~vec3(){

        }

        //math functions
        vec3<T>& add(vec3<T> &other);
        vec3<T>& sub(vec3<T> &other);
        vec3<T>& mul(vec3<T> &other);
        vec3<T>& div(vec3<T> &other);
       static vec3<T>& Lerp(const vec3<T> &start, const vec3<T> &end, float percent);

       float Magnitude()const;
       float getMagnitude();

       vec3<T>& normalize();

        //Overloads
       vec3<T> operator+(vec3<T> right);
       vec3<T> operator-(vec3<T> right);
       vec3<T> operator*(vec3<T> right);
       vec3<T> operator/(vec3<T> right);
       bool operator==(vec3<T> right);
       bool operator!=(vec3<T> right);

        //Conversions
        const char* toCString();

        //setters
        void setX(const T& x);
        void setY(const T& y);
        void setZ(const T& z);

        //getters;
        T getX()const;
        T getY()const;
        T getZ()const;

        T& X();
        T& Y();
        T& Z();
    private:
        T m_x;
        T m_y;
        T m_z;

    };

    }
}

#include "vec3.tcc"

#endif // VEC3

