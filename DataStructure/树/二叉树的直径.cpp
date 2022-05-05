/*
给定一棵二叉树，你需要计算它的直径长度。
    一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
    这条路径可能穿过也可能不穿过根结点。
*/

#include<iostream>

using namespace std;

int maxlen=0;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int diameterOfBinaryTree(TreeNode* root) {
    if(root==nullptr){
        return 0;
    }else{
        int ldeep = diameterOfBinaryTree(root->left);
        int rdeep = diameterOfBinaryTree(root->right);
        if(ldeep + rdeep > maxlen){
            maxlen = ldeep+rdeep;
        }
        int maxdeep = ldeep > rdeep ? ldeep : rdeep;
        return ++maxdeep;
    }

}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    diameterOfBinaryTree(root);
    cout<<maxlen<<endl;

    return 0;
}
