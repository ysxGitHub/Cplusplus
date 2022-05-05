#include<iostream>
using namespace std;


template<class R, class T, typename U>
R add(T x, U y){
    return x + y;
}

template<class T, typename U>
auto sub(T x, U y) -> decltype(1 - 0.1){ // 返回类型后置

    return x - y ;
}


int main(int argc, char const *argv[])
{
    int x = 2;
    double y = 1.2;

    // 这种做法不合理，函数内部不一定是返回（x+y）类型，我们不知道模板内部的实现
    auto ret = add<decltype(x+y), int, double>(x,y);
    cout<<"ret: "<<ret<<endl;

    // 返回类型后置
    auto ret1 = sub(x, y);
    cout<<"ret1: "<<ret1<<endl;

    return 0;
}



