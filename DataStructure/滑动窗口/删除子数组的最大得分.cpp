/*
给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。
    删除子数组的 得分 就是子数组各元素之 和 。

返回 只删除一个 子数组可获得的 最大得分 。

如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，
    那么它就是 a 的一个子数组。
*/
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int>seen;
    int sum = 0, start = 0;
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        int c = nums[i];
        sum += c;
        while(seen.find(c)!=seen.end()){
            sum -= nums[start];
            seen.erase(nums[start]);
            start++;
        }
        ans = max(ans, sum); 
        seen.insert(c);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
