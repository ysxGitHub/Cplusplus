/*
如果输入为0 0则结束输入
输入例子1:
    1 5
    10 20
    0 0

输出例子1:
    6
    30
*/
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    while(cin>>a>>b){
        if(a==0&&b==0) break;
        cout<<a+b<<endl;
    }
    return 0;
}
