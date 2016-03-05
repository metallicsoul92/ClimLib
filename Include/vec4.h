#ifndef VEC4
#define VEC4
namespace clim{
    namespace math{

    template<typename T>
    struct vec4{

    public:
        vec4() {}
        vec4(const T &x,const T &y, const T &z, const T &w){
            this->m_x = x;
            this->m_y = y;
            this->m_z = z;
            this->m_w = w;
        }

        vec4(const vec4<T> &other){
            this->m_x = other.getX();
            this->m_y = other.getY();
            this->m_z = other.getZ();
            this->m_w = other.getW();
        }


        vec4<T>& add(vec4<T> &other){
            m_x += other.getX();
            m_y += other.getY();
            m_z += other.getZ();
            m_w += other.getW();
            return *this;
        }
        vec4<T>& sub(vec4<T> &other){
            m_x -= other.getX();
            m_y -= other.getY();
            m_z -= other.getZ();
            m_w -= other.getW();

            return *this;
        }
        vec4<T>& mul(vec4<T> &other){
            m_x *= other.getX();
            m_y *= other.getY();
            m_z *= other.getZ();
            m_w *= other.getW();

            return *this;
        }
        vec4<T>& div(vec4<T> &other){
            m_x /= other.getX();
            m_y /= other.getY();
            m_z /= other.getZ();
            m_w /= other.getW();

            return *this;
        }

        friend vec4<T> operator+(vec4<T> left, vec4<T> right){
            return left.add(right);
        }

        friend vec4<T> operator-(vec4<T> left, vec4<T> right){
            return left.sub(right);
        }

        friend vec4<T> operator*(vec4<T> left, vec4<T> right){
            return left.mul(right);
        }

        friend vec4<T> operator/(vec4<T> left, vec4<T> right){
            return left.div(right);
        }

        friend bool operator==(vec4<T> left,vec4<T> right){
            if(left.getX() == right.getX() && left.getY() == right.getY() && left.getZ() == right.getZ() && left.getW() == right.getW())
                return true;

            return false;
        }

        friend bool operator!=(vec4<T> left,vec4<T> right){
            if(left.getX() == right.getX() && left.getY() == right.getY() && left.getZ() == right.getZ() && left.getW() == right.getW())
                return false;

            return true;
        }

        //Conversions
        const char* toCString(){
            char* temp;
            temp = "X: " + m_x + "\n";
            temp += "Y: " +m_y + "\n";
            temp += "Z: " + m_z + "\n";
            temp += "W: " + m_w + "\n";
            return temp;
        }

        //Getters
        T getX()const{return m_x;}
        T getY()const{return m_y;}
        T getZ()const{return m_z;}
        T getW()const{return m_w;}

        T& X(){return m_x;}
        T& Y(){return m_y;}
        T& Z(){return m_z;}
        T& W(){return m_w;}

    private:
        T m_x;
        T m_y;
        T m_z;
        T m_w;
    };

    }
}

#endif // VEC4

