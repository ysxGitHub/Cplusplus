/*
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
*/
#include<stack>
#include<iostream>

using namespace std;

int calculate(string s) {
    stack<int>stk;
    stk.push(1);
    int n = s.size();
    int i=0, res=0, sign = 1;
    while(i<n){
        if(s[i]==' '){
            i++;
        }else if(s[i]=='('){
            i++;
            stk.push(sign);
        }else if(s[i]==')'){
            i++;
            stk.pop();
        }else if(s[i]=='+'){
            sign = stk.top();
            i++;
        }else if(s[i]=='-'){
            sign = -stk.top();
            i++;
        }else{
            int sum = 0;
            while(i<n&&s[i]>='0'&&s[i]<='9'){
                sum = sum*10 + (s[i]-'0');
                i++;
            }
            res += sign*sum;
        }
    }
    return res;
}

