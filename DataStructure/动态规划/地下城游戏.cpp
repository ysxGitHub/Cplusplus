/*
一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。
    我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，
    则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），
    要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

为了尽快到达公主，骑士决定每次只向右或向下移动一步。

编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
*/
#include<vector>
#include<iostream>
using namespace std;


// 反向dp
// 从 grid[i][j] 到达终点（右下角）所需的最少生命值是 dp(grid, i, j)。
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>>dp(m, vector<int>(n)); 
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i==m-1&&j==n-1){
                // 终点保证骑士必须有一滴血
                dp[i][j] = max(1, 1-dungeon[i][j]);
            }
            else if(i==m-1){
                dp[i][j] = max(1, dp[i][j+1]-dungeon[i][j]);
            }
            else if(j==n-1){
                dp[i][j] = max(1, dp[i+1][j]-dungeon[i][j]);
            }else{
                dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j]);
            }
        }
    }
    return dp[0][0];
}

// 空间优化版本
int calculateMinimumHP1(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<int>dp(n); //从（i，j）出发，到达终点需要最少的血量
    dp[n-1] = dungeon[m-1][n-1] < 0 ? -dungeon[m-1][n-1]+1 : 1;
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i==m-1&&j==n-1){
                dp[j] = max(1, 1-dungeon[i][j]);
            }
            else if(i==m-1){
                dp[j] = max(1, dp[j+1]-dungeon[i][j]);
            }
            else if(j==n-1){
                dp[j] = max(1, dp[j]-dungeon[i][j]);
            }
            else{
                dp[j] = max(1, min(dp[j+1], dp[j]) - dungeon[i][j]);
            }
        }
    }
    return dp[0];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
