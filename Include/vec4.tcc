#include "vec4.h"


namespace clim{
namespace math{

template<typename T>
vec4<T>::vec4(const T &x, const T &y, const T &z, const T &w){
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
    this->m_w = w;
}
template<typename T>
vec4<T>::vec4(const vec4<T> &other){
    this->m_x = other.getX();
    this->m_y = other.getY();
    this->m_z = other.getZ();
    this->m_w = other.getW();
}
template<typename T>
vec4<T> &vec4<T>::add(vec4<T> &other){
    m_x += other.getX();
    m_y += other.getY();
    m_z += other.getZ();
    m_w += other.getW();
    return *this;
}
template<typename T>
vec4<T> &vec4<T>::sub(vec4<T> &other){
    m_x -= other.getX();
    m_y -= other.getY();
    m_z -= other.getZ();
    m_w -= other.getW();

    return *this;
}
template<typename T>
vec4<T> &vec4<T>::mul(vec4<T> &other){
    m_x *= other.getX();
    m_y *= other.getY();
    m_z *= other.getZ();
    m_w *= other.getW();

    return *this;
}
template<typename T>
vec4<T> &vec4<T>::div(vec4<T> &other){
    m_x /= other.getX();
    m_y /= other.getY();
    m_z /= other.getZ();
    m_w /= other.getW();

    return *this;
}
template<typename T>
 vec4<T> vec4<T>::operator+(vec4<T> right){
    return add(right);
}
template<typename T>
 vec4<T> vec4<T>::operator-(vec4<T> right){
    return sub(right);
}
template<typename T>
 vec4<T> vec4<T>::operator*(vec4<T> right){
    return mul(right);
}
template<typename T>
 vec4<T> vec4<T>::operator/(vec4<T> right){
    return div(right);
}
template<typename T>
 bool vec4<T>::operator==(vec4<T> right){
    if(getX() == right.getX() && getY() == right.getY() && getZ() == right.getZ() && getW() == right.getW())
        return true;

    return false;
}
template<typename T>
 bool vec4<T>::operator!=(vec4<T> right){
    if(getX() == right.getX() && getY() == right.getY() && getZ() == right.getZ() && getW() == right.getW())
        return false;

    return true;
}

template<typename T>
const char *vec4<T>::toCString(){
    char* temp;
    temp = "X: " + m_x + "\n";
    temp += "Y: " +m_y + "\n";
    temp += "Z: " + m_z + "\n";
    temp += "W: " + m_w + "\n";
    return temp;
}
template<typename T>
T vec4<T>::getX() const{return m_x;}
template<typename T>
T vec4<T>::getY() const{return m_y;}
template<typename T>
T vec4<T>::getZ() const{return m_z;}
template<typename T>
T vec4<T>::getW() const{return m_w;}
template<typename T>
T &vec4<T>::X(){return m_x;}
template<typename T>
T &vec4<T>::Y(){return m_y;}


template<typename T>
T &vec4<T>::Z(){return m_z;}

template<typename T>
T&vec4<T>::W(){return m_w;}



}
}
