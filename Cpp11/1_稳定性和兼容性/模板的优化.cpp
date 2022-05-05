/*
在泛型编程中，模板实例化有一个非常繁琐的地方，
    那就是连续的两个右尖括号（>>）会被编译器解析成右移操作符，而不是模板参数表的结束。
*/

// test.cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Base {
public:
    void traversal(T& t)
    {
        auto it = t.begin();
        for (; it != t.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
};


int main1()
{
    vector<int> v{ 1,2,3,4,5,6,7,8,9 };
    // c++11 之前 当成 右移操作符 >>
    Base<vector<int>> b;
    b.traversal(v);

    return 0;
}


// C++11类模板可以有默认的模板参数, 在C++11中添加了对函数模板默认参数的支持:

template<class T = long, typename U = int>
void mytest(T t='a', U u='b'){ // 默认的函数参数不能进行类型推导
    cout<<"t: "<<t<<", u: "<<u<<endl;
}

int main(int argc, char const *argv[])
{
    mytest('a', 'b');  // mytest<char, char>
    mytest<int>('a', 'b');  // mytest<int, char>
    mytest<char>('a', 'b');  // mytest<char, char>
    mytest<char, int>('a', 'b');  // mytest<char, int>
    mytest<int, char>('a', 'b');  // mytest<int, char>
    mytest();  // mytest<long, int>

    // 模板类 有 默认的参数 ，调用时要写 <>  如 Test<> t;

    return 0;
}
