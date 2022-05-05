/*
给定一棵二叉树的根节点 root 和 TreeNode 类对象的数组（列表） nodes，
    返回 nodes 中所有节点的最近公共祖先（LCA）。数组（列表）中所有节点都存在于该二叉树中，
    且二叉树中所有节点的值都是互不相同的。

*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 在二叉树中寻找 values 的最近公共祖先节点
TreeNode* find(TreeNode* root, unordered_set<int>& values) {
    if (root == NULL) {
        return NULL;
    }
    // 前序位置
    if (values.count(root->val)){
        return root;
    }

    TreeNode* left = find(root->left, values);
    TreeNode* right = find(root->right, values);
    // 后序位置，已经知道左右子树是否存在目标值
    if (left != NULL && right != NULL) {
        // 当前节点是 LCA 节点
        return root;
    }

    return left != NULL ? left : right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    // 将列表转化成哈希集合，便于判断元素是否存在
    unordered_set<int> values;
    for (auto node : nodes) {
        values.insert(node->val);
    }

    return find(root, values);    
}