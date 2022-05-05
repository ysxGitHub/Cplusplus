/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


// 动态规划 + stack
int longestValidParentheses(string s) {
    int n = s.size();
    stack<int>stk;
    // dp[i] 的定义：记录以 s[i-1] 结尾的最长合法括号子串长度
    vector<int> dp(n+1);
    for(int i=0; i<n; i++){
        if(s[i]==')'){
            if(!stk.empty()){
                // 配对的左括号对应索引
                int leftidx = stk.top();
                stk.pop();
                // 以这个右括号结尾的最长子串长度
                int len = 1 + i - leftidx + dp[leftidx];
                dp[i + 1] = len;
            }else{
                // 没有配对的左括号
                dp[i + 1] = 0;
            }

        }else{
            stk.push(i);
            // 左括号不可能是合法括号子串的结尾
            dp[i + 1] = 0;
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// stack
/*
对于遇到的每个 ‘(’ ，我们将它的下标放入栈中
对于遇到的每个 ‘)’ ，我们先弹出栈顶元素表示匹配了当前右括号：
    如果栈为空，说明当前的右括号为没有被匹配的右括号，我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
    如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」

我们始终保持栈底元素为当前已经遍历过的元素中「最后一个没有被匹配的右括号的下标」，这样的做法主要是考虑了边界条件的处理，栈里其他元素维护左括号的下标：
*/

int longestValidParentheses1(string s) {
    int n = s.size();
    stack<int>stk;
    stk.push(-1);
    int maxlen = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='('){
            stk.push(i);
        }else{
            if(!stk.empty()) stk.pop();
            if(!stk.empty()){
                maxlen = max(maxlen, i-stk.top());
            }else{
                stk.push(i);
            }
        }
    }
    return maxlen;
}