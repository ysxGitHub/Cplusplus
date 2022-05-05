/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

注意 '*' 表示前一个字符的数量, 如 "a*" 可以是 "", "a", "aa", "aaa".... 
*/

#include<iostream>
#include<unordered_map>
using  namespace std;


unordered_map<int, bool> memo;
bool dp(string& s, int i, string& p, int j){
    int m = s.size(), n = p.size();
    // p 已经完成 s 是否匹配完成
    if(j == n) return i == m;
    // m 已经完成 j 是否完成, 或者 类似"X*Y*Z*"
    if(i == m){
        if((n - j)%2 == 1) return false;
        for(; j + 1 < n; j += 2){
            if(p[j + 1]!='*') return false;
        }
        return true;
    }
    int key = i * n + j;
    // 如果备忘录包括了当前的状态
    if(memo.count(key)) return memo[key];
    bool res = false;

    // 匹配时
    if(s[i] == p[j] || p[j] == '.'){
        // p 的下一个字符为 "*"
        if(j + 1 < n && p[j + 1] == '*'){
            // "*" 匹配 0 个 或 多个 s 中的字符时
            res = dp(s, i, p, i + 2)||dp(s, i + 1, p, j);
        }else{
            // 正常 匹配
            res = dp(s, i + 1, p, i + 1);
        }

    }else{
        if(j + 1 < n && p[j + 1] == '*'){
            // "*" 匹配 0 个
            res = dp(s, i, p, i + 2);
        }else{
            res = false;
        }

    }
    memo[key] = res;
    return res;
}


bool isMatch(string s, string p) {
    return dp(s, 0, p, 0);
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
