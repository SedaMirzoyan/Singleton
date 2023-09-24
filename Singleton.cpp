
#include <iostream>

class Singleton
{
private:

    static int m_a;
    int m_b = 0;
    static Singleton* m_ptr;

    Singleton()
    {
        std::cout << __func__ << std::endl;
    }

    ~Singleton()
    {
        std::cout << __func__ << std::endl;
    }

    Singleton(const Singleton& ob) = delete;

public:

    static Singleton& createObj()
    {
        if (!m_ptr)
        {
            m_ptr = new Singleton();
        }
        else
        {
            std::cout << "Object can be created only one time\n";
        }

        std::cout << "m_ptr = " << m_ptr << std::endl;
        return *m_ptr;
    }

    static void destroyObj()
    {
        delete m_ptr;
        m_ptr = nullptr;
    }
     

    //get data
    static Singleton& getObj()
    {
        //std::cout << "get " << m_ptr << std::endl;
        return *m_ptr;
    }

    static int getDataA()
    {
        std::cout << "get data (a) " << m_a << std::endl;
        return m_a;
    }

    int getDataB()const 
    {
        std::cout << "get data (b) " << m_b << std::endl;
        return m_b;
    }

    //set data
    static void setDataA(int a)
    {
        std::cout << "set data (a) " << m_a << std::endl;
        m_a = a;
    }

    void setDataB(int b) 
    {
        std::cout << "set data (b) " << m_b << std::endl;
        m_b = b;        
    }

};

int Singleton::m_a = 5;
Singleton* Singleton::m_ptr = nullptr;

int main()
{
    std::cout << "A object\n";
    Singleton& A = Singleton::createObj();
    std::cout << "B object\n";
    Singleton& B = Singleton::createObj();

    A.Singleton::getObj();

    B.Singleton::getDataA();
    B.Singleton::setDataA(12);
    B.Singleton::getDataA();

    B.Singleton::getDataB();
    B.Singleton::setDataB(7);
    B.Singleton::getDataB();

    Singleton::destroyObj();

    return 0;
}
