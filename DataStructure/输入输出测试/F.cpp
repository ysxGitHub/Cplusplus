
/*
输入描述:
    输入数据有多组, 每行表示一组输入数据。
    每行的第一个整数为整数的个数n(1 <= n <= 100)。
    接下来n个正整数, 即需要求和的每个正整数。

输出描述:
    每组数据输出求和的结果

输入例子1:
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
    int n;
    while(cin>>n){
        int num, sum=0;
        for(int i=0; i<n; i++){
            cin>>num;
            sum+=num;
        }
        cout<<sum<<endl;
    }
    return 0;
}
