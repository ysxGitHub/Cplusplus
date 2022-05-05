/*
给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 
    如果节点不存在，则返回 null 。

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


TreeNode* ans;
TreeNode* searchBST(TreeNode* root, int val) {
    if(root==nullptr){
        return nullptr;
    }
    if(root->val == val){
        ans = root;
        // return root;
    }
    else if(root->val > val){
        root->left = searchBST(root->left, val);
    }
    else{
        root->right = searchBST(root->right, val);
    }
    return ans;
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

    root = searchBST(root, 2);

    levelOrder(root);
    cout<<endl;

    return 0;
}