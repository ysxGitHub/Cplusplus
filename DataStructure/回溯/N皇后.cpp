/*

*/

#include<iostream>
#include<vector>
using namespace std;


// n = 9 超时
// 把 void 换成 bool ，最后函数找到一个答案后就返回 true
void backtrack1(int fisrt, int n, vector<string>& path, vector<vector<string>>& ans, vector<bool>& row,vector<bool>& col, vector<bool>& sdiag, vector<bool>& udiag){
    if(fisrt==n){
        ans.emplace_back(path);
        return ;
    }
    for(int i=fisrt; i<n; i++){
        for(int j=0; j<n; j++){
            if(row[i]==1||col[j]==1||sdiag[i-j+n]==1||udiag[i+j]==1){
                continue;
            }
            path[i][j] = 'Q';
            row[i]=1, col[j]=1, sdiag[i-j+n]=1, udiag[i+j]=1;
            backtrack1(fisrt+1, n, path, ans, row, col, sdiag, udiag);
            row[i]=0, col[j]=0, sdiag[i-j+n]=0, udiag[i+j]=0;
            path[i][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens1(int n) {
    vector<vector<string>>ans;
    vector<string>path(n, string(n, '.'));
    vector<bool>row(n, 0);
    vector<bool>col(n, 0);
    vector<bool>sdiag(2*n, 0);
    vector<bool>udiag(2*n, 0);
    backtrack1(0, n, path, ans, row, col, sdiag, udiag);
    return ans;
}


void backtrack(int i, int n, vector<string>& path, vector<vector<string>>& ans, vector<bool>& col, vector<bool>& sdiag, vector<bool>& udiag){
    if(i==n){
        ans.emplace_back(path);
        return ;
    }
    for(int j=0; j<n; j++){
        if(col[j]==1||sdiag[i-j+n]==1||udiag[i+j]==1){
            continue;
        }
        path[i][j] = 'Q';
        col[j]=1, sdiag[i-j+n]=1, udiag[i+j]=1;
        backtrack(i+1, n, path, ans, col, sdiag, udiag);
        col[j]=0, sdiag[i-j+n]=0, udiag[i+j]=0;
        path[i][j] = '.';
    }

}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>path(n, string(n, '.'));
    vector<bool>col(n, 0);
    vector<bool>sdiag(2*n, 0);
    vector<bool>udiag(2*n, 0);
    backtrack(0, n, path, ans, col, sdiag, udiag);
    return ans;
}


int main(int argc, char const *argv[])
{
    solveNQueens(9);
    return 0;
}
