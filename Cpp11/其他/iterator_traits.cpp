#include <vector>
#include <iostream>
using namespace std;

template<typename iter>
struct iter_traits{
    typedef typename iter::value_type        value_type;
};

template<typename T>
struct iter_traits<T*>{
    typedef T								 value_type;
};

template<typename T>
struct iter_traits<const T*>{
    typedef T								 value_type;
};

//iter_traits向myalgorithm提供了native pointer的value_type的属性
template<typename iter>
void myalgorithm(iter first,iter last){
    typename iterator_traits<iter>::value_type val;
    while(first!=last){
        val=*first;
        cout<<val<<'\t';
        ++first;
    }
    cout<<'\n';
}

int main() {
    int ZDD[7]={1,2,3,4,5,6,7};
    vector<int> WSS(begin(ZDD),end(ZDD));
    cout<<"ZDD: "<<'\n';
    myalgorithm(ZDD,ZDD+7);
    cout<<"WSS: "<<'\n';
    myalgorithm(WSS.begin(),WSS.end());
    //
}