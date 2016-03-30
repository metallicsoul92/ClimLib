#include "mat4.h"


namespace clim{
namespace math{

template<typename T>
mat4::mat4(const mat4<clim::math::T> &other) {

    for(int i = 0;i< 16; i++){
        m_elements[i] = other.getElement(i);
    }
}

mat4::mat4(const clim::math::T &t){
    m_elements[0 + 0 * 4] = t;
    m_elements[1 + 1 * 4] = t;
    m_elements[2 + 2 * 4 ] = t;
    m_elements[3 + 3 * 4 ] = t;
}

clim::math::T mat4::getElement(int index) const{
    return m_elements[index];
}

void mat4::setElement(int index, const clim::math::T &other)
{m_elements[index] = other;}

mat4<clim::math::T> &mat4::add(mat4<clim::math::T> &other){
    for(int x = 0; x < 16; x++){
        this->m_elements[x] += other.getElement(x);
    }
    return *this;
}

mat4<clim::math::T> &mat4::sub(mat4<clim::math::T> &other){
    for(int x = 0; x < 16; x++){
        this->m_elements[x] -= other.getElement(x);
    }
    return *this;
}

mat4<T> &mat4::mul(const vec4<clim::math::T> &other){
    //TODO: Figure out how to do this easier
    this->m_elements[0] *= other.X();
    this->m_elements[1] *= other.Y();
    this->m_elements[2] *= other.Z();
    this->m_elements[3] *= other.W();
    this->m_elements[4] *= other.X();
    this->m_elements[5] *= other.Y();
    this->m_elements[6] *= other.Z();
    this->m_elements[7] *= other.W();
    this->m_elements[8] *= other.X();
    this->m_elements[9] *= other.Y();
    this->m_elements[10] *= other.Z();
    this->m_elements[11] *= other.W();
    this->m_elements[12] *= other.X();
    this->m_elements[13] *= other.Y();
    this->m_elements[14] *= other.Z();
    this->m_elements[15] *= other.W();

    return *this;
}

mat4<clim::math::T> &mat4::div(mat4<clim::math::T> &other){
    for(int x = 0; x < 16; x++){
        this->m_elements[x] /= other.getElement(x);
    }
    return *this;
}

mat4<clim::math::T> &mat4::invert(mat4<clim::math::T> &mat4){
    {
        T temp[16];

        temp[0] = mat4.getElement(5) *  mat4.getElement(10) *  mat4.getElement(15) -
                mat4.getElement(5) *  mat4.getElement(11) *  mat4.getElement(14) -
                mat4.getElement(9) *  mat4.getElement(6) *  mat4.getElement(15) +
                mat4.getElement(9) *  mat4.getElement(7) *  mat4.getElement(14) +
                mat4.getElement(13) *  mat4.getElement(6) *  mat4.getElement(11) -
                mat4.getElement(13) *  mat4.getElement(7) *  mat4.getElement(10);

        temp[4] = -mat4.getElement(4) *  mat4.getElement(10) *  mat4.getElement(15) +
                mat4.getElement(4) *  mat4.getElement(11) *  mat4.getElement(14) +
                mat4.getElement(8) *  mat4.getElement(6) *  mat4.getElement(15) -
                mat4.getElement(8) *  mat4.getElement(7) *  mat4.getElement(14) -
                mat4.getElement(12) *  mat4.getElement(6) *  mat4.getElement(11) +
                mat4.getElement(12) *  mat4.getElement(7) *  mat4.getElement(10);

        temp[8] = mat4.getElement(4) *  mat4.getElement(9) *  mat4.getElement(15) -
                mat4.getElement(4) *  mat4.getElement(11) *  mat4.getElement(13) -
                mat4.getElement(8) *  mat4.getElement(5) *  mat4.getElement(15) +
                mat4.getElement(8) *  mat4.getElement(7) *  mat4.getElement(13) +
                mat4.getElement(12) *  mat4.getElement(5) *  mat4.getElement(11) -
                mat4.getElement(12) *  mat4.getElement(7) *  mat4.getElement(9);

        temp[12] = -mat4.getElement(4) *  mat4.getElement(9) *  mat4.getElement(14) +
                mat4.getElement(4) *  mat4.getElement(10) *  mat4.getElement(13) +
                mat4.getElement(8) *  mat4.getElement(5) *  mat4.getElement(14) -
                mat4.getElement(8) *  mat4.getElement(6) *  mat4.getElement(13) -
                mat4.getElement(12) *  mat4.getElement(5) *  mat4.getElement(10) +
                mat4.getElement(12) *  mat4.getElement(6) *  mat4.getElement(9);

        temp[1] = -mat4.getElement(1) *  mat4.getElement(10) *  mat4.getElement(15) +
                mat4.getElement(1) *  mat4.getElement(11) *  mat4.getElement(14) +
                mat4.getElement(9) *  mat4.getElement(2) *  mat4.getElement(15) -
                mat4.getElement(9) *  mat4.getElement(3) *  mat4.getElement(14) -
                mat4.getElement(13) *  mat4.getElement(2) *  mat4.getElement(11) +
                mat4.getElement(13) *  mat4.getElement(3) *  mat4.getElement(10);

        temp[5] = mat4.getElement(0) *  mat4.getElement(10) *  mat4.getElement(15) -
                mat4.getElement(0) *  mat4.getElement(11) *  mat4.getElement(14) -
                mat4.getElement(8) *  mat4.getElement(2) *  mat4.getElement(15) +
                mat4.getElement(8) *  mat4.getElement(3) *  mat4.getElement(14) +
                mat4.getElement(12) *  mat4.getElement(2) *  mat4.getElement(11) -
                mat4.getElement(12) *  mat4.getElement(3) *  mat4.getElement(10);

        temp[9] = -mat4.getElement(0) *  mat4.getElement(9) *  mat4.getElement(15) +
                mat4.getElement(0) *  mat4.getElement(11) *  mat4.getElement(13) +
                mat4.getElement(8) *  mat4.getElement(1) *  mat4.getElement(15) -
                mat4.getElement(8) *  mat4.getElement(3) *  mat4.getElement(13) -
                mat4.getElement(12) *  mat4.getElement(1) *  mat4.getElement(11) +
                mat4.getElement(12) *  mat4.getElement(3) *  mat4.getElement(9);

        temp[13] = mat4.getElement(0) *  mat4.getElement(9) *  mat4.getElement(14) -
                mat4.getElement(0) *  mat4.getElement(10) *  mat4.getElement(13) -
                mat4.getElement(8) *  mat4.getElement(1) *  mat4.getElement(14) +
                mat4.getElement(8) *  mat4.getElement(2) *  mat4.getElement(13) +
                mat4.getElement(12) *  mat4.getElement(1) *  mat4.getElement(10) -
                mat4.getElement(12) *  mat4.getElement(2) *  mat4.getElement(9);

        temp[2] = mat4.getElement(1) *  mat4.getElement(6) *  mat4.getElement(15) -
                mat4.getElement(1) *  mat4.getElement(7) *  mat4.getElement(14) -
                mat4.getElement(5) *  mat4.getElement(2) *  mat4.getElement(15) +
                mat4.getElement(5) *  mat4.getElement(3) *  mat4.getElement(14) +
                mat4.getElement(13) *  mat4.getElement(2) *  mat4.getElement(7) -
                mat4.getElement(13) *  mat4.getElement(3) *  mat4.getElement(6);

        temp[6] = -mat4.getElement(0) *  mat4.getElement(6) *  mat4.getElement(15) +
                mat4.getElement(0) *  mat4.getElement(7) *  mat4.getElement(14) +
                mat4.getElement(4) *  mat4.getElement(2) *  mat4.getElement(15) -
                mat4.getElement(4) *  mat4.getElement(3) *  mat4.getElement(14) -
                mat4.getElement(12) *  mat4.getElement(2) *  mat4.getElement(7) +
                mat4.getElement(12) *  mat4.getElement(3) *  mat4.getElement(6);

        temp[10] = mat4.getElement(0) *  mat4.getElement(5) *  mat4.getElement(15) -
                mat4.getElement(0) *  mat4.getElement(7) *  mat4.getElement(13) -
                mat4.getElement(4) *  mat4.getElement(1) *  mat4.getElement(15) +
                mat4.getElement(4) *  mat4.getElement(3) *  mat4.getElement(13) +
                mat4.getElement(12) *  mat4.getElement(1) *  mat4.getElement(7) -
                mat4.getElement(12) *  mat4.getElement(3) *  mat4.getElement(5);

        temp[14] = -mat4.getElement(0) *  mat4.getElement(5) *  mat4.getElement(14) +
                mat4.getElement(0) *  mat4.getElement(6) *  mat4.getElement(13) +
                mat4.getElement(4) *  mat4.getElement(1) *  mat4.getElement(14) -
                mat4.getElement(4) *  mat4.getElement(2) *  mat4.getElement(13) -
                mat4.getElement(12) *  mat4.getElement(1) *  mat4.getElement(6) +
                mat4.getElement(12) *  mat4.getElement(2) *  mat4.getElement(5);

        temp[3] = -mat4.getElement(1) *  mat4.getElement(6) *  mat4.getElement(11) +
                mat4.getElement(1) *  mat4.getElement(7) *  mat4.getElement(10) +
                mat4.getElement(5) *  mat4.getElement(2) *  mat4.getElement(11) -
                mat4.getElement(5) *  mat4.getElement(3) *  mat4.getElement(10) -
                mat4.getElement(9) *  mat4.getElement(2) *  mat4.getElement(7) +
                mat4.getElement(9) *  mat4.getElement(3) *  mat4.getElement(6);

        temp[7] = mat4.getElement(0) *  mat4.getElement(6) *  mat4.getElement(11) -
                mat4.getElement(0) *  mat4.getElement(7) *  mat4.getElement(10) -
                mat4.getElement(4) *  mat4.getElement(2) *  mat4.getElement(11) +
                mat4.getElement(4) *  mat4.getElement(3) *  mat4.getElement(10) +
                mat4.getElement(8) *  mat4.getElement(2) *  mat4.getElement(7) -
                mat4.getElement(8) *  mat4.getElement(3) *  mat4.getElement(6);

        temp[11] = -mat4.getElement(0) *  mat4.getElement(5) *  mat4.getElement(11) +
                mat4.getElement(0) *  mat4.getElement(7) *  mat4.getElement(9) +
                mat4.getElement(4) *  mat4.getElement(1) *  mat4.getElement(11) -
                mat4.getElement(4) *  mat4.getElement(3) *  mat4.getElement(9) -
                mat4.getElement(8) *  mat4.getElement(1) *  mat4.getElement(7) +
                mat4.getElement(8) *  mat4.getElement(3) *  mat4.getElement(5);

        temp[15] = mat4.getElement(0) *  mat4.getElement(5) *  mat4.getElement(10) -
                mat4.getElement(0) *  mat4.getElement(6) *  mat4.getElement(9) -
                mat4.getElement(4) *  mat4.getElement(1) *  mat4.getElement(10) +
                mat4.getElement(4) *  mat4.getElement(2) *  mat4.getElement(9) +
                mat4.getElement(8) *  mat4.getElement(1) *  mat4.getElement(6) -
                mat4.getElement(8) *  mat4.getElement(2) *  mat4.getElement(5);

        double determinant = mat4.getElement(0) *  temp[0] + mat4.getElement(1) *  temp[4] + mat4.getElement(2) *  temp[8] + mat4.getElement(3) *  temp[12];
        determinant = 1.0 / determinant;

        for (int i = 0; i < 4 * 4; i++)
            mat4.setElement(i,temp[i]*determinant);

        return mat4;
    }
}

template<typename T>
bool clim::math::mat4::operator==(mat4<clim::math::T> left, mat4<clim::math::T> right){

    return left.getElement(0) == right.getElement(0) && left.getElement(1) == right.getElement(1) && left.getElement(2) == right.getElement(2) &&
            left.getElement(3) == right.getElement(3) && left.getElement(4) == right.getElement(4) && left.getElement(5) == right.getElement(5) &&
            left.getElement(6) == right.getElement(6) && left.getElement(7) == right.getElement(7) && left.getElement(8) == right.getElement(8) &&
            left.getElement(9) == right.getElement(9) && left.getElement(10) == right.getElement(10) && left.getElement(11) == right.getElement(11) &&
            left.getElement(12) == right.getElement(12) && left.getElement(13) == right.getElement(13) && left.getElement(14) == right.getElement(14) && left.getElement(15) == right.getElement(15);
}

template<typename T>
mat4<T> clim::math::mat4::operator/(mat4<clim::math::T> left, mat4<clim::math::T> right){
    return left.div(right);
}

template<typename T>
mat4<T> clim::math::mat4::operator*(const mat4<clim::math::T> &left, const mat4<clim::math::T> &right){
    return left.mul(right);
}

template<typename T>
mat4<T> clim::math::mat4::operator-(mat4<clim::math::T> left, mat4<clim::math::T> right){
    return left.sub(right);
}

template<typename T>
mat4<T> clim::math::mat4::operator+(mat4<clim::math::T> left, mat4<clim::math::T> right){
    return left.add(right);
}

template<typename T>
mat4<T> clim::math::mat4::translation(vec3<clim::math::T> &translation)
{
    mat4<T> result(1);

    result.setElement((0+3*4),translation.getX());
    result.setElement((1+3*4),translation.getY());
    result.setElement((2+3*4),translation.getZ());

    return result;
}

template<typename T>
mat4<float> clim::math::mat4::rotation(float angle, vec3<float> axis)
{
    mat4<float> result(1);

    float r = math::toRadians(angle);
    float c = cos(r);
    float s = sin(r);
    float omc = 1 - c;

    float x = axis.getX();
    float y = axis.getY();
    float z = axis.getZ();


    result.setElement(0 + 0 * 4,x*omc+c);
    result.setElement(1 + 0 * 4,y*x*omc+z*s);
    result.setElement(2 + 0 * 4,x*z *omc-y *s);


    result.setElement(0 + 1 * 4, x * y * omc - z * s);
    result.setElement(1 + 1 * 4 ,y * omc + c);
    result.setElement(2 + 1 * 4, y * z * omc + x * s);

    result.setElement(0 + 2 * 4, x * z * omc + y * s);
    result.setElement(1 + 2 * 4 , y * z * omc - x * s);
    result.setElement(2 + 2 * 4 , z * omc + c);

    return result;
}

template<typename T>
mat4<T> clim::math::mat4::scale(vec3<clim::math::T> &scale)
{
    mat4<T> result(1);

    result.setElement(0+0*4,scale.getX());
    result.setElement(1+1*4,scale.getY());
    result.setElement(2+2*4,scale.getZ());


    return result;
}


const char *clim::math::mat4::toCString(){
    char* temp;
    temp = "[ ";
    for(int i = 0; i < 16; i++){
        temp += m_elements[i] + " , ";
    }
    temp += "]\n";
    return temp;
}




}
}
