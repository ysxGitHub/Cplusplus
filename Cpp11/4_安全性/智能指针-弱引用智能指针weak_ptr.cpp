#include <memory>
#include <iostream>
using namespace std;

class Test : public enable_shared_from_this<Test>{  // ok 解决
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

    shared_ptr<Test> getSharePtr(){
        // return shared_ptr<Test>(this); // 继承之后就不能直接返回 shared_ptr 的实例化对象
        return shared_from_this();  // weak_ptr 调用 lock 方法 方法 shared_ptr
    }

private:
    int m_num;
};

struct TA;
struct TB;

struct TA{
    shared_ptr<TB> bptr; //
    // weak_ptr<TB> bptr; // ok 解决
    ~TA(){
        cout << "construct TA..." << endl;
    }
};

struct TB{
    shared_ptr<TA> aptr;
    ~TB(){
        cout << "construct TB..." << endl;
    }
};


// 弱引用智能指针 std::weak_ptr 可以看做是 shared_ptr 的助手，它不管理 shared_ptr 内部的指针。
/*
shared_ptr 使用的注意事项：
    1.不能使用一个原始地址初始化多个共享智能指针
    2.函数不能返回管理了 this 的共享智能指针对象
    3.共享智能指针不能循环引用
*/

int main(int argc, char const *argv[])
{
    // 1.不能使用一个原始地址初始化多个共享智能指针
    Test* t = new Test;
    shared_ptr<Test>ptr1(t);
    // shared_ptr<Test>ptr2(t); // error 会析构两次
    shared_ptr<Test>ptr2 = ptr1; // ok

    // 2.函数不能返回管理了 this 的共享智能指针对象
    shared_ptr<Test> sp1(new Test);  // 在这一步 weak_ptr 就实例化了
    cout << "sp1 use_count: " << sp1.use_count() << endl;
    shared_ptr<Test>sp2 = sp1->getSharePtr(); // error 会析构两次，解决如上 类的继承
    cout << "sp2 use_count: " << sp2.use_count() << endl;

    // 3.共享智能指针不能循环引用
    shared_ptr<TA> ap(new TA);
    shared_ptr<TB> bp(new TB);
    cout << "ap use_count: " << ap.use_count() << endl;
    cout << "bp use_count: " << bp.use_count() << endl;

    ap->bptr = bp;
    bp->aptr = ap;
    cout << "ap use_count: " << ap.use_count() << endl;
    cout << "bp use_count: " << bp.use_count() << endl;

    return 0;
}
