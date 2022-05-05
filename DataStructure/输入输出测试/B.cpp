/*
输入例子2:
    4
    1 5
    2 3
    10 20
    20 40
输出例子1:
    6
    5
    30
    60
*/
#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int n, a, b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        cout<<a+b<<endl;
    }
    return 0;
}

