/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
    例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int lengthOfLIS1(vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    // 每个牌堆的堆顶元素
    vector<int>heapTop;
    // 牌堆数量
    int piles = 0;
    for(int i=0; i<n; i++){
        int left = 0, right = piles, poker=nums[i];
        // cout<<left<<","<<right<<"; ";
        while(left<right){
            int mid = left + (right - left)/2;
            if(heapTop[mid] >= poker){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        if(left == piles){
            // 所有的堆顶都小于该张牌，所以新建一个堆，并将该元素放入 牌堆的堆顶
            piles++;
            heapTop.emplace_back(poker);
        }else{
            //找到了放置该牌的合适的堆顶，将堆顶的元素进行替换
            heapTop[left] = poker;
        }

    }
    return piles;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {0,1,2,3,2,3};
    cout<<lengthOfLIS1(nums)<<endl;
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}
