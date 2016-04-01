

using namespace clim::math;

template<typename T>
mat4<T>::mat4(const mat4<T> &other) {

    for(int i = 0;i< 16; i++){
        m_elements[i] = other.getElement(i);
    }
}
template<typename T>
mat4<T>::mat4(const T &t){
    m_elements[0 + 0 * 4] = t;
    m_elements[1 + 1 * 4] = t;
    m_elements[2 + 2 * 4 ] = t;
    m_elements[3 + 3 * 4 ] = t;
}

template<typename T>
T mat4<T>::getElement(int index) const{
    return m_elements[index];
}
template<typename T>
void mat4<T>::setElement(int index, const T &other){
    m_elements[index] = other;
}

template<typename T>
mat4<T> &mat4<T>::add(mat4<T> &other){
    for(int x = 0; x < 16; x++){
        this->m_elements[x] += other.getElement(x);
    }
    return *this;
}
template<typename T>
mat4<T> &mat4<T>::sub(mat4<T> &other){
    for(int x = 0; x < 16; x++){
        this->m_elements[x] -= other.getElement(x);
    }
    return *this;
}
template<typename T>
mat4<T> &mat4<T>::mul(const vec4<T> &other){
    //TODO: Figure out how to do this easier
    this->m_elements[0] *= other.getX();
    this->m_elements[1] *= other.getY();
    this->m_elements[2] *= other.getZ();
    this->m_elements[3] *= other.getW();
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
template<typename T>
mat4<T> &mat4<T>::div(mat4<T> &other){
    for(int x = 0; x < 16; x++){
        this->m_elements[x] /= other.getElement(x);
    }
    return *this;
}
template<typename T>
mat4<T> &mat4<T>::invert(mat4<T> &mat4){
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
bool mat4<T>::operator==(mat4<T> right){

    return getElement(0) == right.getElement(0) && getElement(1) == right.getElement(1) && getElement(2) == right.getElement(2) &&
            getElement(3) == right.getElement(3) && getElement(4) == right.getElement(4) && getElement(5) == right.getElement(5) &&
            getElement(6) == right.getElement(6) && getElement(7) == right.getElement(7) && getElement(8) == right.getElement(8) &&
            getElement(9) == right.getElement(9) && getElement(10) == right.getElement(10) && getElement(11) == right.getElement(11) &&
            getElement(12) == right.getElement(12) && getElement(13) == right.getElement(13) && getElement(14) == right.getElement(14) && getElement(15) == right.getElement(15);
}

template<typename T>
mat4<T> mat4<T>::operator/(mat4<T> right){
    return div(right);
}

template<typename T>
mat4<T> mat4<T>::operator*(mat4<T> &right){
    return mul(right);
}

template<typename T>
mat4<T> mat4<T>::operator-(mat4<T> right){
    return sub(right);
}

template<typename T>
mat4<T> mat4<T>::operator+(mat4<T> right){
    return add(right);
}

template<typename T>
mat4<T> mat4<T>::translation(vec3<T> &translation)
{
    mat4<T> result(1);

    result.setElement((0+3*4),translation.getX());
    result.setElement((1+3*4),translation.getY());
    result.setElement((2+3*4),translation.getZ());

    return result;
}

template<typename T>
mat4<float> mat4<T>::rotation(float angle, vec3<float> axis)
{
    mat4<float> result(1);

    float r = angle * (M_PI/180);
    //float r = math::toRadians(angle);
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
mat4<T> mat4<T>::scale(vec3<T> &scale)
{
    mat4<T> result(1);

    result.setElement(0+0*4,scale.getX());
    result.setElement(1+1*4,scale.getY());
    result.setElement(2+2*4,scale.getZ());


    return result;
}

template<typename T>
const char *mat4<T>::toCString(){

    //char* temp;
    std::string temp;
    temp = "[ ";
    for(int i = 0; i < 16; i++){
        temp += m_elements[i] + " , ";
    }
    temp += "]\n";
    return temp;
}

