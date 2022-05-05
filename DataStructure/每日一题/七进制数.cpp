/*
给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
*/
#include <iostream>
#include <vector>
using namespace std;


string convertToBase7(int num) {
    if(num==0){return "0";}
    int flag=1;
    if(num<0){flag=0; }
    string ans;
    while(num){
        string tmp = to_string(abs(num%7));
        num = num/7;
        tmp += ans;
        ans = tmp;
    }
    if(flag==0){ans = "-"+ans; }
    return ans;    
}