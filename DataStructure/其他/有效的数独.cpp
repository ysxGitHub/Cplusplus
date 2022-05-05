/*
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
*/


#include<vector>
using namespace std;


bool check(vector<vector<char>>& board, int x, int y){
    char num = board[x][y];
    for(int i=0; i<9; i++){
        if(board[x][i]==num&&i!=y) return false;
        if(board[i][y]==num&&i!=x) return false;
        int tx = (x/3)*3+i/3 , ty = (y/3)*3+i%3;
        if(board[tx][ty]==num&&(tx!=x&&ty!=y)) return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]!='.'){
                if(!check(board, i, j)) return false;
            }
        }
    }
    return true;
}