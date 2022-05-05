#include <memory>
#include <iostream>

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



// 1.通过构造函数初始化
// shared_ptr<T> 类模板中，提供了多种实用的构造函数, 语法格式如下:
// std::shared_ptr<T> 智能指针名字(创建堆内存);

// 2.通过拷贝和移动构造函数初始化
// 调用拷贝构造函数
// shared_ptr<int> ptr2(ptr1);
// 调用移动构造函数
// shared_ptr<int> ptr4(std::move(ptr1));

// 3.通过 std::make_shared 初始化

// 4.通过 reset 方法初始化


int main(int argc, char const *argv[])
{
    // 1.通过构造函数初始化
    shared_ptr<int> ptr1(new int(3));
    cout << "ptr1 use_count: " << ptr1.use_count() << endl;
    cout<<endl;

    // 2.通过拷贝和移动构造函数初始化
    shared_ptr<int> ptr2 = move(ptr1); // 移动构造函数
    // cout << "ptr1 use_count: " << ptr1.use_count() << endl; // error ptr1 将亡值
    cout << "ptr2 use_count: " << ptr2.use_count() << endl;
    shared_ptr<int> ptr3 = ptr2;  // 拷贝构造函数
    cout << "ptr2 use_count: " << ptr2.use_count() << endl;
    cout << "ptr3 use_count: " << ptr3.use_count() << endl;
    cout<<endl;

    // 3.通过 std::make_shared 初始化
    shared_ptr<int>ptr4 = make_shared<int>(8);
    shared_ptr<Test>ptr5 = make_shared<Test>(8);
    shared_ptr<Test>ptr6 = make_shared<Test>("hello world!");
    cout << "ptr4 use_count: " << ptr4.use_count() << endl;
    cout << "ptr5 use_count: " << ptr5.use_count() << endl;
    cout << "ptr6 use_count: " << ptr6.use_count() << endl;
     cout<<endl;

    // 4.通过 reset 方法初始化
    ptr6.reset(); // 重置
    cout << "ptr6 use_count: " << ptr6.use_count() << endl;

    ptr5.reset(new Test("666 666")); //
    cout << "ptr5 use_count: " << ptr5.use_count() << endl;

    // 获取原始地址
    Test* t = ptr5.get();
    t->setValue(100);
    t->print();

    // 通过智能指针对象直接操作管理的内存
    ptr5->setValue(20);
    ptr5->print();

    // 指定删除器函数
    shared_ptr<Test> ptr8(new Test(100), [](Test* t){
        // t 指向的是 new Test(100), ptrn 调用该删除器
        delete t;
    });

    // 数组类型的地址必须 指定 删除器函数，否则 内存不能完全释放
    shared_ptr<Test> ptrn(new Test[5], [](Test* t){
        delete []t;
    });

    // 默认删除器函数
    shared_ptr<Test> ptrn1(new Test(10), default_delete<Test>());

    shared_ptr<Test> ptrn2(new Test[5], default_delete<Test[]>());

    return 0;
}


// 自己封装一个 make_shared_array 方法来让 shared_ptr 支持数组
template <typename T>
shared_ptr<T> make_share_array(size_t size) {
    // 返回匿名对象
    return shared_ptr<T>(new T[size], default_delete<T[]>());
}

