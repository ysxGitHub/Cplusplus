/*
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
*/

#include<vector>
#include<iostream>

using namespace std;

bool isValid(vector<vector<char>>& board, char num, int row, int col){
    for(int i=0; i<9; i++){
        if(board[row][i]==num) return false;
        if(board[i][col]==num) return false;
        if(board[(row/3)*3 + i/3][(col/3)*3 + i%3]==num) return false;
    }
    return true;
}

bool backtrack(vector<vector<char>>& board, int i, int j){

    // 如果当前行遍历完成 则返回到下一行，从头开始
    if(j==9) return backtrack(board, i+1, 0);
    // 遍历全部完成
    if(i==9) return true;
    // 不需要遍历，返回到下一个列继续
    if(board[i][j]!='.') return backtrack(board, i, j+1);

    for(char num='1'; num<='9'; num++){
        // 如果 num 存在 则尝试下一个 num
        if(!isValid(board, num, i, j)) continue;
        board[i][j] = num;
        // 下一列成立直接返回
        if(backtrack(board, i, j+1)) return true;
        board[i][j] = '.';
    }
    return false;
}


void solveSudoku(vector<vector<char>>& board) {
    backtrack(board, 0, 0);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
