/*
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。

现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：

 nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数。
*/

// 思路：直线不能相交，这就是说明在字符串A中 找到一个与字符串B相同的子序列，且这个子序列不能改变相对顺序
#include<vector>
#include<iostream>

using namespace std;

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    // dp[i,j] 表示 A[:i] 与 B[:j] 不相交的线
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(nums1[i]==nums2[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[m][n];
}