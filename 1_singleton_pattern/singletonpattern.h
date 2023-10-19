#include <iostream>
#include <mutex>
using namespace std;

//懒汉式
/*
class SingleObject
{
private:
    SingleObject()
    {
        cout << "create SingleObject" << endl;
    }
    static SingleObject *instance;

public:
    static SingleObject *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new SingleObject();
        }
        return instance;
    }
};
SingleObject *SingleObject::instance = nullptr;
*/

//饿汉式
/*
class SingleObject
{
private:
    SingleObject()
    {
        cout << "create SingleObject" << endl;
    }

public:
    static SingleObject *getInstance()
    {
        static SingleObject instance;
        return &instance;
    }
}
*/

//C++11 static特性 保证多线程安全
class SingleObject
{
public:
    static SingleObject *getInstance(const string value)  {
        static SingleObject instance(value);
        return &instance;
    }

    string getValue() const {
        return m_value;
    }    

private:
    std::string m_value;

    SingleObject(const string value): m_value(value) {
        cout << "create SingleObject" << endl;
    }

     SingleObject() = default;
    ~SingleObject() = default;
    SingleObject(const SingleObject &other) =delete;
    SingleObject & operator = (const SingleObject& other) =delete;
};


void Thread1() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingleObject *pSingle = SingleObject::getInstance("AA");
    std::cout<<"Thread1 Get: "<< pSingle->getValue() << std::endl;
}


void Thread2() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingleObject *pSingle = SingleObject::getInstance("CC") ;
    std::cout<<"Thread2 Get: "<< pSingle->getValue() << std::endl;
}


void sington_test() {
    std::thread t1(Thread1);
    std::thread t2(Thread2);
    t1.join();
    t2.join();
}



