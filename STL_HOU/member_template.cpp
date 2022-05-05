template<class T1, class T2>
struct pair
{
    T1 first;
    T2 second;
    pair():first(T1()), second(T2())
    {

    }
    pair(const T1& a, const T2& b):first(a),second(b)
    {

    }
    // 成员模板
    template<class U1, class U2>
    pair(const pair<U1, U2>& p):first(p.first), second(p.second){}
};



class Base1{};
class Derived1: public Base1
{

};

class Base2{};
class Derived2: public Base2
{

};

pair<Derived1, Derived2>p;
pair<Base1, Base2>p2(p);


// 特化
template<>
struct hash<int>
{
    /* data */
};

// 偏特化（参数个数）
template<class T>
class vector<bool, T>
{

};

// 偏特化
template <class T>
class stack
{

};

// 偏特化（范围），接收指针类型的
template <class U>
class stack<U*>
{

};

// 类模板不能自己推到参数类型，而函数模板可以直接推到参数类型
