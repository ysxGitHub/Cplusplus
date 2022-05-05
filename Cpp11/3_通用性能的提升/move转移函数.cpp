/*
使用std::move方法可以将左值转换为右值。使用这个函数并不能移动任何东西，
    而是和移动构造函数一样都具有移动语义，将对象的状态或者所有权从一个对象转移到另一个对象，
    只是转移，没有内存拷贝。
    一般用于前面的对象不用了, 转移给后面的对象, 自己变成将亡值
*/

#include <iostream>
#include <list>
using namespace std;

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


int main(int argc, char const *argv[])
{
    Test t = getObj();

    Test&& t2 = getObj2();

    Test&& t3 = t2; // error
    Test&& t3 = move(t2); // t3 没有被构造, 只是 t2 的转移

    list<string> ls1 = {"111", "aaa", "bbb"};

    list<string> ls2 = ls1; // copy
    list<string> ls2 = move(ls1); // 转移

    return 0;
}
