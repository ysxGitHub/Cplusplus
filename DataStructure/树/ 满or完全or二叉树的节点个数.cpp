/*
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，
    其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
    若最底层为第 h 层，则该层包含 1~ 2^h 个节点。

满二叉树 是一种特殊的完全二叉树，每层都是是满的，像一个稳定的三角形
*/
#include<iostream>
#include<cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 一般的二叉树节点个数统计
int countNodes(TreeNode* root) {
    if(root==nullptr){return 0;}
    return countNodes(root->left)+countNodes(root->right)+1;
}

// 那如果是一棵满二叉树，节点总数就和树的高度呈指数关系：
int countNodes1(TreeNode* root) {
    int h=0;
    // 统计满二叉树树高
    while (root!=nullptr){
        root = root->left;
        h++;
    }
    // 节点总数就是 2^h - 1
    return pow(2,h)-1;
}

// 完全二叉树比普通二叉树特殊，但又没有满二叉树那么特殊，
// 计算它的节点总数，可以说是普通二叉树和完全二叉树的结合版
int countNodes2(TreeNode* root) {
    TreeNode* l = root;
    TreeNode* r = root;
    int hl = 0;
    int hr = 0;
    while (l!=nullptr){
        l = l->left;
        hl++;
    }
    while (r!=nullptr){
        r = r->right;
        hr++;
    }
    if(hl==hr){
        return pow(2, hl)-1;
    }
    return countNodes2(root->left)+countNodes2(root->right)+1;
  
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
