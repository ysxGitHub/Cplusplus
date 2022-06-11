/*

*/

#include <iostream>
using namespace std;

// try、throw和catch关键字
int test() {
    double m = 1, n = 0;
    try {
        cout << "before dividing." << endl;
        if (n == 0)
            throw - 1;  //抛出int型异常
        else if (m == 0)
            throw - 1.0;  //拋出 double 型异常
        else
            cout << m / n << endl;
        cout << "after dividing." << endl;
    }
    catch (double d) {
        cout << "catch (double)" << d << endl;
    }
    catch (...) {
        cout << "catch (...)" << endl;
    }
    cout << "finished" << endl;
    return 0;
}

// 函数的异常声明列表
// int fun() throw(int,double,A,B,C){...};
// 这种写法表名函数可能会抛出int,double型或者A、B、C三种类型的异常，如果throw中为空，表明不会抛出任何异常，如果没有throw则可能抛出任何异常

// C++标准异常类 exception
/*
bad_typeid：使用typeid运算符，如果其操作数是一个多态类的指针，而该指针的值为 NULL，则会拋出此异常

bad_cast：在用 dynamic_cast 进行从多态基类对象（或引用）到派生类的引用的强制类型转换时，如果转换是不安全的，则会拋出此异常

bad_alloc：在用 new 运算符进行动态内存分配时，如果没有足够的内存，则会引发此异常

out_of_range:用 vector 或 string的at 成员函数根据下标访问元素时，如果下标越界，则会拋出此异常
*/
class A{
public:
  virtual ~A();
};


int test2() {
	A* a = NULL;
	try {
  		cout << typeid(*a).name() << endl; // Error condition
  	}
	catch (bad_typeid){
  		cout << "Object is NULL" << endl;
  	}
    return 0;
}

int* test3(){
    int a = 3;
    return &a;
}

int main(int argc, char const *argv[])
{
    test2();
    // 危险 &a 目前也就成为我们所说的野地址。
    int *p = test3();

    return 0;
}


