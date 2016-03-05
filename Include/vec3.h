#ifndef VEC3
#define VEC3


namespace clim{
    namespace math{

    template<typename T>
    struct vec3{

    public:
        //constructors
        vec3() {}
        vec3(const T &x,const T &y, const T &z){
            this->m_x = x;
            this->m_y = y;
            this->m_z = z;
        }
        vec3(const vec3<T> &other){
            this->m_x = other.getX();
            this->m_y = other.getY();
            this->m_z = other.getZ();
        }
        //math functions
        vec3<T>& add(vec3<T> &other){
            m_x += other.getX();
            m_y += other.getY();
            m_z += other.getZ();
            return *this;
        }
        vec3<T>& sub(vec3<T> &other){
            m_x -= other.getX();
            m_y -= other.getY();
            m_z -= other.getZ();
            return *this;
        }
        vec3<T>& mul(vec3<T> &other){
            m_x *= other.getX();
            m_y *= other.getY();
            m_z *= other.getZ();
            return *this;
        }
        vec3<T>& div(vec3<T> &other){
            m_x /= other.getX();
            m_y /= other.getY();
            m_z /= other.getZ();

            return *this;
        }
       static vec3<T>& Lerp(const vec3<T> &start, const vec3<T> &end, float percent)  {
          vec3<T> temp = end.sub(start);
           vec3<T> tem = vec3<T>(percent / 100.0f, percent / 100.0f, percent / 100.0f);
          temp.mul(tem);

           return start + temp;

       }

        //Overloads
        friend vec3<T> operator+(vec3<T> left, vec3<T> right){
            return left.add(right);
        }
        friend vec3<T> operator-(vec3<T> left, vec3<T> right){
            return left.sub(right);
        }
        friend vec3<T> operator*(vec3<T> left, vec3<T> right){
            return left.mul(right);
        }
        friend vec3<T> operator/(vec3<T> left, vec3<T> right){
            return left.div(right);
        }
        friend bool operator==(vec3<T> left,vec3<T> right){
            if(left.getX() == right.getX() && left.getY() == right.getY()&& left.getZ())
                return true;

            return false;
        }
        friend bool operator!=(vec3<T> left,vec3<T> right){
            if(left.getX() == right.getX() && left.getY() == right.getY() && left.getZ())
                return false;

            return true;
        }

        //Conversions
        const char* toCString(){
            char* temp;
            temp = "X: " + m_x + "\n";
            temp += "Y: " +m_y + "\n";
            temp += "Z: " + m_z + "\n";
            return temp;
        }


        //getters;
        T getX()const{return m_x;}
        T getY()const{return m_y;}
        T getZ()const{return m_z;}

        T& X(){return m_x;}
        T& Y(){return m_y;}
        T& Z(){return m_z;}
    private:
        T m_x;
        T m_y;
        T m_z;

    };

    }
}



#endif // VEC3

