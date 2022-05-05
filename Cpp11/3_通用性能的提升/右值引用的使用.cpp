#include <iostream>
using namespace std;


/*
右值引用具有移动语义，移动语义可以将资源（堆、系统对象等）通过浅拷贝从一个对象转移到
    另一个对象这样就能减少不必要的临时对象的创建、拷贝以及销毁，可以大幅提高 C++ 应用程序的性能。
*/


class Test
{
public:
    Test() : m_num(new int(100))
    {
        cout << "construct: my name is jerry" << endl;
        cout << "t.m_num adderss: " << m_num << endl;
    }

    Test(const Test& a) : m_num(new int(*a.m_num))
    {
        cout << "copy construct: my name is tom" << endl;
    }

    // 添加移动构造函数 -> 复用其他对象中的资源（堆内存）
    // 浅拷贝
    Test(Test&& a) : m_num(a.m_num)
    {
        a.m_num = nullptr; // 改变一下 a.m_num 的指向，防止释放堆里的数据
        cout << "move construct: my name is sunny" << endl;
    }

    ~Test() {
        delete m_num;
    }

    int* m_num;
};

Test getObj() {
    Test t;
    return t;
}

Test getObj2() {
    return Test(); //匿名对象
}

Test&& getObj3() {
    return Test(); //匿名对象
}

// vscode会出现 bug
int main() {
    // 要求右侧的对象是一个临时对象，才会调用移动构造函数
    // 如果没有移动构造函数, 会调用copy构造函数
    Test t = getObj(); // 复用了即将 被析构的对象的 堆资源
    cout << "t.m_num adderss: " << t.m_num << endl;

    Test&& t1 = getObj();
    cout << "t1.m_num adderss: " << t1.m_num << endl;

    // 如果没有移动构造函数,使用右值引用初始化要求更高一些
    // 要求右侧是一个临时对象且不能取地址
    Test&& t2 = getObj2(); // 复用了 匿名对象 的 所有资源
    cout << "t2.m_num adderss: " << t2.m_num << endl;

    // 或者
    Test&& t3 = getObj3(); // 复用了 匿名对象 的 所有资源
    cout << "t3.m_num adderss: " << t3.m_num << endl;

    return 0;
};
