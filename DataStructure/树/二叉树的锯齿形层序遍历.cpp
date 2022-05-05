/*
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
*/

#include<vector>
#include<iostream>
#include<queue>
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


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root==nullptr) return {};
    vector<vector<int>>ans;
    queue<TreeNode*> stk;
    stk.push(root);
    int i=1;
    while(!stk.empty()){
        int n = stk.size();
        vector<int>tmp;
        for(int i=0; i<n; i++){
            auto node = stk.front();
            tmp.push_back(node->val);
            stk.pop();
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
        }
        if(i%2==0) reverse(tmp.begin(), tmp.end());
        ans.push_back(tmp);
        i++;
    }
    return ans;
}


