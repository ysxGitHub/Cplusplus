#include <iostream>
using namespace std;

class Test1{
public:
    Test1() {};
    Test1(int max){
        this->m_max = max > 0 ? max : 100;
    }

    Test1(int max, int min){
        this->m_max = max > 0 ? max : 100;              // 冗余代码
        this->m_min = min > 0 && min < max ? min : 1;
    }

    Test1(int max, int min, int mid){
        this->m_max = max > 0 ? max : 100;             // 冗余代码
        this->m_min = min > 0 && min < max ? min : 1;  // 冗余代码
        this->m_middle = mid < max && mid > min ? mid : 50;
    }

    int m_min;
    int m_max;
    int m_middle;
};


/*
这种链式的构造函数调用不能形成一个闭环（死循环），
    否则会在运行期抛异常。
如果要进行多层构造函数的链式调用，建议将构造函数的调用的写在初始列表中而不是函数体内部，
    否则编译器会提示形参的重复定义。
在初始化列表中调用了代理构造函数初始化某个类成员变量之后，
    就不能在初始化列表中再次初始化这个变量了。
*/
class Test{
public:
    Test() {};
    Test(int max){
        this->m_max = max > 0 ? max : 100;
    }

    Test(int max, int min): Test(max) {
        // Test(max) // error;
        this->m_min = min > 0 && min < max ? min : 1;
    }

    Test(int max, int min, int mid): Test(max, min) {
        this->m_middle = mid < max && mid > min ? mid : 50;
    }

    int m_min;
    int m_max;
    int m_middle;
};
