#ifndef VEC2
#define VEC2

#include <string>

namespace clim{
    namespace math{

    template<typename T>
    struct vec2{

    public:
        vec2();
        vec2(const T &x,const T &y);
        vec2(const vec2<T> &other);
        //destructor
        ~vec2(){

        }


        vec2<T>& add(const vec2<T> &other);
        vec2<T>& sub(const vec2<T> &other);
        vec2<T>& mul(const vec2<T> &other);
        vec2<T>& div(const vec2<T> &other);
        vec2<T>& cross(const vec2<T> &other);


    std::string ToString();

        vec2<T> operator+(vec2<T> right);

        vec2<T> operator-(vec2<T> right);

        vec2<T> operator*(vec2<T> right);

        vec2<T> operator/(vec2<T> right);

        bool operator==(vec2<T> right);

        bool operator!=(vec2<T> right);


        void setX(T x);
        void setY(T y);

        T getX()const;
        T getY()const;

        T& X();
        T& Y();
    private:
        T m_x;
        T m_y;


    };

    }
}

#include "vec2.tcc"

#endif // VEC2

