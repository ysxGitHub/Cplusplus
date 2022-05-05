#include<iostream>
using namespace std;
#include<stack>
#include<algorithm>

/*
stack符合先进后出的原则，
不容许有遍历的行为，

*/ 



int main(int argc, char const *argv[])
{
    //
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    
    // 拷贝构造
    stack<int>s2(s1);

    cout<<"size: "<<s1.size()<<endl;
    while (!s1.empty())
    {
        cout<<"stack pop: "<<s1.top()<<endl;
        s1.pop();
    }

    return 0;
}
