/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
    你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

*/
#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int>dq;
    vector<int> ans;
    for(int i=1; i<=nums.size(); i++){
        while(!dq.empty()&&nums[i-1]>nums[dq.back()]){
            dq.pop_back();
        }
        dq.emplace_back(i-1);
        if(i>=k){
            // 注意这里的dq.front()范围还是[0, n-1],所以i-k不用加1
            while(!dq.empty()&&dq.front()<i-k){
                dq.pop_front();
            }
            ans.emplace_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
