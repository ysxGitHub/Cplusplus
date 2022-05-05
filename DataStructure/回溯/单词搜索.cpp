/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>offset={{0,1},{1,0},{0,-1},{-1,0}};
bool backtrace(vector<vector<char>>& board, string& word, int i, int j, string& path, int k){
    if(board[i][j]!=word[k]||path.size()>=word.size()) return 0;
    int m = board.size(), n = board[0].size();
    path+=board[i][j];
    board[i][j] = '0';
    if(path==word) return 1;
    for(auto&off: offset){
        int x = i+off[0], y = j+off[1];
        if(x<0||x>=m||y<0||y>=n||board[x][y]=='0') continue;
        if(backtrace(board, word, x, y, path, k+1)) return 1;
    }
    board[i][j] = path.back();
    path.pop_back();
    return 0;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            string path;
            // if(word[0]!=board[i][j]) continue;
            if(backtrace(board, word, i, j, path, 0)) return 1;
        }
    }
    return 0;
}