/*
在一个 8x8 的棋盘上，放置着若干「黑皇后」和一个「白国王」。

给定一个由整数坐标组成的数组 queens ，表示黑皇后的位置；以及一对坐标 king ，表示白国王的位置，返回所有可以攻击国王的皇后的坐标(任意顺序)。
*/
#include <vector>
using namespace std;

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<vector<int>>ans;
    vector<pair<int, int>> offset={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1},{-1,1},{1,-1},{-1,-1}};
    vector<vector<bool>>board(8, vector<bool>(8,0));
    for(auto&que: queens){
        board[que[0]][que[1]] = 1;
    }
    for(auto& off: offset){
        int x = king[0] + off.first, y = king[1] + off.second;
        while(x>=0&&x<8&&y>=0&&y<8){
            if(board[x][y]) {
                ans.push_back({x,y});
                break;
            }
            x += off.first, y += off.second;
        }
    }
    return ans;
}