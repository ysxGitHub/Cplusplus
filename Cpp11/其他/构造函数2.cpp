/*

*/
#include <iostream>
using namespace std;

class CString
{
public:
    CString() = default; //语句1
    //构造函数
    CString(const char* pstr) : _str(pstr){}
    void* operator new() = delete; //这样不允许使用new关键字
    //析构函数
    ~CString(){}
    // 纯虚函数
    virtual void print()=0;
public:
     string _str;
};

void test(){
   auto a = new CString(); //语句2
   cout << "Hello World" <<endl;
}

/*
构造函数:
对象不存在，没用别的对象初始化，在创建一个新的对象时调用构造函数

拷贝构造函数:
对象不存在，但是使用别的已经存在的对象来进行初始化

赋值运算符:
对象存在，用别的对象给它赋值，这属于重载“=”号运算符的范畴，“=”号两侧的对象都是已存在的


拷贝构造函数和赋值运算符重载的区别？

拷贝构造函数是函数，赋值运算符是运算符重载。
拷贝构造函数会生成新的类对象，赋值运算符不能。

拷贝构造函数是直接构造一个新的类对象，所以在初始化对象前不需要检查源对象和新建对象是否相同；赋值运算符需要上述操作并提供两套不同的复制策略，另外赋值运算符中如果原来的对象有内存分配则需要先把内存释放掉。
*/
class A {
public:
	A() {
		cout << "我是构造函数" << endl;
	}
	A(const A& a) {
		cout << "我是拷贝构造函数" << endl;
	}
	A& operator = (A& a) {
		cout << "我是赋值操作符" << endl;
		return *this;
	}
	~A() {};
};

void test2(){
	A a1; //调用构造函数
	A a2 = a1; //调用拷贝构造函数
	a2 = a1; //调用赋值操作符
}

