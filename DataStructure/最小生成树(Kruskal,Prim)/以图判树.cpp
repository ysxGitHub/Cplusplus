/*
给定编号从 0 到 n - 1 的 n 个结点。给定一个整数 n 和一个 edges 列表，
    其中 edges[i] = [ai, bi] 表示图中节点 ai 和 bi 之间存在一条无向边。

如果这些边能够形成一个合法有效的树结构，则返回 true ，否则返回 false 。

注意 ai != bi， 不存在自循环或重复的边
*/

#include<vector>
#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

class UnionFind{
public:

    // // 这里的ans相当于根节点的个数
    // int ans;

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

        // // 合并成功根节点减少
        // ans--;
    }
private:
    vector<int>parent;
    vector<int>rank;
};

bool validTree(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);

    // uf.ans = n;

    // 生成树的边个数
    int remaining = n-1;  
    for(auto&e : edges){
        if(uf.isConnect(e[0], e[1])){
            return false;
        }
        uf.unionVer(e[0], e[1]);
        if(!--remaining){
            break;
        }
    }
    if(remaining){
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    vector<vector<int>>edges={{0, 1}, {1, 2}, {3, 4}};
    cout<<validTree(n, edges);
    return 0;
}
