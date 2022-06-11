#include <iostream>
using namespace std;


void test(){
    #define NUM 5
    typedef double DOU;
    DOU a = 1.0;
    cout<<a<<endl;
    cout<<NUM<<endl;
}


// using 可以直接给模板类进行取别名。
template<class T>
using ba = Base<T>

// typedef 不能够直接给模板类进行取别名。
template<class T>
typedef Base<T> bs;


int main(int argc, char const *argv[])
{
    test();
    cout<<NUM<<endl;
    // DOU a = 0.0; // typedef有作用域

	#define INTPTR1 int*
	typedef int* INTPTR2;


	INTPTR1 p1, p2; // int* p1, int p2
    INTPTR2 p3, p4; // int* p3, int* p4

    int a = 1;
    int b = 2;
    int c = 3;

    const INTPTR1 pa = &a; // const int* pa
    const INTPTR2 pb = &b; // int* const pb;
    INTPTR2 const pc = &c; // int* const pc;

    *pa = 10; //error
    *pb = 10; //ok
    *pc = 10; //ok
    int c = 20;
    pb = &c; // error
    pc = &c; // error

    return 0;
}
