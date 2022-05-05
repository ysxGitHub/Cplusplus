/*
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
*/
#include<vector>
#include<iostream>
using namespace std;


int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    // 不在 [1, n] 的数都变成 n+1
    for (int& num: nums) {
        if (num <= 0) {
            num = n + 1;
        }
    }
    // 现在 nums 中的数值都在 [1, n] 以及 n+1;
    for (int i = 0; i < n; ++i) {
        // 当前id 对应的 num
        int num = abs(nums[i]);
        if (num <= n) {
            // 将该 num 当成 id, 将 nums[num-1]中的数变为 负数
            nums[num - 1] = -abs(nums[num - 1]);
        }
    }
    // 找到第一个大于 0 的 nums[id], id + 1即为缺失的最小的正整数
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    return n + 1;
}

int firstMissingPositive1(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        // 先判断该数是否在 [1, n], 如果 当前 数 -1 当成 id, 对应的 数 不等于 该数, 则交换
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[nums[i] - 1], nums[i]);
        }
    }
    // 扫描 当前 id+1 与 nums[id] 之间的关系
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main(int argc, char const *argv[])
{

    return 0;
}
