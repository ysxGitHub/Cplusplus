
/*
输入一棵二叉树的根节点，求该树的深度。
从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
*/

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



int maxDepth(TreeNode* root) {
    if(root==nullptr){
        return 0;
    }else{
        int ldeep = maxDepth(root->left);
        int rdeep = maxDepth(root->right);
        int maxdeep = ldeep > rdeep ? ldeep : rdeep;
        return ++maxdeep;
    }
}

int main(int argc, char const *argv[])
{
    // [3,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout<<maxDepth(root)<<endl;

    return 0;
}
