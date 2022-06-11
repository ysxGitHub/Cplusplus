/*
给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

你可以假设所有输入数组都可以得到满足题目要求的结果。
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// 75 颜色分类 + 215 数组中的第K个最大元素
void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    std::nth_element(nums.begin(), nums.begin() + n/2, nums.end());
    int mid = nums[n/2];

    // 3-way-partion
    int i = 0, j = 0, k = n - 1;

    // 映射
    #define a(i) nums[(2*(i)+1)%(n|1)]

    while (j <= k) {
        if (a(j) > mid) {
            swap(a(i), a(j));
            ++i, ++j;
        } else if (a(j) < mid) {
            swap(a(j), a(k));
            --k;
        } else {
            ++j;
        }
    }
}

int main(int argc, char const *argv[])
{
    cout<<(8|1)<<endl;
    return 0;
}
