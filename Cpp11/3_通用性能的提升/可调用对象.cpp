#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 可调用对象

// 1.是一个函数指针
int print(int a, double b){
    cout<<a<<", "<<b<<endl;
    return 0;
}
// 定义函数指针
int (*func)(int, double) = &print;
using funcptr = int(*)(int, double);
funcptr f = print;





// 2.是一个具有operator()成员函数的类对象（仿函数）
struct cmp{
    bool operator()(vector<int>&a, vector<int>&b){
        return a.back() < b.back();
    }
};

int main1(int argc, char const *argv[])
{
    vector<vector<int>> v{{1,2},{3,4}};
    sort(v.begin(), v.end(), cmp());
    return 0;
}





// 3.是一个可以转换为函数指针的类对象
using func_ptr = void(*)(int, string);
struct Test{

    static void print(int a, string b){ //静态成员 属于类的
        cout<<"name: "<<b<<", agr: "<<a<<endl;
    }

    void print1(int a, string b){ //属于对象的，没有对象就不存在
        cout<<"name: "<<b<<", agr: "<<a<<endl;
    }
    // 将类对象转换为函数指针
    operator func_ptr(){
        return print;
        // return print1; // error
    }
};

int main2(int argc, char const *argv[])
{
    Test t;
    t(10, "luffy");

    // 类的函数指针
    func_ptr f1 = Test::print;
    func_ptr f = Test::print1; //error 左边不是类里的函数指针，右边是类里的函数指针

    return 0;
}



// 4.是一个类成员函数指针或者类成员指针
struct Test1{
    static void print(int a, string b){
        cout<<"name: "<<b<<", agr: "<<a<<endl;
    }
    void print1(int a, string b){
        cout<<"name: "<<b<<", agr: "<<a<<endl;
    }
    int m_num;
};

int main(int argc, char const *argv[])
{
    // 类的函数指针
    using fptr = void(Test1::*)(int, string);
    fptr f1 = Test1::print1;

    // 类的成员指针(变量)
    using ptr1 = int Test1::*;
    ptr1 pt = &Test1::m_num;

    Test1 tt;
    (tt.*f1)(20, "luffy");
    tt.*pt = 100;

    cout<<"m_id: "<<tt.m_num<<endl;

    return 0;
}




