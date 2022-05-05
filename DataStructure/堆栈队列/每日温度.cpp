/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
    其中 answer[i] 是指在第 i 天之后，才会有更高的温度。如果气温在这之后都不会升高，
    请在该位置用 0 来代替。
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int len = temperatures.size();
    vector<int> ans(len);
    // 这里存储温度的index就行
    stack<int> s;

    for(int i=len-1; i>=0; i--){
        // 这里注意要可以等于
        while(!s.empty()&&temperatures[i]>=temperatures[s.top()]){
            s.pop();
        }
        ans[i] = s.empty() ? 0 : s.top() - i;
        s.emplace(i);
    }
    return ans;
}