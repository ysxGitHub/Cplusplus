/*
给你一个数组 pairs ，其中 pairs[i] = [xi, yi] ，并且满足：

pairs 中没有重复元素
xi < yi
令 ways 为满足下面条件的有根树的方案数：

树所包含的所有节点值都在 pairs 中。
一个数对 [xi, yi] 出现在 pairs 中 当且仅当 xi 是 yi 的祖先或者 yi 是 xi 的祖先。
注意：构造出来的树不一定是二叉树。
两棵树被视为不同的方案当存在至少一个节点在两棵树中有不同的父节点。

请你返回：

如果 ways == 0 ，返回 0 。
如果 ways == 1 ，返回 1 。
如果 ways > 1 ，返回 2 。
一棵 有根树 指的是只有一个根节点的树，所有边都是从根往外的方向。

我们称从根到一个节点路径上的任意一个节点（除去节点本身）都是该节点的 祖先 。根节点没有祖先。

*/

#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iostream>

using namespace std;

int checkWays(vector<vector<int>>& pairs) {
    unordered_map<int, unordered_set<int>>adj;
    for(auto& p: pairs){
        adj[p[0]].emplace(p[1]);
        adj[p[1]].emplace(p[0]);
    }
    int root = -1;
    for(auto&n: adj){
        if(n.second.size()==adj.size()-1){
            root = n.first;
            break;
        }
    }
    if(root==-1){
        return 0;
    }
    int res=1;
    for(auto&ad: adj){
        if(ad.first==root){
            continue;
        }
        int curDegree = ad.second.size();
        int parent = -1;
        int parentDegree = INT32_MAX;
        // 寻找当前节点的父节点
        for(auto&a: ad.second){
            if(adj[a].size()<parentDegree&&adj[a].size()>=curDegree){
                parentDegree = adj[a].size();
                parent = a;
            }
        }
        if(parent==-1){
            return 0;
        }
        // 判断当前节点的邻接点 是否都是 当前节点的父节点的邻接点
        for(auto&a: ad.second){
            if(a==parent){
                continue;
            }
            if(adj[parent].count(a)==0){
                return 0;
            }
        }
        // 前节点与父节点都有相同的邻接点
        if(parentDegree==curDegree){
            return 2;
        }

    }
    return res;

}

int main(int argc, char const *argv[])
{
    vector<vector<int>> pairs = {{1,2},{2,3},{1,3}};
    cout<<checkWays(pairs)<<endl;
    return 0;
}
