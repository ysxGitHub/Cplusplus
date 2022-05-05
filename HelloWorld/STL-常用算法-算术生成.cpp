#include<iostream>
using namespace std;
#include<vector>
#include<numeric>

template<class T>
void printAll(const T& vp)
{
    for(class T::const_iterator it=vp.begin(); it!=vp.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    vector<int>v1;
    for(int i=1; i<101; i++)
    {
        v1.push_back(i);
    }

    // 起始累加值为0
    cout<<"accumulate: "<<accumulate(v1.begin(), v1.end(), 0)<<endl;
    
    vector<int>v2;
    for(int i=0; i<8; i++)
    {
        v2.push_back(i);
    }
    // 填充数值
    fill(v2.begin(), v2.end(), 10);
    printAll<vector<int>>(v2);


    return 0;
}
