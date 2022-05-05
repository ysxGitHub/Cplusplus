/*
给定一个二叉搜索树的根节点 root ，和一个整数 k ，
    请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

注意：BST的中序遍历为升序
*/

class Solution {
public:
    int ans;
    int rank=0;
    void inOrder(TreeNode* root, int k){
        if(root==nullptr){
            return;
        }
        inOrder(root->left, k);
        rank++;
        if(rank==k){
            ans = root->val;
        }
        inOrder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }
};