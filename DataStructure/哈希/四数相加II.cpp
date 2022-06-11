/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int ans = 0;
    unordered_map<int, int>ab;
    for(auto&num1: nums1){
        for(auto&num2: nums2){
            ab[num1+num2]++;
        }
    }
    for(auto&num3: nums3){
        for(auto&num4: nums4){
            ans += ab[-num3-num4];
        }
    }
    return ans;
}