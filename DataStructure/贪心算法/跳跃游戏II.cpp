/*
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。

*/

#include<iostream>
#include<vector>

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int end = 0, farthest = 0;
    int jumps = 0;
    for (int i = 0; i < n - 1; i++) {
        if(farthest>=i){
            farthest = max(nums[i] + i, farthest);
            if (end == i) {
                jumps++;
                end = farthest;
            }            
        }
    }
    return jumps;
}

int main(int argc, char const *argv[])
{
    vector<int>nums={3,1,3};
    cout<<jump(nums)<<endl;    
    return 0;
}
