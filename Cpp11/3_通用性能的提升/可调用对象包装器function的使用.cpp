#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print(int a, string b){
        cout<<"name: "<<b<<", agr: "<<a<<endl;
}


using func_ptr = void(*)(int, string);
struct Test{

    static void print(int a, string b){ //静态成员 属于类的
        cout<<"(static) name: "<<b<<", agr: "<<a<<endl;
    }

    void print1(int a, string b){ //属于对象的，没有对象就不存在
        cout<<"name: "<<b<<", agr: "<<a<<endl;
    }

    // 将类对象转换为函数指针
    operator func_ptr(){
        return print;
        // return print1; // error
    }

    void operator()(string b) const{
        cout<<"name: "<<b<<endl;
    }

};


class A{
public:
    // 构造函数参数是一个包装器对象
    A(const function<void(int a, string b)>& f) : callback(f) {
    }

    void notify(int a, string b){
        callback(a, b); // 调用通过构造函数得到的函数指针
    }
private:
    function<void(int a, string b)> callback;
};


int main(int argc, char const *argv[])
{
    // 1.包装普通函数
    function<void(int, string)> f1 = print;

    // 2.包装类的静态函数
    function<void(int, string)> f2 = Test::print;

    // 3.包装仿函数
    function<void(string)> f3 = Test();

    // 4.包装转换为函数指针的对象
    function<void(int, string)> f4 = Test();


    f1(0, "abc");

    f2(10, "bcd");

    f3("cde");

    f4(30, "def");

    A aa(print);
    aa.notify(1,"aa");

    A ab(Test::print);
    ab.notify(2,"ab");

    Test tc;
    A ac(tc);
    ac.notify(3,"ac");


    return 0;
}
