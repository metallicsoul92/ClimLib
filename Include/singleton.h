#ifndef SINGLETON_H
#define SINGLETON_H


namespace clim{

    /*
     * The Singleton class acts more as an interface to objects that are only suppose
     */
    template<typename T>
    class singleton: public QObject{

    protected:

        //The actual instance of the class
        static T* m_instance;

    public:
        //Function to call instance
        static T* instance(){
            if(!m_instance){
                m_instance = new T;
            }
            return m_instance;
        }
    };

}



#endif // SINGLETON_H
