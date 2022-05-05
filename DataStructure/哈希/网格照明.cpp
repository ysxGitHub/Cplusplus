/*
在大小为 n x n 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。

给你一个由灯的位置组成的二维数组 lamps ，其中 lamps[i] = [rowi, coli] 表示 
    打开 位于 grid[rowi][coli] 的灯。即便同一盏灯可能在 lamps 中多次列出，
    不会影响这盏灯处于 打开 状态。

当一盏灯处于打开状态，它将会照亮 自身所在单元格 以及同一 行 、同一 列 和两条 对角线 上的 
    所有其他单元格 。

另给你一个二维数组 queries ，其中 queries[j] = [rowj, colj] 。对于第 j 个查询，
    如果单元格 [rowj, colj] 是被照亮的，则查询结果为 1 ，否则为 0 。
    在第 j 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowj][colj] 上及相邻 8 个方向上
    （与单元格 grid[rowi][coli] 共享角或边）的任何灯。

返回一个整数数组 ans 作为答案， ans[j] 应等于第 j 次查询 queries[j] 的结果，
    1 表示照亮，0 表示未照亮。

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;


vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    vector<int>ans;
    vector<vector<int>> obs= {{0,0},{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
    unordered_map<int, int> row; //记录被照亮的行
    unordered_map<int, int> col; //记录被照亮的列
    unordered_map<int, int> sdiag; //记录被照亮的主对角线 (x1-y1==x2-y2)
    unordered_map<int, int> udiag; //记录被照亮的副对角线 (x1+y1==x2+y2)
    set<pair<int, int>>lampslight; //记录被点亮的灯，防止重复点亮；

    for(auto&ls : lamps){
        auto p = make_pair(ls[0], ls[1]);
        if(lampslight.count(p)==0){
            lampslight.insert(p);
            row[ls[0]]+=1;
            col[ls[1]]+=1;
            sdiag[ls[0]-ls[1]]+=1;
            udiag[ls[0]+ls[1]]+=1;
        }
    }
    for(auto&qs : queries){
        int nx = qs[0];
        int ny = qs[1];
        ans.push_back(row[nx]||col[ny]||sdiag[nx-ny]||udiag[nx+ny]);        
        for(auto&os : obs){
            auto q = make_pair(nx+os[0], ny+os[1]);
            if(lampslight.count(q)>0){
                lampslight.erase(q);
                row[nx+os[0]]-=1;
                col[ny+os[1]]-=1;
                sdiag[nx+os[0]-ny-os[1]]-=1;
                udiag[nx+os[0]+ny+os[1]]-=1; 
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> lamps = {{0,0},{0,1},{0,4}};
    vector<vector<int>> queries = {{0,0},{0,1},{0,2}};
    vector<int> ans = gridIllumination(5, lamps, queries);
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }

    return 0;
}

