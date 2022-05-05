/*
给定一个长度为 n 的整数数组 nums 。

假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
返回 F(0), F(1), ..., F(n-1)中的最大值 。

生成的测试用例让答案符合 32 位 整数。
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;


/**
 * SUM(data) = 15
 * 把数组逆转跟把乘数逆转是一样的，可以看出有如下规律
 *   4     3     2     6
 *
 *  0*4   1*3   2*2   3*6   F(0) = 25
 *
 *  3*4   0*3   1*2   2*6   F(1) = F(0) - SUM(data) + N * data[0] = 25 - 15 + 4 * 4 = 26;
 *
 *  2*4   3*3   0*2   1*6   F(2) = F(1) - SUM(data) + N * data[1] = 26 - 15 + 4 * 3 = 23;
 *
 *  1*4   2*3   3*2   0*6   F(3) = F(2) - SUM(data) + N * data[2] = 23 - 15 + 4 * 2 = 16;
 *
 */
int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return 0;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int curf = 0, prevf = 0;

    for(int i=0; i<n; i++){
        curf += nums[i]*i;
    }

    int ans = curf;

    for(int i=1; i<n; i++){
        prevf = curf;
        curf = prevf - sum + n * nums[i-1];
        ans = max(ans, curf);
    }
    return ans;
}