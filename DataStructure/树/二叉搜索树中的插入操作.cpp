/*
给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。
    返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 
    你可以返回 任意有效的结果 。

*/

#include<iostream>
#include<queue>
using  namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void levelOrder(TreeNode* root){
    queue<TreeNode*>node;
    node.push(root);
    while (!node.empty()){/* code */
        TreeNode* tmp = node.front();
        cout<<tmp->val<<"  ";
        node.pop();
        if(tmp->left){
            node.push(tmp->left);
        }
        if(tmp->right){
            node.push(tmp->right);
        }
    }
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root==nullptr){
        root = new TreeNode(val);
        return root;
    }
    else if (root->val > val){
        root->left = insertIntoBST(root->left, val);
    }
    else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
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

    levelOrder(root);
    cout<<endl;

    root = insertIntoBST(root, 6);

    levelOrder(root);
    cout<<endl;

    return 0;
}
