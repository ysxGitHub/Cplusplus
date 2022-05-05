/*
给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。
*/

#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> ans;
void preOrderTravesal(TreeNode* root, vector<int>&path){
    
    if(root->left==nullptr&&root->right==nullptr){
        path.emplace_back(root->val);
        ans.emplace_back(path);
        path.pop_back();
        return;
    }
    path.emplace_back(root->val);
    if(root->left) preOrderTravesal(root->left, path);
    if(root->right) preOrderTravesal(root->right, path);
    path.pop_back();
}

int dfs(TreeNode* root, int preSum){
    if(root==nullptr){return 0;}
    preSum = preSum*10 + root->val;
    // 这步就可以返回，防止进入左右节点重复计算
    if(root->left==nullptr&&root->right==nullptr){
        return preSum;
    }else{
        return dfs(root->left, preSum) + dfs(root->right, preSum);
    }
}

int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    cout<<sumNumbers(root)<<endl;
    return 0;
}
