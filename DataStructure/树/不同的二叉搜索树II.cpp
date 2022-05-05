/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。
    可以按 任意顺序 返回答案。
*/
#include<iostream>
#include<vector>
#include<queue>
using  namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
分而治之的思想

1、穷举root节点的所有可能。

2、递归构造出左右子树的所有合法 BST。

3、给root节点穷举所有左右子树的组合。
*/
vector<TreeNode*> builtTree(int begin, int end){
    if(begin>end){
        return {nullptr};
    }
    vector<TreeNode*> allTree;
    for(int i=begin; i<=end; i++){
        vector<TreeNode*> allLeft = builtTree(begin, i-1);
        vector<TreeNode*> allRight = builtTree(i+1, end);
        for(auto&l : allLeft){
            for(auto&r: allRight){
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                allTree.emplace_back(root);
            }
        }
    }
    return allTree;
}
vector<TreeNode*> generateTrees(int n) {
    return builtTree(1, n);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
