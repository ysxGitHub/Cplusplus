/*
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，
    然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 超时
int ans=0;
vector<int>path;
void backtrack(vector<int>& nums, int target, int front){
    if(target==0&&path.size()==nums.size()){
        ans++;
        return ;
    }
    for(int i=front; i<nums.size(); i++){
        path.emplace_back(nums[i]);
        backtrack(nums, target-nums[i], i+1);
        backtrack(nums, target+nums[i], i+1);
        path.pop_back();
    }
}
int findTargetSumWays1(vector<int>& nums, int target) {
    backtrack(nums, target, 0);
    return ans;
}

// 改进一下，还是超时
unordered_map<string, int>memo;
int dp(vector<int>& nums, int target, int level){
    if(level==nums.size()){
        if(target==0){return 1;}
        return 0;
    }
    string key;
    key = to_string(level)+","+to_string(target);
    int res = dp(nums, target-nums[level], level+1)+dp(nums, target+nums[level], level+1);
    memo[key] = res;
    return res;
}
int findTargetSumWays2(vector<int>& nums, int target) {
    return dp(nums, target, 0);
}


/*
继续改进dp
  ... -5 -4 -3 -2 -1  0  1  2  3  4  5 ... sum
1 ... 0  0  0   0  1  0  1  0  0  0  0 ...
1 ... 0  0  0   1  0  2  0  1  0  0  0 ...
1 ... 0  0  1   0  3  0  3  0  1  0  0 ...
2 ... 1  0  3   0  4  0  4  0  3  0  0 ...
3 ... 0  4  0   5  0  6  0  4  0  0  3 ...
num

*/
int findTargetSumWays3(vector<int>& nums, int target) {
    int len = nums.size();
    int sum1 = 0;
    for(auto&n: nums){
        sum1+=n;
    }
    if(sum1<abs(target)){
        return 0;
    }
    vector<vector<int>>dp(len, vector<int>(sum1*2+1));

    dp[0][sum1-nums[0]] += 1;
    dp[0][sum1+nums[0]] += 1;

    for(int i=1; i<len; i++){
        for(int j=-sum1; j<=sum1; j++){
            if(j + nums[i] > sum1){
                dp[i][j + sum1] = 0 + dp[i-1][j + sum1 - nums[i]];
            }
            else if(j - nums[i] < -sum1){
                dp[i][j + sum1] = dp[i-1][j + sum1 + nums[i]] + 0;
            }
            else{
                dp[i][j + sum1] = dp[i - 1][j + sum1 + nums[i]] + dp[i - 1][j + sum1 - nums[i]];
            }
        }
    }
    return dp[len-1][sum1+target];
}


// 继续改进dp
/*
原问题等同于： 找到nums一个正子集P和一个负子集N，使得总和等于target。
    即sum(P) - sum(N) == target，
    即sum(P) - sum(N) - sum(P) - sum(N) == target - sum(P) - sum(N)
    即2 * sum(N) == sum(nums) - target ， 其中sum(nums) - target必须>=0且为偶数，
        否则等式不可能成立。
则问题转换为：存在多少个子集N，使sum(N) == (sum(nums) - target)/2。
*/

// 0-1背包问题+组合
int findTargetSumWays(vector<int>& nums, int target) {
    int len = nums.size();
    int sum1 = 0;
    for(auto&n: nums){
        sum1+=n;
    }
    int diff = sum1-target;
    if(diff<0||diff%2==1){
        return 0;
    }
    int neg = diff/2;

    /*
    dp[i][j]表示前i个元素有多少个目标和为j的子集。dp[0][0] = 1
        1. dp[i][j] = dp[i-1][j]
        2. 如果nums[0...i-2]存在目标和为j-nums[i-1]的子集，则dp[i][j] += dp[i-1][j-nums[i-1]]
    */
    vector<vector<int>>dp(len+1, vector<int>(neg+1));
    /*
    当没有任何元素可以选取时，元素和只能是 0，对应的方案数是 1，因此动态规划的边界条件是：
    dp[0][j] = 1; j=0;
    dp[0][j] = 0; j>0;
    */
    dp[0][0] = 1;
    for (int i = 1; i <= len; i++) {
        int num = nums[i - 1];
        for (int j = 0; j <= neg; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= num) {
                dp[i][j] += dp[i - 1][j - num];
            }
        }
    }
    return dp[len][neg];

    /*
    空间改进
    vector<int> dp(neg+1, 0);
    dp[0]=1;
    // 变成0-1背包问题
    for(auto&n: nums){
        for(int j=neg; j>=n; j--){
            dp[j] += dp[j-n];
        }
    }
    return dp[neg];
    */
}