#include <iostream>

using namespace std;

//C++中的继承与多态
struct A {

    virtual void fun()  //C++中的多态:通过虚函数实现
    {
        cout<<"A:fun()"<<endl;
    }
    int a;
};

struct B:public A     //C++中的继承:B类公有继承A类
{
    virtual void fun()  //C++中的多态:通过虚函数实现（子类的关键字virtual可加可不加）
    {
        cout<<"B:fun()"<<endl;
    }
    int b;
};

//C语言模拟C++的继承与多态

typedef void (*FUN)();   //定义一个函数指针来实现对成员函数的继承

struct _A    //父类
{
    FUN _fun;  //由于C语言中结构体不能包含函数，故只能用函数指针在外面实现
    int _a;
};

struct _B     //子类
{
    _A _a_;   //在子类中定义一个基类的对象即可实现对父类的继承
    int _b;
};

void _fA()    //父类的同名函数
{
    printf("_A:_fun()\n");
}

void _fB()    //子类的同名函数
{
    printf("_B:_fun()\n");
}

void Test()
{

    //测试C++中的继承与多态
    A a;  //定义一个父类对象a
    B b;  //定义一个子类对象b

    A* p1 = &a;  //定义一个父类指针指向父类的对象
    p1->fun();  //调用父类的同名函数
    p1 = &b;   //让父类指针指向子类的对象
    p1->fun();  //调用子类的同名函数

    //C语言模拟继承与多态的测试
    _A _a;  //定义一个父类对象_a
    _B _b;  //定义一个子类对象_b
    _a._fun = _fA;    //父类的对象调用父类的同名函数
    _b._a_._fun = _fB;  //子类的对象调用子类的同名函数


    _A* p2 = &_a;  //定义一个父类指针指向父类的对象
    p2->_fun();   //调用父类的同名函数
    p2 = (_A*)&_b; //让父类指针指向子类的对象,由于类型不匹配所以要进行强转
    p2->_fun();   //调用子类的同名函数
}


// 类的内存对齐
class MyClass {
public:
	MyClass();
	~MyClass();
	//virtual void fun() {}; // 4

private:
    char b; // 1
	int a; // 4
    double c; // 8
};

MyClass::MyClass() {

}

MyClass::~MyClass() {

}

int main() {

	// test03
	std::cout << "size int :" << sizeof(int) << " size char:" << sizeof(char) << " size double:" << sizeof(double) << std::endl;
	std::cout << "size MyClass:" << sizeof(MyClass) << std::endl;
}
