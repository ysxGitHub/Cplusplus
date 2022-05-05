#include <iostream>
using namespace std;

class Base
{
public:
    int a = 0;
};

class Base1 : virtual public Base
{
// public:
//     int a = 1;
};

class Base2 : virtual public Base
{
// public:
//     int a = 2;
};

class Son : public Base1, public Base2
{

// public:
//     int a = 3;
};


int main(int argc, char const* argv[])
{

    // 8
    cout << sizeof(Son) << endl;

    Son s1;
    // 当多个父类都出现同名成员，调用时需要指定作用域
    // 当出现菱形继承时，调用同名成员时需要指定作用域
    // 而且会浪费内存，由于在内存中拷贝了两份
    cout << s1.Base1::a << endl;
    cout << s1.Base2::a << endl;
    // cout<<s1.a<<endl; // 没有virtual不行
    // 利用虚继承可以解决菱形继承问题，在继承之前加上关键字 virtual变为虚继承，相当于在每个继承类中用指针指向父类继承的同名成员。
    cout<<s1.a<<endl; // 加上virtual可以了

    return 0;
}



