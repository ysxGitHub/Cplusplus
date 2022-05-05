
#include <iostream>
using namespace std;

class Test
{
public:
    Test(int) {}
private:
    Test(const Test &);
};

int main(void)
{
    Test t1(520);  // 构造
    Test t2 = 520;  // 隐式类型转换
    Test t3 = { 520 };  // 初始化列表
    Test t4{ 520 };  // 初始化列表

    int a1 = { 1314 };  // 初始化列表
    int a2{ 1314 };  // 初始化列表
    int arr1[] = { 1, 2, 3 };  // 初始化列表
    int arr2[]{ 1, 2, 3 };  // 初始化列表

    int * p = new int{520};  // 初始化列表
    double b = double{52.134};  // 初始化列表
    int * array = new int[3]{1,2,3};  // 初始化列表


    return 0;
}
