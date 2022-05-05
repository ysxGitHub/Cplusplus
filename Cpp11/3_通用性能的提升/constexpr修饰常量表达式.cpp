#include<iostream>
#include<string>
using namespace std;

// constepr 不能直接修饰 类 和 结构体, 但是可以修饰 对象 和 实例
cosntptr struct Stu{
    int a;
};

void func(const int num){
    const int count = 24;

    int array[num]; //error, num 是一个只读变量， 不是常量

    //  在定义常量时，const 和 constexpr 是等价的，都可以在程序的编译阶段计算出结果
    const int i = 0;
    const int j = i+1;

    constexpr int a = 0;
    constexpr int b = a + 1;

    int a1 = 11;
    int a2 = 22;

    int& x = a1;

    const int & y = a1;

}




int main(int argc, char const *argv[])
{



    return 0;
}
