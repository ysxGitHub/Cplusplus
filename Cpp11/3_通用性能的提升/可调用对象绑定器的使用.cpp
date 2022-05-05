#include <iostream>
#include <functional>
using namespace std;

class Test{
public:
    void output(int x, int y){

        cout << x << " " << y << endl;
    }
    int m_num = 100;
};



int main(int argc, char const *argv[])
{
    Test t;
    // 绑定成员函数，得到仿函数
    auto f1 = bind(&Test::output, &t, 11, placeholders::_1);
    f1(12);

    // 包装，得到包装器类型 做了一个隐式转换
    function<void(int, int)> f11 = bind(&Test::output, &t, 11, placeholders::_1);


    // 绑定成员变量
    auto f2 = bind(&Test::m_num, &t);
    cout<<f2()<<endl;
    f2() = 22;
    cout<<f2()<<endl;

    // 包装
    function<int&(void)> f22 = bind(&Test::m_num, &t);

    return 0;

}
