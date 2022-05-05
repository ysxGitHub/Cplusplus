/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using  namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int>nums;
void inOrder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    inOrder(root->left);
    nums.push_back(root->val);
    inOrder(root->right);
}
bool isValidBST(TreeNode* root) {
    if(root->left==nullptr&&root->right==nullptr){
        return true;
    }
    else{
        inOrder(root);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        return true;
    }
}

// 注意这里要用long long
bool helper(TreeNode* root, long long low, long long up){
    if(root==nullptr){
        return true;
    }
    if(root->val<=low||root->val>=up){
        return false;
    }
    return helper(root->left, low, root->val)&&helper(root->right, root->val, up);
}

bool isValidBST1(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}

int main(int argc, char const *argv[])
{
    // 5,3,6,2,4,null,7
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(7);

    inOrder(root);
    for(auto&n: nums){
        cout<<n<<" ";
    }

    return 0;
}