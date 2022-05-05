/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check(TreeNode* left, TreeNode* right){
    if(left==nullptr||right==nullptr) return left==right;

    if(left->val!=right->val) return 0;

    return check(left->left, right->right)&&check(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if(root==nullptr) return 1;

    return check(root->left, root->right);
}