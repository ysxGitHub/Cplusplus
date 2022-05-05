#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void radixSort(vector<int>&nums){
    int n = nums.size();

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

}


int main(int argc, char const *argv[])
{
    vector<int>nums={4,5,1,6,7,8,9,10};
    radixSort(nums);
    for(auto&num: nums){
        cout<<num<<", ";
    }
    return 0;
}