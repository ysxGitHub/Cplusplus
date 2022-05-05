/*
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，
    找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
*/
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;


void DFS(vector<vector<char>>& board, int x, int y){
    if(x<0||y<0||x>=board.size()||y>=board[0].size()){
        return;
    }
    if(board[x][y]=='X'||board[x][y]=='P'){
        return;
    }

    board[x][y]='P';

    DFS(board, x+1, y);
    DFS(board, x-1, y);
    DFS(board, x, y+1);
    DFS(board, x, y-1);
}


void solve1(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
 
    for(int i=0; i<m; i++){
        DFS(board, i, 0);
        DFS(board, i, n-1);
    }
    for(int j=0; j<n; j++){
        DFS(board, 0, j);
        DFS(board, m-1, j);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]=='O'){
                board[i][j]='X';
            }
            else if(board[i][j]=='P'){
                board[i][j]='O';
            }
        }
    }

}

class UnionFind{
public:
    UnionFind(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int findRoot(int x){
        if(parent[x]!=x){
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    bool isConnect(int x, int y){
        int x_root = findRoot(x);
        int y_root = findRoot(y); 
        if(x_root==y_root){
            return true;
        } 
        return false;
    }

    void unionVer(int x, int y){
        int x_root = findRoot(x);
        int y_root = findRoot(y); 

        if(rank[x_root]>rank[y_root]){
            parent[y_root] = x_root;
        }
        else if(rank[x_root]<rank[y_root]){
            parent[x_root] = y_root; 
        }
        else{
            parent[y_root] = x_root;
            rank[x_root]++;       
        }
    }
private:
    vector<int>parent;
    vector<int>rank;
};

void solve2(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    // 边界的‘O’的公共父节点demmy
    int demmy = m*n;
    UnionFind uf(demmy+1);
    for(int i=0; i<m; i++){
        if(board[i][0]=='O'){
            uf.unionVer(i*n, demmy);
        }
        if(board[i][n-1]=='O'){
            uf.unionVer(i*n+n-1, demmy);
        }
    }
    for(int j=0; j<n; j++){
        if(board[0][j]=='O'){
            uf.unionVer(j, demmy);
        }
        if(board[m-1][j]=='O'){
            uf.unionVer((m-1)*n+j, demmy);
        }
    }
    vector<vector<int>> sf = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for(int i=1; i<m-1; i++){
        for(int j=1; j<n-1; j++){
            // 将该‘O’与周围的’O‘相连
            if(board[i][j] == 'O'){
                for(int k=0; k<4; k++){
                    int x = i+sf[k][0];
                    int y = j+sf[k][1];
                    if (board[x][y] == 'O'){
                        uf.unionVer(i*n+j, x*n+y);
                    }
                }
            }
        }
    }
    for(int i=1; i<m-1; i++){
        for(int j=1; j<n-1; j++){
            if(board[i][j]=='O'&&!uf.isConnect(i*n+j, demmy)){
                board[i][j]='X';
            }
        }
    }   
}


void solve(vector<vector<char>>& board) {
    queue<pair<int, int>>que;
    int m = board.size();
    int n = board[0].size();
    // 将边界的’O‘全换成’A‘
    for(int i=0; i<m; i++){
        if(board[i][0]=='O'){
            que.push(make_pair(i, 0));
            board[i][0]='A';
        }
        if(board[i][n-1]=='O'){
            que.push(make_pair(i, n-1));
            board[i][n-1]='A';
        }
    }
    for(int j=0; j<n; j++){
        if(board[0][j]=='O'){
            que.push(make_pair(0, j));
            board[0][j]='A';
        }
        if(board[m-1][j]=='O'){
            que.push(make_pair(m-1, j));
            board[m-1][j]='A';
        }
    }
    vector<vector<int>> sf = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
 
    while(!que.empty()){
        int i = que.front().first;
        int j = que.front().second;
        que.pop();
        for(int k=0; k<4; k++){
            int x = i+sf[k][0];
            int y = j+sf[k][1];
            if(x<1||y<1||x>=m-1||y>=n-1){
                continue;
            }
            if(board[x][y]=='O'){
                // 将与边界O相连的O放入queue，并且将其替换为A
                que.push(make_pair(x, y));
                board[x][y]='A';
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]=='A'){
                board[i][j]='O';
            }
            else if(board[i][j]=='O'){
                board[i][j]='X';
            }
        }
    }    

}


int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'X','O'},{'O','O'}};
    solve(board);

    for(auto &m : board){
        for(auto &n : m){
            cout<<n<<"  ";
        } 
        cout<<endl;
    }

    return 0;
}
