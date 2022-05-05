/*
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    if(root==nullptr){
        return nullptr;
    } 
    TreeNode* left_root = invertTree(root->left);
    TreeNode* right_root = invertTree(root->right);
    root->left = right_root;
    root->right = left_root;
    return root;
}

void levelOrder(TreeNode* root){
    queue<TreeNode*>nodes;
    nodes.push(root);
    while(!nodes.empty()){
        // 遍历这一层的所有节点
        TreeNode* node = nodes.front();
        nodes.pop();
        cout<<node->val<<"  ";
        // 加入左右子节点
        if(node->left){
            nodes.push(node->left);
        }
        if(node->right){
            nodes.push(node->right);
        }
    }
    
}

int main(int argc, char const *argv[])
{
    // [4,2,7,1,3,6,9]
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    TreeNode* rroot = invertTree(root);

    levelOrder(rroot);
    
    return 0;
}
