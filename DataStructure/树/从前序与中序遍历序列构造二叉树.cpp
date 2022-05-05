/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， 
    inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrder(TreeNode* root){
    if(root==nullptr){return;}
    cout<<root->val<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder, 
                int pre_lo, int pre_hi,
                int in_lo, int in_hi) {
    if(pre_lo>pre_hi||in_lo>in_hi){
        return nullptr;
    }

    int pre_root = preorder[pre_lo];
    int in_mid = in_lo;
    for(; in_mid<=in_hi; in_mid++){
        if(inorder[in_mid] == pre_root){
            break;
        }
    }
    // 注意：in_mid的起始位置是in_lo，计算左子树的宽度时要用in_mid - in_lo
    int left_length = in_mid - in_lo;
    // cout<<in_mid <<"-"<<in_lo<<endl;
    TreeNode* root = new TreeNode(pre_root);
    root->left = build(preorder, inorder, pre_lo+1, pre_lo+left_length, in_lo, in_mid-1);
    root->right = build(preorder, inorder, pre_lo+left_length+1, pre_hi, in_mid+1, in_hi);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}


int main(int argc, char const *argv[])
{
    
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    preOrder(root);
    return 0;
}

