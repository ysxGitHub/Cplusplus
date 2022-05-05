/*
1、如果把根节点看做第 1 层，如何打印出每一个节点所在的层数？

2、如何打印出每个节点的左右子树各有多少节点？
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void PrintLevel(TreeNode *root, int level){
    /*
    打印每个节点所在的层
    */
    if(root==nullptr){
        return;
    }
    cout<<"level: "<<level<<" val: "<<root->val<<endl;
    PrintLevel(root->left, level+1);
    PrintLevel(root->right, level+1);
}

int PrintEveryNode(TreeNode *root){
    /*
    打印每个节点的左右节点的数目
    */
    if(root==nullptr){
        return 0;
    }

    int leftc = PrintEveryNode(root->left);
    int rightc = PrintEveryNode(root->right);
    cout<<"left= "<<leftc<<"  ";
    cout<<"right= "<<rightc<<"  ";
    cout<<endl;

    return leftc+rightc+1;
}



int countNode(TreeNode *root){
    // 二叉树共有几个节点
    if(root==nullptr){
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    PrintLevel(root, 1);
    PrintEveryNode(root);
    return 0;
}
