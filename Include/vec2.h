#ifndef VEC2
#define VEC2


namespace clim{
    namespace math{

    template<typename T>
    struct vec2{

    public:
        vec2() {}
        vec2(const T &x,const T &y){
            this->m_x = x;
            this->m_y = y;
        }

        vec2(const vec2<T> &other){
            this->m_x = other.getX();
            this->m_y = other.getY();
        }


        vec2<T>& add(const vec2<T> &other){
            m_x += other.getX();
            m_y += other.getY();

            return *this;
        }
        vec2<T>& sub(const vec2<T> &other){
            m_x -= other.getX();
            m_y -= other.getY();

            return *this;
        }
        vec2<T>& mul(const vec2<T> &other){
            m_x *= other.getX();
            m_y *= other.getY();

            return *this;
        }
        vec2<T>& div(const vec2<T> &other){
            m_x /= other.getX();
            m_y /= other.getY();

            return *this;
        }
        vec2<T>& cross(const vec2<T> &other){
            m_x *= other.getY();
            m_y *= -(other.getX());

            return *this;
        }

        const char* toCString(){
            char* temp;
            temp = "X: " + m_x + "\n";
            temp += "Y: " +m_y + "\n";
            return temp;
        }

        friend vec2<T> operator+(vec2<T> left, vec2<T> right){
            return left.add(right);
        }

        friend vec2<T> operator-(vec2<T> left, vec2<T> right){
            return left.sub(right);
        }

        friend vec2<T> operator*(vec2<T> left, vec2<T> right){
            return left.mul(right);
        }

        friend vec2<T> operator/(vec2<T> left, vec2<T> right){
            return left.div(right);
        }

        friend bool operator==(vec2<T> left,vec2<T> right){
            if(left.getX() == right.getX() && left.getY() == right.getY())
                return true;

            return false;
        }

        friend bool operator!=(vec2<T> left,vec2<T> right){
            if(left.getX() == right.getX() && left.getY() == right.getY())
                return false;

            return true;
        }


        void setX(T x){ m_x = x;}
        void setY(T y){ m_y = y;}

        T getX()const{return m_x;}
        T getY()const{return m_y;}

        T& X(){return m_x;}
        T& Y(){return m_y;}
    private:
        T m_x;
        T m_y;


    };

    }
}


#endif // VEC2

