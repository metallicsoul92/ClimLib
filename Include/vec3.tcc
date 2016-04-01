#include "vec3.h"


namespace clim{
namespace math{

template<typename T>
vec3<T>::vec3() {}

template<typename T>
vec3<T>::vec3(const T &x, const T &y, const T &z){
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
}
template<typename T>
vec3<T>::vec3(const vec3<T> &other){
    this->m_x = other.getX();
    this->m_y = other.getY();
    this->m_z = other.getZ();
}
template<typename T>
vec3<T> &vec3<T>::add(vec3<T> &other){
    m_x += other.getX();
    m_y += other.getY();
    m_z += other.getZ();
    return *this;
}
template<typename T>
vec3<T> &vec3<T>::sub(vec3<T> &other){
    m_x -= other.getX();
    m_y -= other.getY();
    m_z -= other.getZ();
    return *this;
}
template<typename T>
vec3<T> &vec3<T>::mul(vec3<T> &other){
    m_x *= other.getX();
    m_y *= other.getY();
    m_z *= other.getZ();
    return *this;
}
template<typename T>
vec3<T> &vec3<T>::div(vec3<T> &other){
    m_x /= other.getX();
    m_y /= other.getY();
    m_z /= other.getZ();

    return *this;
}
template<typename T>
vec3<T> &vec3<T>::Lerp(const vec3<T> &start, const vec3<T> &end, float percent)  {
    vec3<T> temp = end.sub(start);
    vec3<T> tem = vec3<T>(percent / 100.0f, percent / 100.0f, percent / 100.0f);
    temp.mul(tem);

    return start + temp;

}

template<typename T>
float vec3<T>::Magnitude() const{
 return sqrt((m_x*m_y)+(m_x*m_y)+(m_z*m_z));
}
template<typename T>
float vec3<T>::getMagnitude(){ return sqrt((m_x*m_y)+(m_x*m_y)+(m_z*m_z));}
template<typename T>
vec3<T> &vec3<T>::normalize(){
    setX(m_x/getMagnitude());
    setY(m_y/getMagnitude());
    setZ(m_z/getMagnitude());
    return this;
}
template<typename T>
const char *vec3<T>::toCString(){
    char* temp;
    temp = "X: " + m_x + "\n";
    temp += "Y: " +m_y + "\n";
    temp += "Z: " + m_z + "\n";
    return temp;
}
template<typename T>
void vec3<T>::setX(const T& x)
{
    m_x = x;
}

template<typename T>
void vec3<T>::setY(const T &y)
{
    m_y = y;
}
template<typename T>
void vec3<T>::setZ(const T& z){
    m_z = z;
}

template<typename T>
T vec3<T>::getX() const{return m_x;}
template<typename T>
T vec3<T>::getY() const{return m_y;}
template<typename T>
T vec3<T>::getZ() const{return m_z;}
template<typename T>
T &vec3<T>::X(){return m_x;}
template<typename T>
T &vec3<T>::Y(){return m_y;}
template<typename T>
T &vec3<T>::Z(){return m_z;}
template<typename T>
bool vec3<T>::operator!=(vec3<T> right){
    if(getX() == right.getX() && getY() == right.getY() && getZ())
        return false;

    return true;
}
template<typename T>
bool vec3<T>::operator==(vec3<T> right){
    if(getX() == right.getX() && getY() == right.getY()&& getZ())
        return true;

    return false;
}
template<typename T>
vec3<T> vec3<T>::operator/(vec3<T> right){
    return div(right);
}
template<typename T>
vec3<T> vec3<T>::operator*(vec3<T> right){
    return mul(right);
}
template<typename T>
vec3<T> vec3<T>::operator-(vec3<T> right){
    return sub(right);
}
template<typename T>
vec3<T> vec3<T>::operator+(vec3<T> right){
    return add(right);
}



}
}
