/*
给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。

已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，
    从 f 楼层或比它低的楼层落下的鸡蛋都不会破。

每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。
    如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，
    则可以在之后的操作中 重复使用 这枚鸡蛋。

请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？
*/

#include<vector>
#include<iostream>
using namespace std;


/*
这个问题有什么「状态」，有什么「选择」，然后穷举。

「状态」很明显，就是当前拥有的鸡蛋数 K 和需要测试的楼层数 N。
    随着测试的进行，鸡蛋个数可能减少，楼层的搜索范围会减小，这就是状态的变化。

「选择」其实就是去选择哪层楼扔鸡蛋。
    回顾刚才的线性扫描和二分思路，二分查找每次选择到楼层区间的中间去扔鸡蛋，
    而线性扫描选择一层层向上测试。不同的选择会造成状态的转移。


我们选择在第 i 层楼扔了鸡蛋之后，可能出现两种情况：鸡蛋碎了，鸡蛋没碎。注意，这时候状态转移就来了：
    如果鸡蛋碎了，那么鸡蛋的个数 K 应该减一，搜索的楼层区间应该从 [1..N] 变为 [1..i-1] 共 i-1 层楼；
    如果鸡蛋没碎，那么鸡蛋的个数 K 不变，搜索的楼层区间应该从 [1..N] 变为 [i+1..N] 共 N-i 层楼。


*/


// dp 超时
vector<vector<int>>memo;
int dp(int K, int N){
    if(K==1) return N;
    if(N==0) return 0;
    if(memo[K][N]!=-1) return memo[K][N];
    int res = INT32_MAX;
    for(int i=1; i<=N; i++){
        res = min(res, max(dp(K, N-i), dp(K-1, i-1)) + 1);
    }
    memo[K][N] = res;
    return memo[K][N];
}

// 二分dp改进
vector<vector<int>>memo;
int dp2(int K, int N){
    if(K==1) return N;
    if(N==0) return 0;
    if(memo[K][N]!=-1) return memo[K][N];
    int res = INT32_MAX;
    int lo=1, hi=N;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int not_broken = dp(K, N-mid);
        int broken = dp(K-1, mid-1);
        if(broken>not_broken){
            res = min(res, broken+1);
            hi = mid - 1;
        }else{
            res = min(res, not_broken+1);
            lo = mid + 1;           
        }
    }
    memo[K][N] = res;
    return memo[K][N];
}

int superEggDrop1(int k, int n) {
    memo.resize(k+1, vector<int>(n+1, -1));
    return dp2(k, n);
}

/*
# 当前有 k 个鸡蛋，可以尝试扔 m 次鸡蛋
# 这个状态下，最坏情况下最多能确切测试一栋 n 层的楼

# 比如说 dp[1][7] = 7 表示：
# 现在有 1 个鸡蛋，允许你扔 7 次;
# 这个状态下最多给你 7 层楼，
# 使得你可以确定楼层 F 使得鸡蛋恰好摔不碎
# （一层一层线性探查嘛）

我们最终要求的其实是扔鸡蛋次数m，但是这时候m在状态之中而不是dp数组的结果

1、无论你在哪层楼扔鸡蛋，鸡蛋只可能摔碎或者没摔碎，碎了的话就测楼下，没碎的话就测楼上。

2、无论你上楼还是下楼，总的楼层数 = 楼上的楼层数 + 楼下的楼层数 + 1（当前这层楼）

所以递推公式是
    dp[k][m] = dp[k - 1][m - 1] + dp[k][m - 1] + 1

dp[k][m - 1]就是楼上的楼层数，因为鸡蛋个数k不变，也就是鸡蛋没碎，扔鸡蛋次数m减一；

dp[k - 1][m - 1]就是楼下的楼层数，因为鸡蛋个数k减一，也就是鸡蛋碎了，同时扔鸡蛋次数m减一。    
*/
int superEggDrop(int k, int n) {
    vector<vector<int>>dp(k+1, vector<int>(n+1, 0));
    // base case:
    // dp[0][..] = 0
    // dp[..][0] = 0
    int m = 0;
    while (dp[k][m] < n) { 
        m++;
        for (int j = 1; j <= k; j++)
            dp[j][m] = dp[j][m - 1] + dp[j - 1][m - 1] + 1;
    }
    return m;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
