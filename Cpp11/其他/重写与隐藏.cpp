/*
两个函数参数相同，但是基类函数不是虚函数。隐藏和重写的区别在于基类函数是否是虚函数

两个函数参数不同，无论基类函数是不是虚函数，都会被隐藏。隐藏和和重载的区别在于两个函数不在同一个类中。
*/

#include<string>
#include<iostream>
using namespace std;


//父类
class A{
public:
    void fun(int a){
		cout << "A中的fun函数" << endl;
	}
    virtual void fun2(int a){
		cout << "A中的fun函数" << endl;
	}
};
//子类
class B : public A{
public:
    //隐藏父类的fun函数
    void fun(int a){
		cout << "B中的fun函数" << endl;
	}
    //隐藏父类的fun函数
    virtual void fun2(char* a){
        cout << "B中的fun函数" << endl;
    }
};
int main(){
    B b;
    b.fun(2); //调用的是B中的fun函数
    b.A::fun(2); //调用A中fun函数
    // b.fun2(2); //调用的是B中的fun函数，参数类型不对
    b.A::fun2(2); //调用A中fun函数
    return 0;
}
