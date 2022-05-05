/*
输入描述:
    输入数据有多组, 每行表示一组输入数据。
    每行不定有n个整数，空格隔开。(1 <= n <= 100)。

输出描述:
    每组数据输出求和的结果

输入例子1:
    1 2 3
    4 5
    0 0 0 0 0

输出例子1:
    6
    9
    0
*/


#include<iostream>
using namespace std;



int main(int argc, char const *argv[])
{
    int num=0, sum=0;
    while(cin>>num){
        sum += num;
        if(cin.get()=='\n'){
            cout<<sum<<endl;
            sum=0;
        }
    }

    return 0;
}
