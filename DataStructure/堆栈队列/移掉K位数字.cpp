/*
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，
    使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

思想：
    贪心+stack
*/
#include<vector>
#include<iostream>
using namespace std;

string removeKdigits(string num, int k) {
    // 利用vector充当stack
    vector<char> stk; 
    for(char c: num){
        // while弹出前一个比自己大的元素
        while(k&&!stk.empty()&&stk.back()>c){
            stk.pop_back();
            --k;
        }
        stk.emplace_back(c);
    }
    // 降序时上面的k不会一直减减，所有要判断一下是否k==0
    while(k){
        stk.pop_back();
        --k;
    }
    bool startZero = 1;
    string ans = "";
    for(char c: stk){
        // 去掉开头的 "0"
        if(startZero && c=='0'){
            continue;
        }
        startZero = 0;
        ans += c;
    }
    return ans == "" ? "0" : ans;
}


int main(int argc, char const *argv[])
{
    cout<<removeKdigits("10200", 1);
    return 0;
}


