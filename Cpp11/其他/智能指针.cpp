#include <iostream>
#include <memory>
using namespace std;

namespace test1
{
    class A {
    public:
        ~A() {
            cout << "dealloc A" << endl;
        }
        // 父类的指针在析构时，不会调用子类中的析构函数，导致子类如果有堆区属性成员，会出现内存泄漏，
        // virtual ~A() {
        //     cout << "dealloc A" << endl;
        // }
    };
    class B : public A {
    public:
        ~B() {
            cout << "dealloc B" << endl;
        }
    };

    int main(int argc, const char * argv[]) {
        A *a = new B();
        delete a; //只打印dealloc A

        shared_ptr<A>spa = make_shared<B>(); //析构spa是会先打印dealloc B，再打印dealloc A
        return 0;
    }
}

namespace test2
{
    class A {
    public:
        shared_ptr<B> b;
    };
    class B {
    public:
        shared_ptr<A> a;
    };
    int main(int argc, const char * argv[]) {
        shared_ptr<A> spa = make_shared<A>();
        shared_ptr<B> spb = make_shared<B>();
        spa->b = spb;
        spb->a = spa;
        return 0;
    } //main函数退出后，spa和spb强引用计数依然为1，无法释放
}


namespace test3
{
    class A {
    public:
        shared_ptr<B> b;
    };
    class B {
    public:
        weak_ptr<A> a;
    };

    int main(int argc, const char * argv[]) {
        shared_ptr<A> spa = make_shared<A>();
        shared_ptr<B> spb = make_shared<B>();
        spa->b = spb; //spb强引用计数为2，弱引用计数为1
        spb->a = spa; //spa强引用计数为1，弱引用计数为2
        return 0;
    } //main函数退出后，spa先释放，spb再释放，循环解开了
}


