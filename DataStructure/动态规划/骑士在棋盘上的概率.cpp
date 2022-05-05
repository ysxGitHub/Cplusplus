/*
在一个 n x n 的国际象棋棋盘上，一个骑士从单元格 (row, column) 开始，并尝试进行 k 次移动。
    行和列是 从 0 开始 的，所以左上单元格是 (0,0) ，右下单元格是 (n - 1, n - 1) 。

象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。

每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。

骑士继续移动，直到它走了 k 步或离开了棋盘。

返回 骑士在棋盘停止移动后仍留在棋盘上的概率 。

*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

unordered_map<int,unordered_map<int, double>> ans;
vector<vector<int>> offset = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
double knightProbability1(int n, int k, int row, int column) {
    // 终点返回1
    if(k==0){return 1.0;}
    // 查询是否访问过
    if(ans[row*n+column].find(k)!=ans[row*n+column].end()){
        return ans[row*n+column][k];
    }
    double pro=0.0;
    for(int a=0; a<8; a++){
        int x = row+offset[a][0];
        int y = column+offset[a][1];
        if(x<0||x>=n||y<0||y>=n){
            continue;
        }
        pro += knightProbability1(n, k-1, x, y)/8.0;
    }
    // 保存本次的概率
    ans[row*n+column][k] = pro;
    return pro;
}

double knightProbability(int n, int k, int row, int column) {
    vector<vector<vector<double>>>dp(k+1, vector<vector<double>>(n, vector<double>(n, 0)));
    for (int step=0; step<=k; step++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(step==0){
                    dp[step][i][j]=1;
                }else{
                    for(auto&o: offset){
                        int x = i + o[0];
                        int y = j + o[1];
                        if(x>=0&&x<n&&y>=0&&y<n){
                            dp[step][x][y] += dp[step-1][i][j]/8.0;
                        }
                    }
                }
            }
        }
    }
    return dp[k][row][column];
}



int main(int argc, char const *argv[])
{
    cout<<knightProbability1(8,30,0,0);
    return 0;
}
