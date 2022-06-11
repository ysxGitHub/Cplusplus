/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

/*
不要想整体，而应该去想局部
仅仅对于位置 i，能装下多少水呢？
位置 i 最大的水柱高度就是 min(l_max, r_max)
*/
int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n-1;
    int l_max = 0, r_max = 0;
    int ans = 0;
    while(left<right){
        // 计算当前左边最大和右边最大的元素
        l_max = max(l_max, height[left]);
        r_max = max(r_max, height[right]);
        // 找到最小的一边，计算当前位置可以盛放的水
        if(l_max > r_max){
            ans += r_max - height[right];
            right--;
        }else{
            ans += l_max - height[left];
            left++;
        }
    }
    return ans;
}

// dp
int trap1(vector<int>& height) {
    int ans = 0;
    int n = height.size();
    vector<int> left_max(n);
    vector<int> right_max(n);
    // 初始化 base case
    left_max[0] = height[0];
    right_max[n-1] = height[n-1];
    // 从左向右计算 l_max
    for(int i=1; i<n; i++){
        left_max[i] = max(left_max[i-1], height[i]);
    }
    // 从右向左计算 r_max
    for(int i=n-2; i>=0; i--){
        right_max[i] = max(right_max[i+1], height[i]);
    }

    for(int i=1; i<n-1; i++){
        ans += min(right_max[i], left_max[i]) - height[i];
    }
    return ans;

}

int trap2(vector<int>& height) {
    int n = height.size();
    int ans = 0;
    stack<int>stk;
    for(int i=0; i<n; i++){
        // 如果当前的高度高于之前的高度就可以计算 left mid i 之间的雨水量
        while(!stk.empty()&&height[i]>height[stk.top()]){
            int mid = stk.top();
            stk.pop();
            if(stk.empty()){break; }
            int left = stk.top();
            // 计算宽度
            int w = i - left - 1;
            // - height[mid] 因为底下一层已经计算过，只计算现在这一层的宽度
            int h= min(height[left], height[i]) - height[mid];
            ans += w * h;
        }
        stk.emplace(i);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int>height = {4,3,2,0,1,1,5};
    cout<<trap2(height);
    return 0;
}
