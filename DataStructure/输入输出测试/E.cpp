/*
输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
接下来t行, 每行一组数据。
每行的第一个整数为整数的个数n(1 <= n <= 100)。
接下来n个正整数, 即需要求和的每个正整数。

输入例子1:
    2
    4 1 2 3 4
    5 1 2 3 4 5

输出例子1:
    10
    15
*/
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n=0;
    cin>>n;
    while(n--){
        int num=0, sum=0, size=0;
        cin>>size;
        for(int i=0; i<size; i++){
            cin>>num;
            sum+=num;
        }
        cout<<sum<<endl;
    }
    return 0;
}