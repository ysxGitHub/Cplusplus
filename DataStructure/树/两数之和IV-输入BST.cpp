/*
给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 
    中存在两个元素且它们的和等于给定的目标结果，则返回 true。
*/

#include<iostream>
#include<unordered_set>
using  namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



unordered_set<int>cnt;

bool findTarget(TreeNode* root, int k) {
    if(root==nullptr) return false;
    if(cnt.count(root->val)) return true;
    cnt.insert(k - root->val);
    return findTarget(root->left, k)|findTarget(root->right, k);
}