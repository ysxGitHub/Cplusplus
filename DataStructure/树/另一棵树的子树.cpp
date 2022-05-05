/*
给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
    如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。
    tree 也可以看做它自身的一棵子树
*/

/*
  1       1
1  1       1
  1 1
所以 root 每走一步都要判断 subroot
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

bool isIdentical(TreeNode* root, TreeNode* subRoot){
    if((root&&!subRoot)||(!root&&subRoot)) return false;
    if(!root&&!subRoot) return true;
    if(root->val!=subRoot->val) return false;
    return isIdentical(root->left, subRoot->left)&isIdentical(root->right, subRoot->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root) return !subRoot;
    if(isIdentical(root, subRoot)) return true;
    return isSubtree(root->left, subRoot)|isSubtree(root->right, subRoot);
}