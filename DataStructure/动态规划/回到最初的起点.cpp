/*
圆环上有10个点，编号为0~9。从0点出发，每次可以逆时针和顺时针走一步，问走n步回到0点共有多少种走法。
points: 点的个数
*/

#include <vector>
#include <iostream>
using namespace std;

//思路：走 n 步到 0 的方案数 = 走 n-1 步到 1 的方案数 + 走 n-1 步到 9 的方案数。
int backToOrigin(int n, int points){
    // dp[i][j]表示从0出发，走i步到j的方案数
    vector<vector<int>>dp(n+1, vector<int>(points));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<points; j++){
            dp[i][j] = dp[i-1][(j-1+points)%points] + dp[i-1][(j+1)%points];
        }
    }
    return dp[n][0];
}

int main(int argc, char const *argv[])
{
    cout<<backToOrigin(4,10);
    return 0;
}

