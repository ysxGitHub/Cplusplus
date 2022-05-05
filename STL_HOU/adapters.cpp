
// 适配器可以是继承父类，适配器内含其他类
// 适配器内含容器、仿函数、 迭代器
// stack, queue 内含 Sequence

/*
typename的使用场合
用处1, 用在模板定义里, 标明其后的模板参数是类型参数。
    template<typename T, typename Y>
    T foo(const T& t, const Y& y){//....};

用处2, 模板中标明“内嵌依赖类型名”
    typename iterator_traits<_InputIter>::difference_type
    typename iterator_traits<_InputIter>::value_type
    typename iterator_traits<_InputIter>::difference_type __n = 0;

difference_type， value_type就是依赖于_InputIter（模板类型参数）的类型名。源码如下：
    template <class _Iterator>
    struct iterator_traits {
    typedef typename _Iterator::iterator_category iterator_category;
    typedef typename _Iterator::value_type    value_type;
    typedef typename _Iterator::difference_type  difference_type;
    typedef typename _Iterator::pointer      pointer;
    typedef typename _Iterator::reference     reference; };

内嵌是指定义在类名的定义中的。以上difference_type和value_type都是定义在iterator_traits中的。
依赖是指依赖于一个模板参数。 typename iterator_traits<_inputiter>::difference_type中
    difference_type依赖于模板参数_InputIter。

类型名是指这里最终要指出的是个类型名，而不是变量。
例如iterator_traits<_inputiter>::difference_type完全有可能是
    类iterator_traits<_inputiter> 类里的一个static对象。而且当我们这样写的时候，
    C＋＋默认就是解释为一个变量的。所以，为了和变量区分，必须使用typename告诉编译器。

那么是不是所有的T::type_or_variable, 或者tmpl:type_or_variable都需要使用typename呢？
    不是，有以下两个例外。

例外
    （1）类模板定义中的基类列表。
    template<class T>
    class Derived: public Base<T>::XXX
    {
    ...
    }

    （2）类模板定义中的初始化列表。
    Derived(int x) : Base<T>::xxx(x)
    {
    ...
    }
为什么这里不需要呢？因为编译器知道这里需要的是类型还是变量，
（1）基类列表里肯定是类型名，（2）初始化列表里肯定是成员变量名。

*/

/*
class MyArray 
{ 
public:
  typedef int LengthType;
};
 
template<class T>
void MyMethod( T myarr ) 
{ 
  typedef typename T::LengthType LengthType; 
  LengthType length = myarr.GetLength; 
};
这个时候typename的作用就是告诉c++编译器，typename后面的字符串为一个类型名称，
而不是成员函数或者成员变量，这个时候如果前面没有
typename，编译器没有任何办法知道T::LengthType是一个类型还是一个成员名称(静态数据成员或者静态函数)，
所以编译不能够通过。
*/

#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>

using namespace std::placeholders; //adds visibility of _1, _2, _3
using namespace std;

double my_div(double x, double y){
    return x/y;
}

class MyPair{
public:
    double a,b;
    double mult(){
        return a*b;
    }
};

int main(int argc, char const *argv[])
{
    auto fn_five = bind(my_div, 10, 2);
    cout<< fn_five()<<endl;

    auto fn_half = bind(my_div, _1, 2);
    cout<< fn_half(10)<<endl;

    auto fn_invert = bind(my_div, _2, _1);
    cout<< fn_invert(10, 2)<<endl;

    // bind <int>返回类型
    auto fn_rounding = bind<int>(my_div, _1, _2);
    cout<<fn_rounding(10, 3)<<endl;

    MyPair ten_two{10, 2};
    // 这里的_1表示 this
    auto bound_memfn = bind(&MyPair::mult, _1);
    cout<<bound_memfn(ten_two)<<endl;

    auto bound_menmdata = bind(&MyPair::a, ten_two);
    cout<<bound_menmdata()<<endl;

    auto bound_menmdata2 = bind(&MyPair::b, _1);
    cout<<bound_menmdata2(ten_two)<<endl;

    vector<int> v {15,20,49,50,74,58,29,98};
    int n = count_if(v.cbegin(), v.cend(), not1(bind2nd(less<int>(),50)));
    cout<<"n= "<<n<<endl;

    auto fn_ = bind(less<int>(), _1, 50);
    // const begin()
    cout<<count_if(v.cbegin(), v.cend(), fn_)<<endl;
    cout<<count_if(v.begin(), v.end(), bind(less<int>(), _1, 50))<<endl;


    
    return 0;
    
}
