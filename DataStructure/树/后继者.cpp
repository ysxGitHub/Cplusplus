/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
如果指定节点没有对应的“下一个”节点，则返回null。
*/

#include <iostream>
#include <stack>
using  namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    stack<TreeNode*> V;
    TreeNode* T = root;
    bool flag = 0;
    while(T||!V.empty()){
        while(T){
            V.emplace(T);
            T = T->left;
        }
        if(!V.empty()){
            T = V.top();
            V.pop();
            if(flag) return T;
            if(T == p) flag = 1;
            T = T->right;
        }
    }
    return nullptr;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    return root == nullptr ? root : (root->val > p->val ? (inorderSuccessor(root->left, p) == nullptr ? root : inorderSuccessor(root->left, p)): inorderSuccessor(root->right, p));
}