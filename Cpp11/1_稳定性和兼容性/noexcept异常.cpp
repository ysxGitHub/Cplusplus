#include<iostream>
#include<string>
using namespace std;


/*
异常被抛出后，从进入 try 块起，到异常被抛掷前，这期间在栈上构造的所有对象，都会被自动析构。
    析构的顺序与构造的顺序相反。这一过程称为栈的解旋。
*/
int main1() {
    try {
        throw -1; // 抛掷异常
    }
    catch (int e) {  // 捕获 整形异常
        cout << "int exception, value: " << e << endl;
    }
    cout << "That's ok!" << endl;
    return 0;
}

/*
    1.2 异常接口声明
*/

struct MyException{
    MyException(string s) :msg(s) {}
    string msg;
};
/*
1.显示指定可以抛出的异常类型: 当在 divisionMethod 函数后添加了 throw(MyException, int) 异常接口声明，
    其参数表示可以抛出的异常类型，分别为 int 和 MyException 类型。

2.抛出任意异常类型: 当 divisionMethod 没有添加 throw 接口，可以抛出任意异常类型

3.不抛出任何异常: 当 divisionMethod 添加 throw() 其参数列表为空，表示该函数不允许抛出异常。
*/
double divisionMethod(int a, int b) throw(MyException, int) {
    if (b == 0){
        throw MyException("division by zero!!!");
        // throw 0;
    }
    return a / b;
}

int main2(){
    try{
        double v = divisionMethod(100, 0);
        cout << "value: " << v << endl;
    }
    catch (int e){  // 捕获 整形异常
        cout << "catch except: "  << e << endl;
    }
    catch (MyException e){  // 捕获 自定义异常
        cout << "catch except: " << e.msg << endl;
    }
    return 0;
}

/*
上面的例子中，在 divisionMethod 函数声明之后，
    我们定义了一个动态异常声明 throw(MyException, int)，该声明指出了
    divisionMethod 可能抛出的异常的类型。事实上，该特性很少被使用，因此在 C++11 中被弃用了 ，
    而表示函数不会抛出异常的动态异常声明 throw() 也被新的 noexcept 异常声明所取代。
*/

double divisionMethod(int a, int b) noexcept {
    if (b == 0)
    {
        cout << "division by zero!!!" << endl;
        return -1;
    }
    return a / b;
}

/*
从语法上讲，noexcept 修饰符有两种形式：

    简单地在函数声明后加上 noexcept 关键字

    可以接受一个常量表达式作为参数，如下所示∶
    double divisionMethod(int a, int b) noexcept(常量表达式);


常量表达式的结果会被转换成一个 bool 类型的值：

    值为 true，表示函数不会抛出异常
    值为 false，表示有可能抛出异常这里
    不带常量表达式的 noexcept 相当于声明了 noexcept（true），即不会抛出异常。
*/

