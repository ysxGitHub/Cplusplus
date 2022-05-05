/*
给你一个二进制数组 nums ，你需要从中删掉一个元素。

请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。

如果不存在这样的子数组，请返回 0 。
*/
/*
思想类似 : 最大连续1的个数III
        1替换0最长的1子序列，最后结果减1
*/

#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int start=0, maxLen=0, cntOne=0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i]) cntOne++;
        maxLen = max(maxLen, cntOne);
        if(i - start + 1 > maxLen + 1){
            if(nums[start]) cntOne--;
            start++;
        }
    }
    return n - start - 1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
