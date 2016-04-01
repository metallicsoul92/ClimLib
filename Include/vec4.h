#ifndef VEC4
#define VEC4
namespace clim{
    namespace math{

    template<typename T>
    struct vec4{

    public:

        //constructors
        vec4() {}
        vec4(const T &x,const T &y, const T &z, const T &w);

        vec4(const vec4<T> &other);

        //destructor
        ~vec4(){

        }


        vec4<T>& add(vec4<T> &other);
        vec4<T>& sub(vec4<T> &other);
        vec4<T>& mul(vec4<T> &other);
        vec4<T>& div(vec4<T> &other);

        vec4<T> operator+(vec4<T> right);

        vec4<T> operator-(vec4<T> right);

        vec4<T> operator*(vec4<T> right);

        vec4<T> operator/(vec4<T> right);

        bool operator==(vec4<T> right);

        bool operator!=(vec4<T> right);

        //Conversions
        const char* toCString();

        //Getters
        T getX()const;
        T getY()const;
        T getZ()const;
        T getW()const;

        T& X();
        T& Y();
        T& Z();
        T& W();

    private:
        T m_x;
        T m_y;
        T m_z;
        T m_w;
    };

    }
}
#include "vec4.tcc"
#endif // VEC4

