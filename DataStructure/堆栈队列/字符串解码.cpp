/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。
    注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
*/

#include<stack>
#include<string>
#include<iostream>
using namespace std;

string decodeString(string s) {
    string ans;
    int n=s.size();
    stack<int> cnt;  // 记录重复次数
    stack<int> idx;  // 记录[]生成的字符串起点
    for(int i=0;i<n;i++) {
        if(isalpha(s[i])) {
            ans+=s[i];
        } else if(s[i]==']') {
            string temp=ans.substr(idx.top()); idx.pop();  // []中生成的字符串
            int count=cnt.top();cnt.pop();
            for(int j=1;j<count;j++) {  // 重复n-1次
                ans+=temp;
            }
        } else { // 数值 或 '['
            int start=i;
            while(isdigit(s[i])) i++;
            cnt.push(stoi(s.substr(start,i-start)));
            idx.push(ans.size());
        }
    }
    return ans;
}
// isalpha
// isdigit