/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
    并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
*/
#include<iostream>
using  namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    cout<<root->val<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}

TreeNode* getNode(TreeNode* root){
    while(root->left){
        root = root->left; 
    }
    return root; 
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==nullptr){
        return nullptr;
    }
    if(root->val == key){
        // 要删除的节点都没有左右子节点，返回空节点
        if(root->left==nullptr&&root->right==nullptr){
            return nullptr;
        }
        // 要删除的节点有左子节点，返回左子节点
        if(root->left==nullptr&&root->right!=nullptr){
            return root->right;
        }
        // 要删除的节点有右子节点，返回右子节点
        if(root->left!=nullptr&&root->right==nullptr){
            return root->left;
        }
        // 要删除的节点有左右子节点
        // 寻找右子节点最小的子节点，一定在右子节点的最左边
        TreeNode* minNode = getNode(root->right);
        // 删除右子节点的最左边的节点
        root->right = deleteNode(root->right, minNode->val);
        // leftMaxNode->left = root->left;
        // leftMaxNode->right = root->right;
        // root = leftMaxNode;
        // 用右子节点的最左边的节点的值替换当前节点的值
        root->val = minNode->val;

    }else if(root->val > key){
        root->left = deleteNode(root->left, key);
    }else{
        root->right = deleteNode(root->right, key);
    }
    return root;
}



TreeNode* deleteNode1(TreeNode* root, int key) {
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while(cur && cur->val != key){
        pre = cur;
        if(cur->val > key) cur = cur->left;
        else if(cur->val < key) cur = cur->right;
        else break;
    }
    // 不存在，直接返回
    if(!cur) return root;
    // 要删除的节点为叶子时
    if(!cur->left && !cur->right){
        if(!pre){return nullptr; }
        if(pre->left==cur) pre->left = nullptr;
        else pre->right = nullptr;
    }
    // 要删除的节点有两个子节点时
    else if(cur->left && cur->right){
        TreeNode* rightMin = cur->right;
        pre = cur;
        while(rightMin->left){
            pre = rightMin;
            rightMin = rightMin->left;
        }
        cur->val = rightMin->val;
        // 如果右子节点没有左节点时
        if(pre==cur) cur->right = rightMin->right;
        // 如果右子节点有左节点时, 应该将右边最左的节点右子节点赋给上一个节点
        else pre->left = rightMin->right;
    }
    // 要删除的节点有一个子节点时
    else{
        TreeNode* One = cur->left ? cur->left : cur->right;
        if(!pre) return One;
        if(pre->left == cur) pre->left = One;
        else pre->right = One;
    }
    return root;
}

int main(int argc, char const *argv[])
{
    // 5,3,6,2,4,null,7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    preOrder(root);

    cout<<endl;
    root = deleteNode1(root, 5);

    preOrder(root);

    return 0;
}
