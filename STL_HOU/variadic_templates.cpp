#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

void print(){}

template<typename T, typename...Types>
void print(const T& firstArg, const Types&... args)
{
    cout<<firstArg<<endl;
    print(args...);
}


int main(int argc, char const *argv[])
{
    print(7.5, "hello", bitset<16>(112), 42);
    vector<int>v1;
    // 
    for(int i:{1,2,3,4,5,6})
    {
        v1.push_back(i);
    }
    // vector<int>::iterator it = auto
    for(auto elem: v1)
    {
        cout<<elem<<" ";
    }
    for(auto& elem: v1)
    {
        elem*= 10;
    }
    for(auto elem: v1)
    {
        cout<<elem<<" ";
    }
    return 0;
}



