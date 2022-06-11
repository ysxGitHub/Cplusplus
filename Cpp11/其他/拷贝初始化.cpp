/*
为了提高效率，允许编译器跳过创建临时对象这一步，直接调用构造函数构造要创建的对象，这样就完全等价于直接初始化了（语句1和语句3等价），但是需要辨别两种情况。
    当拷贝构造函数为private时：语句3和语句4在编译时会报错
    使用explicit修饰构造函数时：如果构造函数存在隐式转换，编译时会报错
*/
#include<string>
#include<iostream>
using namespace std;

class A{
public:
    int num1;
    int num2;
public:
    A(int a=0, int b=0):num1(a),num2(b){};
    // 拷贝初始化
    A(const A& a){
        this->num1 = a.num1;
        this->num2 = a.num2;
    };
    //重载 = 号操作符函数
    A& operator=(const A& a){
        num1 = a.num1 + 1;
        num2 = a.num2 + 1;
        return *this;
    };
};

int main(int argc, char const *argv[])
{
    string str1("I am a string");//语句1 直接初始化
    string str2(str1);//语句2 直接初始化，str1是已经存在的对象，直接调用拷贝构造函数对str2进行初始化
    string str3 = "I am a string";//语句3 拷贝初始化，先为字符串”I am a string“创建临时对象，再把临时对象作为参数，使用拷贝构造函数构造str3
    string str4 = str1;//语句4 拷贝初始化，这里相当于隐式调用拷贝构造函数，而不是调用赋值运算符函数

    // 对于简单类型来说，初始化和赋值没什么区别, 对于类和复杂数据类型来说，这两者的区别就大了
    A a(1,1);
    A a1 = a; //拷贝初始化操作，调用拷贝构造函数
    cout<<a1.num1<<", "<<a1.num2<<endl;
    A b;
    b = a;//赋值操作，对象a中，num1 = 1，num2 = 1；对象b中，num1 = 2，num2 = 2
    cout<<b.num1<<", "<<b.num2<<endl;

    return 0;
}

