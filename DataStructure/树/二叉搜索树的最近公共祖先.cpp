/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
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


// 在 BST 中寻找 val1 和 val2 的最近公共祖先节点
TreeNode* find(TreeNode* root, int val1, int val2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val > val2) {
        // 当前节点太大，去左子树找
        return find(root.left, val1, val2);
    }
    if (root->val < val1) {
        // 当前节点太小，去右子树找
        return find(root.right, val1, val2);
    }
    // val1 <= root.val <= val2
    // 则当前节点就是最近公共祖先
    return root;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 保证 val1 较小，val2 较大
    int val1 = min(p->val, q->val);
    int val2 = max(p->val, q->val);
    return find(root, val1, val2);    
}