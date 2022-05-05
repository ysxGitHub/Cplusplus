/*
在 C++ 中声明自定义的类，编译器会默认帮助程序员生成一些他们未自定义的成员函数。
    这样的函数版本被称为” 默认函数”。这样的函数一共有六个：

    无参构造函数：创建类对象
    拷贝构造函数：拷贝类对象
    移动构造函数：拷贝类对象
    拷贝赋值函数：类对象赋值
    移动赋值函数：类对象赋值
    析构函数：销毁类对象

在 C++ 语法规则中，一旦程序员实现了这些函数的自定义版本，则编译器不会再为该类自动生成默认版本。
有时程序员会忘记上面提到的规则，最常见的是声明了带参数的构造，
    如果还需要无参构造函数，这时候必须定义出不带参数的版本。

一旦声明了自定义版本的构造函数，则有可能导致我们定义的类型不再是 POD 类型

在 C++11 标准中称 = default 修饰的函数为显式默认【缺省】（explicit defaulted）函数，
    而称 =delete 修饰的函数为删除（deleted）函数或者显示删除函数。

*/

// =default
// 可以在类内部修饰满足条件的类函数为显示默认函数，也可以在类定义之外修饰成员函数为默认函数。

// 在类内部指定函数为默认函数
class Base0 {
public:
    Base0() = default;  // 指定无参构造为默认函数
    Base0(const Base0& obj) = default;  // 指定拷贝构造函数为默认函数
    Base0(Base0&& obj) = default;  // 指定移动构造函数为默认函数
    Base0& operator= (const Base0& obj) = default; // 指定复制赋值操作符重载函数为默认函数
    Base0& operator= (Base0&& obj) = default; // 指定移动赋值操作符重载函数为默认函数
    ~Base0() = default; // 指定析构函数为默认函数
};

// 类定义
class Base
{
public:
    Base();
    Base(const Base& obj);
    Base(Base&& obj);
    Base& operator= (const Base& obj);
    Base& operator= (Base&& obj);
    ~Base();
};
// 在类定义之外指定成员函数为默认函数
Base::Base() = default;
Base::Base(const Base& obj) = default;
Base::Base(Base&& obj) = default;
Base& Base::operator= (const Base& obj) = default;
Base& Base::operator= (Base&& obj) = default;
Base::~Base() = default;

/*
注意：
    如果程序猿对 C++ 类提供的默认函数（上面提到的六个函数）进行了实现，
        那么可以通过 =default 将他们再次指定为默认函数，
        不能使用 =default 修饰这六个函数以外的函数。
*/

#include<iostream>

// =delete
// =delete 表示显示删除，`显式删除可以避免用户使用一些不应该使用的类的成员函数`，
// 使用这种方式可以有效的防止某些类型之间自动进行隐式类型转换产生的错误。

// 禁止使用默认生成的函数
class Base1 {
public:

    Base1() = default;
    Base1(const Base1& obj) = delete;
    Base1& operator= (const Base1& obj) = delete;


    Base1(int num) : m_num(num) {}
    Base1(char c) = delete;
    void print(char c) = delete;
    void print()
    {
        std::cout << "num: " << m_num << std::endl;
    }
    void print(int num)
    {
        std::cout << "num: " << num << std::endl;
    }

private:
    int m_num;
};

int main(){
    Base1 b;
    Base1 tmp1(b);    // error  禁用拷贝构造函数
    Base1 tmp = b;    // error  禁用 = 进行对象复制

    Base1 b(97);       // 'a' 对应的 acscii 值为97
    Base1 b1('a');     // error  禁用带 char 类型参数的构造函数，防止隐式类型转换（char 转 int)
    b.print();
    b.print(97);
    b.print('a');      // error  禁止使用带 char 类型的自定义函数，防止隐式类型转换（char 转 int)
    return 0;
}
