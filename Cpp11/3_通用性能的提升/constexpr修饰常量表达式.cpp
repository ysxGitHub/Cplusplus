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


// 变量只读并不等价于常量，二者是两个概念不能混为一谈
void test(){
    int a1 = 520;
    int a2 = 250;
    const int& b = a1;
    b = a2;    // error

    /*
        b 是一个常量的引用，所以 b 引用的变量是不能被修改的，也就是说 b = a2; 这句代码语法是错误的。
        在 const 对于变量 a1 是没有任何约束的，a1 的值变了 b 的值也就变了
        引用 b 是只读的，但是并不能保证它的值是不可改变的，也就是说它不是常量。
    */
}

/*
在使用中建议将 const 和 constexpr 的功能区分开，即凡是表达“只读”语义的场景都使用 const，表达“常量”语义的场景都使用 constexpr。
*/

int main(int argc, char const *argv[])
{



    return 0;
}
