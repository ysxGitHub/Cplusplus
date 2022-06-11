/*
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。
*/

// 计数排序
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> cnt(101, 0);
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        cnt[nums[i]]++;
    }
    for (int i = 1; i <= 100; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        ret.push_back(nums[i] == 0 ? 0: cnt[nums[i]-1]);
    }
    return ret;
}