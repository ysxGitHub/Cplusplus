/*
给你一棵根节点为 0 的 二叉树 ，它总共有 n 个节点，节点编号为 0 到 n - 1 。
    同时给你一个下标从 0 开始的整数数组 parents 表示这棵树，其中 parents[i] 是节点 i 的父节点。
    由于节点 0 是根，所以 parents[0] == -1 。

一个子树的 大小 为这个子树内节点的数目。每个节点都有一个与之关联的 分数 。
    求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除 ，剩余部分是若干个 非空 子树，
    这个节点的 分数 为所有这些子树 大小的乘积 。

请你返回有 最高得分 节点的 数目 。
*/

#include<vector>
#include<iostream>
using namespace std;

int ans=0;
long long maxCnt = 0;

int cntNode(vector<vector<int>>& tree, int p, int n){
    int size = tree[p].size();
    
    if(size == 0){
        int tcnt = n - 1;
        if(tcnt > maxCnt){
            maxCnt = tcnt;
            ans = 1;
        }else if(tcnt == maxCnt){
            ans++;
        }
        return 1;
    }
    int l=0, r=0;
    if(size == 1){
        l = cntNode(tree, tree[p][0], n);
    }else{
        l = cntNode(tree, tree[p][0], n);
        r = cntNode(tree, tree[p][1], n);
    }
    int otherCnt = n - l - r - 1;
    int cnt = 1;
    if(otherCnt){
        cnt *= otherCnt;
    }
    if(l){
        cnt *= l;
    }
    if(r){
        cnt *= r;
    }

    return r+l+1;
}


int countHighestScoreNodes(vector<int>& parents){
    int n = parents.size();
    vector<vector<int>> tree(n);

    for(int i=1; i<n; i++){
        tree[parents[i]].emplace_back(i);
    }
    cntNode(tree, 0, n);

    return ans;

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
