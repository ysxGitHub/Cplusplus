/*
给你一棵以 root 为根的 二叉树 ，请你返回 任意 二叉搜索子树的最大键值和。

二叉搜索树的定义如下：

任意节点的左子树中的键值都 小于 此节点的键值。
任意节点的右子树中的键值都 大于 此节点的键值。
任意节点的左子树和右子树都是二叉搜索树。

*/

#include<iostream>
#include<vector>

using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans = 0;
vector<int> helper(TreeNode* root) {
    if(root==nullptr){
        return {1, -50000, 50000, 0};
    }
    vector<int> left_arr = helper(root->left);
    vector<int> right_arr = helper(root->right);
    vector<int> arr(4, 0);
    if(left_arr[0]==1&&right_arr[0]==1&&root->val>left_arr[1]&&root->val<right_arr[2]){
        arr[0] = 1;
        arr[1] = max(max(left_arr[1], right_arr[1]),root->val);
        arr[2] = min(min(left_arr[2], right_arr[2]),root->val);
        arr[3] = left_arr[3] + right_arr[3] + root->val;
        ans = max(ans, arr[3]);
    }
    else{
        arr={0,-50000, 50000, root->val};
    }
    return arr;
}

int maxSumBST(TreeNode* root) {
    helper(root);
    return ans;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(9);
    root->left = new TreeNode(4);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(11);
    cout<<maxSumBST(root)<<endl;
    return 0;
}
