/*
给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0 。

您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。

*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if(n<2) return 0;
    int maxn = INT32_MIN, minn = INT32_MAX;

    for(auto&num: nums){
        maxn = max(maxn, num);
        minn = min(minn, num);
    }

    // 相邻数字的最大间距不会小于 (max−min)/(N−1)。
    // 我们将整个区间划分为若干个大小为整数 d = (max−min)/(N−1) 的桶，并找出每个整数所在的桶。
    int d = max(1, (maxn - minn) / (n - 1));
    int buckets = (maxn - minn) / d + 1;

    // 存放每个桶中的最大最小值
    vector<pair<int, int>>bucketArr(buckets, {-1,-1}); // min, max

    for(auto&num: nums){
        int id = (num-minn)/d;
        if(bucketArr[id].first==-1){
            bucketArr[id].first = bucketArr[id].second = num;
        }else{
            bucketArr[id].first = min(bucketArr[id].first, num);
            bucketArr[id].second = max(bucketArr[id].second, num);
        }
    }
    int pre = -1;
    int maxdist = 0;
    // 元素之间的最大间距一定不会出现在某个桶的内部，而一定会出现在不同桶当中。
    for(int i=0; i<buckets; i++){
        if(bucketArr[i].first==-1) continue;
        if(pre!=-1){
            maxdist = max(maxdist, bucketArr[i].first-bucketArr[pre].second);
        }
        pre = i;
    }
    return maxdist;
}


int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return 0;
    }
    int exp = 1;
    vector<int> buf(n);
    int maxVal = *max_element(nums.begin(), nums.end());

    while (maxVal >= exp) {
        // cnt 数组清零
        vector<int> cnt(10);
        // 依次获取 个位、十位、百位。。。
        for (int i = 0; i < n; i++) {
            int digit = (nums[i] / exp) % 10;
            cnt[digit]++;
        }
        // 计算累加频数，用户计数排序
        for (int i = 1; i < 10; i++) {
            cnt[i] += cnt[i - 1];
        }
        //使用倒数第 i+1 位数对 nums 进行排序
        for (int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            buf[cnt[digit] - 1] = nums[i];
            cnt[digit]--;
        }
        // 将按第 i 为数排序后的结果保存回数组 nums 中
        copy(buf.begin(), buf.end(), nums.begin());
        exp *= 10;
    }

    int ret = 0;
    for (int i = 1; i < n; i++) {
        ret = max(ret, nums[i] - nums[i - 1]);
    }
    return ret;
}
