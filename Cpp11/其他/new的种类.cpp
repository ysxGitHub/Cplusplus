/*
plain new，nothrow new 和 placement new

因此plain new在空间分配失败的情况下，抛出异常std::bad_alloc而不是返回NULL

nothrow new在空间分配失败的情况下是不抛出异常，而是返回NULL


placement new 允许在一块已经分配成功的内存上重新构造对象或对象数组。placement new 不用担心内存分配失败，因为它根本不分配内存，它做的唯一一件事情就是调用对象的构造函数
*/

#include <iostream>
#include <string>
using namespace std;

//执行结果：bad allocation
void test() {
	try {
		char *p = new char[static_cast<int>(10e11)];
		delete p;
	}
	catch (const std::bad_alloc &ex) {
		cout << ex.what() << endl;
	}
}

//运行结果：alloc failed
void test2(){
	char *p = new(nothrow) char[static_cast<int>(10e11)];
	if (p == NULL)
	{
		cout << "alloc failed" << endl;
	}
	delete p;
}


class ADT{
	int i;
	int j;
public:
	ADT(){
		i = 10;
		j = 100;
		cout << "ADT construct i=" << i << "j="<<j <<endl;
	}
	~ADT(){
		cout << "ADT destruct" << endl;
	}
};

void test3(){
	char *p = new(nothrow) char[sizeof ADT + 1];
	if (p == NULL) {
		cout << "alloc failed" << endl;
	}
	ADT *q = new(p) ADT;  //placement new:不必担心失败，只要p所指对象的的空间足够ADT创建即可
	//delete q;//错误!不能在此处调用delete q;
	q->ADT::~ADT();//显示调用析构函数
	delete[] p;
}

int main()
{
    test();
    test2();
    test3();
	return 0;
}
