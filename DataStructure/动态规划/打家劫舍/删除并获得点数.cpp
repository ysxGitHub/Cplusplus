/*
给你一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
*/

// #include<unordered_map>
// #include<set>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    vector<int>nnums(10001);
    for(auto&num: nums){
        nnums[num] += num;
    }
    vector<int>dp(10001);
    dp[0] = 0;
    dp[1] = nnums[1];
    for(int i=2; i<10001; i++){
        dp[i] = max(dp[i-1], dp[i-2]+nnums[i]);
    }
    return dp[10000];
}


int rob(vector<int> &nums) {
    int size = nums.size();
    if (size == 1) {
        return nums[0];
    }
    int first = nums[0], second = max(nums[0], nums[1]);
    for (int i = 2; i < size; i++) {
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}

int deleteAndEarn(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(), nums.end());
    vector<int> sum = {nums[0]};
    for (int i = 1; i < n; ++i) {
        int val = nums[i];
        if (val == nums[i - 1]) {
            sum.back() += val;
        } else if (val == nums[i - 1] + 1) {
            sum.push_back(val);
        } else {
            ans += rob(sum);
            sum = {val};
        }
    }
    ans += rob(sum);
    return ans;
}



int main(int argc, char const *argv[])
{


    return 0;
}
