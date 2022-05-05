/*
给你一个大小为 m x n 的矩阵 board 表示甲板，其中，每个单元格可以是一艘战舰 'X' 
    或者是一个空位 '.' ，返回在甲板 board 上放置的 战舰群 的数量。

战舰群 只能水平或者垂直放置在 board 上。换句话说，战舰群只能按 1 x k（1 行，k 列）或 
    k x 1（k 行，1 列）的形状建造，其中 k 可以是任意大小。
    两艘战舰群之间至少有一个水平或垂直的空位分隔 （即没有相邻的战舰）。
*/

#include<iostream>
#include<vector>

using namespace std;

/*
遍历整个board， 遇到board[i][j]=='X' 那么 res + 1
如果它是竖着的一部分，我们直接看(i-1,j)这个坐标，如果也是'X', 那么 res - 1
如果它是横着的一部分，我们看(i,j-1)这个坐标，如果也是'X', 那么 res - 1
本题本质上就是求解：只有当这个点是一个战舰的头部的时候，那么 res + 1
*/

int countBattleships(vector<vector<char>>& board) {
    int res=0;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j]=='X') {
                res++;
                if(i>0&&board[i-1][j]=='X') res--;
                if(j>0&&board[i][j-1]=='X') res--;
            }
        }
    }
    return res;
}

int countBattleships1(vector<vector<char>>& board) {
    int res=0;
    int n = board.size(), m = board.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='X') {
                res++;
                board[i][j] = '.';
                for(int k=i+1; k<n&&board[k][j]=='X'; k++) board[k][j]='.';
                for(int k=j+1; k<m&&board[i][k]=='X'; k++) board[i][k]='.';
            }
        }
    }
    return res;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
