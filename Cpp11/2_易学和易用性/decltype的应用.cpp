#include<iostream>
#include<list>
using namespace std;

// 用于泛型编程

template<class T>
class Container{
public:
    void print(T& t){
        for(m_it = t.begin(); m_it!=t.end(); ++m_it){
            cout<<"value: "<<*m_it<<", ";
        }
    }

private:
    // 注意这里必须加上 typename, 否则编译器认为 T::iterator 是类的成员
    typename T::iterator m_it1; // or ok

    decltype(T().begin()) m_it;
};

int main1(int argc, char const *argv[])
{
    list<int> ls = {1,2,3,5};
    Container<list<int>> c;
    c.print(ls);
    cout<<endl;

    const list< int> ls1 = {1,2,3,5};
    Container<const list<int>> c1;
    c1.print(ls1);
    return 0;
}
