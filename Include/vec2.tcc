
using namespace clim::math;

template<typename T>
vec2<T>::vec2() {

}
template<typename T>
vec2<T>::vec2(const T &x, const T &y){
    this->m_x = x;
    this->m_y = y;
}
template<typename T>
vec2<T>::vec2(const vec2<T> &other){
    this->m_x = other.getX();
    this->m_y = other.getY();
}
template<typename T>
vec2<T> &vec2<T>::add(const vec2<T> &other){
    m_x += other.getX();
    m_y += other.getY();

    return *this;
}
template<typename T>
vec2<T> &vec2<T>::sub(const vec2<T> &other){
    m_x -= other.getX();
    m_y -= other.getY();

    return *this;
}
template<typename T>
vec2<T> &vec2<T>::mul(const vec2<T> &other){
    m_x *= other.getX();
    m_y *= other.getY();

    return *this;
}
template<typename T>
bool vec2<T>::operator!=(vec2<T> right){
    if(getX() == right.getX() && getY() == right.getY())
        return false;

    return true;
}
template<typename T>
vec2<T> vec2<T>::operator/(vec2<T> right){
    return div(right);
}
template<typename T>
bool vec2<T>::operator==( vec2<T> right){
    if(getX() == right.getX() && getY() == right.getY())
        return true;

    return false;
}
template<typename T>
vec2<T> vec2<T>::operator*(vec2<T> right){
    return mul(right);
}
template<typename T>
vec2<T> vec2<T>::operator-(vec2<T> right){
    return sub(right);
}
template<typename T>
vec2<T> vec2<T>::operator+(vec2<T> right){
    return add(right);
}






template<typename T>
vec2<T>& vec2<T>::div(const vec2<T> &other){
    m_x /= other.getX();
    m_y /= other.getY();

    return *this;
}
template<typename T>
vec2<T>& vec2<T>::cross(const vec2<T> &other){
    m_x *= other.getY();
    m_y *= -(other.getX());

    return *this;
}

template<typename T>
std::string vec2<T>::ToString(){

std::string temp;
temp += "X: ";
temp += std::to_string(m_x);
temp +="\nY: ";
temp += std::to_string(m_y);
temp +="\n";
return temp;

}


template<typename T>
void vec2<T>::setX(T x){ m_x = x;}
template<typename T>
void vec2<T>::setY(T y){ m_y = y;}

template<typename T>
T vec2<T>::getX()const{return m_x;}
template<typename T>
T vec2<T>::getY()const{return m_y;}

template<typename T>
T& vec2<T>::X(){return m_x;}

template<typename T>
T& vec2<T>::Y(){return m_y;}


