/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，
    而左子指针始终为 null 。

展开后的单链表应该与二叉树 先序遍历 顺序相同。

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


void preOrder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    cout<<root->val<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}


void flatten(TreeNode* root) {
    if(root==nullptr){
        return;
    }
    flatten(root->left);
    flatten(root->right);
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    TreeNode* tmp = root;
    TreeNode* tmp_left = left;
    root->left = nullptr;
    if(left==nullptr){
        return;
    }
    while (left){
        tmp->right = left;
        tmp = tmp->right;
        tmp_left = left;
        left = left->right;
    }
    tmp_left->right = right;
}

int main(int argc, char const *argv[])
{
    // vector<int>nums = {1, 2, 5, 3, 4, -1, 6};
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);

    while(root){
        cout<<root->val<<"  ";
        root = root->right;
    }

    return 0;
}
