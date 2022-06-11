#include<iostream>

// 语法
// decltype(表达式)

// 类型推导
int a = 10;
decltype(a) b = 20;
decltype(a+3.14) c = 51.1;


// 规则1：表达式为普通变量或者普通表达式或者类表达式，在这种情况下，
//       使用 decltype 推导出的类型和表达式的类型是一致的。

int x = 1;
const int & y = x;

decltype(x) a1 = x;

decltype(y) a2 = x;

class Test{
public:
    std::string text;
    static const int value = 110;
};

decltype(Test::text) c = "haha";
decltype(Test::value) d = 0;


// 规则2：表达式是函数调用，使用 decltype 推导出的类型和函数返回值一致。
//       对于纯右值（自变量）而言，只有类类型可以携带const、volatile限定符，除此之外需要忽略掉这两个限定符

//函数声明
int func_int();                 // 返回值为 int
int& func_int_r();              // 返回值为 int&
int&& func_int_rr();            // 返回值为 int&&

const int func_cint();          // 返回值为 const int
const int& func_cint_r();       // 返回值为 const int&
const int&& func_cint_rr();     // 返回值为 const int&&

const Test func_ctest();        // 返回值为 const Test

//decltype类型推导
int n = 100;
decltype(func_int()) a = 0;
decltype(func_int_r()) b = n;
decltype(func_int_rr()) c = 0;

decltype(func_cint())  d = 0;      // int d;

decltype(func_cint_r())  e = n;    // cosnt int &e
decltype(func_cint_rr()) f = 0;    // cosnt int &&f
decltype(func_ctest()) g = Test(); // const Test g

/*
函数 func_cint () 返回的是一个纯右值（在表达式执行结束后不再存在的数据，也就是临时性的数据），对于纯右值而言，只有类类型可以携带const、volatile限定符，除此之外需要忽略掉这两个限定符，因此推导出的变量 d 的类型为 int 而不是 const int。
*/


// 规则3：表达式是一个左值，或者被括号 ( ) 包围，使用 decltype 推导出的是表达式类型的引用
//      （如果有 const、volatile 限定符不能忽略）。

class Test1{
public:
    int num = 9;
    std::string text;
    static const int value = 11;
};

const Test1 obj;

decltype(obj.num) a3 = 0; // int a3;
// 带括号的表达式
decltype((obj.num)) a4 = 1; // const int &a4;

int m = 0, n = 0;
decltype(n+m) a5 = 0;  // int a5;
// 加法表达式
decltype(n+=m) a6 = n; // int &a6;

decltype(n+=m) a6 = 1; // int &a6 = 1; error 非常量引用的初始值必须为左值
const int &i = 1; //const int tmp =1; const int & i = tmp;

decltype(m) x; // int x;


//3. 对指针的解引用操作返回的是引用类型
int i1 = 3, j1 = 6, *p1 = &i1;
decltype(*p1) c1 = j1; // c是int&类型, c和j绑定在一起

int e1 = 4;
const int* f1 = &e1; // f是底层const
decltype(auto) j1 = f1;//j的类型是const int* 并且指向的是e

