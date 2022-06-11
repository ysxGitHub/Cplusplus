#include <iostream>
using namespace std;

class A {
public:
    A() :age(0), sex(0), bChild(0) {};
    A(int a, bool s, bool b) {
        age = a;
        sex = s;
        bChild = b;
    }
    void setAge(int a) {
        age = a;
    }
private:
    int age;
    bool sex;
    bool bChild;
};

class Foo
{
public:
    int _id;
    long _data;
    string _str;
public:
    Foo() :_id(0) { cout << "default ctor.this=" << this << " id=" << _id << endl; }
    Foo(int i) :_id(i) { cout << "ctor.this=" << this << " id=" << _id << endl; }
    ~Foo() { cout << "dtor.this=" << this << " id=" << _id << endl; }
    static void* operator new(size_t size);
    static void operator delete(void* pdead, size_t size);
    static void* operator new[](size_t size);
    static void operator delete[](void* pdead, size_t size);
};

void* Foo::operator new(size_t size)
{
    Foo* p = (Foo*)malloc(size);
    cout << "调用了Foo::operator new" << endl;
    return p;
}

void Foo::operator delete(void* pdead, size_t size)
{
    cout << "调用了Foo::operator delete" << endl;
    free(pdead);
}
void* Foo::operator new[](size_t size)
{
    Foo* p = (Foo*)malloc(size);
    cout << "调用了Foo::operator new[]" << endl;
    return p;
}

void Foo::operator delete[](void* pdead, size_t size)
{
    cout << "调用了Foo::operator delete[]" << endl;
    free(pdead);
}

int main(int argc, char const* argv[])
{
    // 操作符
    A* a1 = new A();
    /*
    编译产生的代码
    void* p = (void*)malloc(12);
    A* a1 = static_cast<A*>(p);
    a1->A::A();
    return a1;
    */
    a1->setAge(10);
    // 将 a1 的地址给了 a11
    A* a11 = new(a1)A;
    a11->setAge(20);
    // 操作符
    delete a11;


    // placement new
    void* tmpM1 = (void*)::operator new(12);
    A* a2 = new(tmpM1)A;
    ::operator delete(tmpM1);

    
    // placement new
    void* tmpM2 = (void*)malloc(12);
    A* a3 = new(tmpM2)A;
    free(tmpM2);

    // 全局函数
    Foo* pf = new Foo(7);
    Foo* pf1 = new Foo[10];
    delete pf;
    delete[] pf1;

    return 0;
}

