
// 1.不能作为函数的参数使用
// error
int func(auto a, auto b){

}

// 2.不能用于类的非静态变量的初始化
class Test{
    auto v1 = 0; // error
    static auto v2 = 0; // error
    static const auto v3 = 0; // correct
};



int t[] = {1,2,3};
// 3.不能定义数组
auto t1[] = {1,2,3} // error
auto t2[] = t; // error
auto t3 = t; // ok



template<class T>
struct Test1{

};

Test1<double> x;
// 4.无法推导出模板类型
Test1<auto> x1 = x; // error







