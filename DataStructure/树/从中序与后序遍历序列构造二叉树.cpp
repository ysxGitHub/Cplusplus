/*
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， 
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

TreeNode* build(vector<int>& inorder, vector<int>& postorder, 
                int in_lo, int in_hi,
                int post_lo, int post_hi) {

    if(in_lo>in_hi||post_lo>post_hi){
        return nullptr;
    }

    int post_root = postorder[post_hi];
    int in_mid = in_lo;
    for(; in_mid<=in_hi; in_mid++){
        if(inorder[in_mid] == post_root){
            break;
        }
    }
    // 注意：in_mid的起始位置是in_lo，计算左子树的宽度时要用in_mid - in_lo - 1
    int left_length = in_mid - in_lo;
    // cout<<in_mid <<"-"<<in_lo<<endl;
    TreeNode* root = new TreeNode(post_root);
    root->left = build(inorder, postorder, in_lo, in_mid-1, post_lo, post_lo+left_length-1);
    root->right = build(inorder, postorder, in_mid+1, in_hi, post_lo+left_length, post_hi-1);
    return root;    

}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}


int main(int argc, char const *argv[])
{
    
    vector<int> inorder = {9, 3, 15,20,7};
    vector<int> postorder = {9, 15,7,20, 3};

    TreeNode* root = buildTree(inorder, postorder);
    preOrder(root);

    return 0;
}
