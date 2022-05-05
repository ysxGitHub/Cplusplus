/*
给你一棵二叉树，它的根为 root 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。

由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。
*/

#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int>treeSum;
int mod = pow(10, 9) + 7;
int postTree(TreeNode* root) {
    if(root==nullptr){return 0;}
    int sum = postTree(root->left) + postTree(root->right) + root->val;
    return sum;
}

int maxProduct(TreeNode* root) {
    long long ans = 0;
    int maxNum = treeSum.back();
    for(int n: treeSum){
        long long tmp = n*(maxNum-n);
        if(tmp>ans) ans = tmp;
    }

    return ans%mod;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
