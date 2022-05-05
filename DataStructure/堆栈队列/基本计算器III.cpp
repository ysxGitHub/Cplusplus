/*
s 由整数和算符 ('(', ')', '+', '-', '*', '/') 组成，中间由一些空格隔开
*/
#include<bits/stdc++.h>

using namespace std;

int helper(string& s, int& index) {
    int n = s.size();
    vector<int>res;
    char sign = '+';
    int num = 0;
    for(index; index<n; index++){
        char c = s[index];
        if(isdigit(c)){
            num = num*10 + (c-'0');
        }
        if(c=='('){
            index++;
            num = helper(s, index);
        }
        if((c!=' '&&!isdigit(c))||index==n-1){
            if(sign=='+'){
                res.push_back(num); 
            }else if(sign=='-'){
                res.push_back(-num); 
            }else if(sign=='*'){
                res.back()*=num;
            }else if(sign=='/'){
                res.back()/=num;
            }
            num=0;
            sign = c;
        }
        if(c==')') break;
    }
    return accumulate(res.begin(), res.end(), 0);
}

int calculate(string s) {
    int index = 0;
    return helper(s, index);
}


int main(int argc, char const *argv[])
{
    cout<<calculate("1 +5 *(2+ 5)+ 1 + (2+8)/5");
    return 0;
}
