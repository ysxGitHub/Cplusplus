// 重载++是用i++调用++i
// stack和queue都不允许遍历，也不提供iterator
// stack和queue都可选择list或deque做为底层结构
// queue不可以选择vector做为底层结构
// stack可以选择vector做为底层结构
// stack和queue都不可选择set或map做为底层结构

#include <iostream>
#include <bits/stl_tree.h>
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<isdigit('a')<<endl;
    cout<<isdigit('1')<<endl; 

    // _Identity<int>: 输入5返回5，less<int> ’<‘返回真
    _Rb_tree<int, int, _Identity<int>, less<int>> itree;
    cout<<itree.empty()<<endl;
    cout<<itree.size()<<endl;

    itree._M_insert_unique(3);
    itree._M_insert_unique(8);
    itree._M_insert_unique(5);
    itree._M_insert_unique(9);
    itree._M_insert_unique(13);
    itree._M_insert_unique(5);
    
    cout<< itree.empty()<<endl;
    cout<< itree.size()<<endl;
    cout<< itree.count(5)<<endl;

    itree._M_insert_equal(5);
    cout<< itree.size()<<endl;
    cout<< itree.count(5)<<endl;    

    return 0;
}

