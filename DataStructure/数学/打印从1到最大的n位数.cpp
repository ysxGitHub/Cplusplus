/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3
    一直到最大的 3 位数 999。
*/

#include <iostream>
#include <vector>
using namespace std;


bool overflow(string& s){
    bool isOverflow = false;
    bool carry = false;
    int n = s.size();
    for(int i=n-1; i>=0; i--){
        int num = s[i] - '0' + carry;
        if(i == n-1) num++;
        if(num>=10){
            if(i==0) isOverflow = true;
            carry = true;
            s[i] = num - 10 + '0';
        }else{
            s[i] = num + '0';
            break;
        }
    }
    return isOverflow;
}

void inputNum(string& s){
    bool isZeroFront = true;
    for(int i=0; i<s.size(); i++){
        if(isZeroFront && s[i] != '0') isZeroFront = false;
        if(!isZeroFront) cout<<s[i];
    }
    cout<<", ";
}

void printNumbers(int n) {
    string s(n, '0');
    while(!overflow(s)){
        inputNum(s);
    }
}
int main(int argc, char const *argv[])
{
    printNumbers(10);
    return 0;
}
