#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>
using namespace std;

// 局部静态的指针 也是线程安全的 所以不用加 m_mtx
class Singleton
{
public:
    static Singleton* GetInstance() {
        if (nullptr == m_pInstance) {
            m_pInstance = new Singleton();
        }
        return m_pInstance;
    }
    // 实现一个内嵌垃圾回收类
    class CGarbo {
    public:
        ~CGarbo() {
            if (Singleton::m_pInstance)
                delete Singleton::m_pInstance;
        }
    };
    // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
    static CGarbo Garbo;
private:
    // 构造函数私有
    Singleton() {};
    // 防拷贝
    Singleton(Singleton const& obj);
    Singleton& operator=(Singleton const& obj);
    static Singleton* m_pInstance; // 单例对象指针 静态成员变量，在调用构造函数前先创建进行判断
    static mutex m_mtx; //互斥锁
};

// 为什么不需要了
////静态成员变量类外初始化，第一次初始化为nullptr
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;

void func1(int n)
{
    sleep(1);
    cout<< Singleton::GetInstance() << endl;
}

void func2(int n)
{
    sleep(1);
    cout<< Singleton::GetInstance() << endl;
}

// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
int main()
{
    thread t1(func1, 10);
    thread t2(func2, 10);
    t1.join();
    t2.join();
    cout << Singleton::GetInstance() << endl;
    cout << Singleton::GetInstance() << endl;

    pause();
    return 0;
}