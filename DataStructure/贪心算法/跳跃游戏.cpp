/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
*/
#include<iostream>
#include<vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    // 能覆盖的最远距离
    int farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        if(farthest>=i){
            // 更新覆盖的最远距离
            farthest = max(nums[i] + i, farthest); 
            // 如果超过了就可以  
            if(farthest>=n-1) return true;  
        }
    }
    return false;
}

// 从后向前，当前的位置 + 当前的数值 是否能到达 back
bool canJump1(vector<int>& nums) {
    int n = nums.size();
    // back 开始在最后位置
    int back = n-1;
    for(int i = n-2; i>=0; i--){
        // 可以到达 back 更新back
        if(i+nums[i]>=back) back = i;

    }
    return back==0;
}


int main(int argc, char const *argv[])
{
    vector<int>nums={3,2,1,0,4};
    cout<<canJump1(nums)<<endl;
    return 0;
}
