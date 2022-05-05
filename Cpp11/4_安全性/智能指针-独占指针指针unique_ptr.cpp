#include <memory>
#include <iostream>
#include <functional>
using namespace std;


class Test {
public:
    Test() {
        cout << "construct Test..." << endl;
    }
    Test(int x) {
        cout << "construct Test, x = " << x << endl;
    }
    Test(string str) {
        cout << "construct Test, str = " << str << endl;
    }
    ~Test(){
        cout << "destruct Test ..." << endl;
    }
    void setValue(int v){
        m_num = v;
    }
    void print() const {
        cout<<"m_num: "<<m_num<<endl;
    }

private:
    int m_num;
};


int main(int argc, char const *argv[])
{
    // 通过构造函数初始化对象
    unique_ptr<int> ptr1(new int(10));
    // unique_ptr<int> ptr2 = ptr1; // error, 不允许将一个unique_ptr赋值给另一个unique_ptr

    // 通过转移所有权的方式初始化
    unique_ptr<int> ptr2 = move(ptr1);

    // reset 初始化
    ptr2.reset(); // 重置

    ptr2.reset(new int(250)); // 替换

    // 获取原始指针
    unique_ptr<Test> ptr3(new Test(10));
    Test* pt = ptr3.get();
    pt->setValue(2);
    pt->print();

    // 通过智能指针对象直接操作管理的内存
    ptr3->setValue(4);
    ptr3->print();

    // 指定删除器函数
    using ptrFun = void(*)(Test*);
    unique_ptr<Test, ptrFun> ptr4(new Test("hello"), [](Test* t){
        delete t;
    });

    unique_ptr<Test, function<void(Test*)>> ptr5(new Test("world"), [=](Test* t){
        delete t;
    });

    // 独占的智能指针可以管理数组类型的地址，能够自动释放
    unique_ptr<Test[]> ptr6(new Test[3]);
    // C++11 不支持，C++11之后才支持
    shared_ptr<Test[]> ptr7(new Test[3]);

    return 0;
}

