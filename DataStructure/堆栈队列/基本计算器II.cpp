/*
s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
*/

#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
#include<numeric>

using namespace std;

int calculate(string s) {
    int n = s.size();
    char sign = '+';
    vector<int>res;
    int num = 0;
    for(int i=0; i<n; i++){
        char c = s[i];
        if(c>='0'&&c<='9'){
            num = num*10 + (c-'0');
        }
        if((c!=' '&&(c<'0'||c>'9'))||i==n-1){
            if(sign=='+'){
                res.push_back(num);
            }else if(sign=='-'){
                res.push_back(-num);
            }else if(sign=='*'){
                res.back()*=num;
            }else if(sign=='/'){
                res.back()/=num;
            }
            sign = c;
            num=0;                
        }
    }
    return accumulate(res.begin(), res.end(), 0);
}
