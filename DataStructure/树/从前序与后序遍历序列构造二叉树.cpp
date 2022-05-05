/*
给定两个整数数组 preorder 和 postorder ，其中 preorder 是二叉树的前序遍历， 
    postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

*/

#include<iostream>
#include<vector>

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

TreeNode* build(vector<int>& preorder, vector<int>& postorder, 
                int pre_lo, int pre_hi,
                int post_lo, int post_hi) {

    if(pre_lo>pre_hi||post_lo>post_hi){
        return nullptr;
    }
    if(pre_lo==pre_hi){
        return new TreeNode(preorder[pre_lo]);
    }
    TreeNode* root = new TreeNode(preorder[pre_lo]);
    int left_root = preorder[pre_lo+1];
    int post_mid  = post_lo;
    for(; post_mid<=post_hi; post_mid++){
        if(postorder[post_mid]==left_root){
            break;
        }
    }
    int left_length = post_mid - post_lo + 1;
    root->left = build(preorder, postorder, pre_lo+1, pre_lo+left_length, post_lo, post_mid);
    root->right = build(preorder, postorder, pre_lo+left_length+1, pre_hi, post_mid+1, post_hi-1);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder) {

    return build(preorder, postorder, 0, preorder.size()-1, 0, postorder.size()-1);
}


int main(int argc, char const *argv[])
{
    
    vector<int> preorder = {1, 2, 4,5, 3,6,7};
    vector<int> postorder = {4,5, 2, 6,7,3, 1};

    TreeNode* root = buildTree(preorder, postorder);
    preOrder(root);

    return 0;
}
