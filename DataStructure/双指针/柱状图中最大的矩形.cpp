/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

#include <stack>
#include <vector>

using namespace std;

// 双指针 超时
int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    for(int i=0; i<heights.size(); i++){
        int left = i, right = i;
        for(; left>=0; --left){
            if(heights[i]>heights[left]) break;
        }
        for(; right<heights.size(); ++right){
            if(heights[i]>heights[right]) break;
        }
        res += (right-left-1)*heights[i];
    }
    return res;
}

// 动态规划
int largestRectangleArea(vector<int>& heights) {
    int res = 0, n = heights.size();
    vector<int>leftminIndex(n);
    vector<int>rightminIndex(n);
    leftminIndex[0] = -1; // 注意这里初始化，防止下面while死循环
    rightminIndex[n-1] = n; // 注意这里初始化，防止下面while死循环

    // 记录每个柱子 左边第一个小于该柱子的下标
    for(int i=1; i<n; ++i){
        int t = i-1;
        while(t>=0&&heights[t]>=heights[i]) t = leftminIndex[t];
        leftminIndex[i] = t;
    }

    // 记录每个柱子 左边第一个小于该柱子的下标
    for(int i=n-2; i>=0; --i){
        int t = i+1;
        while(t<n&&heights[t]>=heights[i]) t = rightminIndex[t];
        rightminIndex[i] = t;
    }
    for(int i=0; i<n; ++i){
        res = max(res, heights[i]*(rightminIndex[i]-leftminIndex[i]-1));
    }

    return res;
}


// 单调栈
int largestRectangleArea(vector<int>& heights) {
    // 前后插入元素 0
    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    int n = heights.size();
    stack<int>st;

    int res = 0;
    for(int i=0; i<n; ++i){
        // 维护一个单减栈
        while(!st.empty()&&heights[st.top()]>heights[i]){
            int mid = st.top();
            st.pop();
            if(st.empty()) break;
            int w = i - st.top() - 1;
            res = max(res, w*heights[mid]);
        }
        st.push(i);
    }
    return res;
}