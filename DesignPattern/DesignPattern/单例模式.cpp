#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;
/*
饿汉模式：资源在程序初始化阶段就完成加载（空间换时间）
饿汉方法实现：
    采用静态方法修饰资源，所有对象共用同一份资源，程序初始化阶段完成资源加载且只被加载一次
    构造函数私有化 ，保证一个类只能实例化一个对象
*/
class UserManager {
private:
    // 将构造函数设为私有
    UserManager() {};
    // 同时将 copy 构造与 =操作符重载 禁用
    UserManager(const UserManager& obj) = delete;
    UserManager& operator=(const UserManager& obj) = delete;
public:
    static UserManager* GetInstance() {
        // 创建静态局部对象, C++11 不用考虑线程安全
        static UserManager um;
        return &um;
    }
};

/*
懒汉模式：资源在使用的时候再去加载（延迟加载）
    定义对象指针，初始资源为空
    static修饰，共用一份资源
    volatite修饰 ，防止编译器过度优化
    加锁保护  线程安全
    二次检测，防止锁冲突
*/

// 局部静态的指针 也是线程安全的 所以不用加 m_mtx
class Singleton
{
public:
    static Singleton* GetInstance() {
        // 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
        if (nullptr == m_pInstance) {//第一次判断防止多次加锁导致锁冲突
            m_mtx.lock();
            //第二次判断是否为空，为空则为第一次调用构造函数创建，不为空，后续都不会调用构造函数，满足对象第一次创建且仅创建一次
            if (nullptr == m_pInstance) {
                m_pInstance = new Singleton();
            }
            m_mtx.unlock();
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
//静态成员变量类外初始化，第一次初始化为nullptr
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;


int main(int argc, char const* argv[])
{
    UserManager* um1 = UserManager::GetInstance();
    UserManager* um2 = UserManager::GetInstance();
    cout << um1 << ", " << um2 << endl;
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();
    cout << s1 << ", " << s2 << endl;

    pause();
    return 0;
}
