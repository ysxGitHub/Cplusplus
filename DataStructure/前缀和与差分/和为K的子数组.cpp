/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数.

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> sumArr;


/*
直接记录下有几个 preSum[left] 和 preSum[right] - k 相等，直接更新结果，就避免了内层的 for 循环。
*/
int subarraySum(vector<int> &nums, int k)
{
    int sum = 0, ans = 0;
    unordered_map<int, int> sumCnt;
    // base case 前缀和为 0 的子数组有 1 个
    // 例如 nums = [1, 2, 3, 6]，k = 6
    sumCnt[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(sumCnt.count(sum - k)){
            ans += sumCnt[sum - k];
        }
        sumCnt[sum] += 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, -1, 0};
    cout << subarraySum(nums, 0);
    return 0;
}
