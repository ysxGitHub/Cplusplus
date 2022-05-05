
/*
输入数据包括多组。
每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
接下来n个正整数,即需要求和的每个正整数。


输入例子1:
    4 1 2 3 4
    5 1 2 3 4 5
    0

输出例子1:
    10
    15
*/
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n=0;
    while(cin>>n){
        if(n==0) break;
        int num=0, sum=0;
        for(int i=0; i<n; i++){
            cin>>num;
            sum+=num;
        }
        cout<<sum<<endl;
    }
    return 0;
}