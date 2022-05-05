/*
给定一棵二叉树的根节点 root，返回给定节点 p 和 q 的最近公共祖先（LCA）节点。
    如果 p 或 q 之一 不存在 于该二叉树中，返回 null。树中的每个节点值都是互不相同的。
*/
#include<iostream>
// #include<unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 用于记录 p 和 q 是否存在于二叉树中
bool foundP = false, foundQ = false;

// 在二叉树中寻找 val1 和 val2 的最近公共祖先节点
TreeNode* find(TreeNode* root, int val1, int val2) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* left = find(root->left, val1, val2);
    TreeNode* right = find(root->right, val1, val2);

    // 后序位置，判断当前节点是不是 LCA 节点
    if (left != NULL && right != NULL) {
        return root;
    }

    // 后序位置，判断当前节点是不是目标值
    if (root->val == val1 || root->val == val2) {
        // 找到了，记录一下
        if (root->val == val1) foundP = true;
        if (root->val == val2) foundQ = true;
        return root;
    }

    return left != NULL ? left : right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* res = find(root, p->val, q->val);
    if (!foundP || !foundQ) {
        return NULL;
    }
    // p 和 q 都存在二叉树中，才有公共祖先
    return res;    
}