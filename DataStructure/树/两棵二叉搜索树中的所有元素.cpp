/*
给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。
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

void inorder(TreeNode *node, vector<int> &res) {
    if (node) {
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> nums1, nums2;
    inorder(root1, nums1);
    inorder(root2, nums2);

    vector<int> merged;
    auto p1 = nums1.begin(), p2 = nums2.begin();
    while (true) {
        if (p1 == nums1.end()) {
            merged.insert(merged.end(), p2, nums2.end());
            break;
        }
        if (p2 == nums2.end()) {
            merged.insert(merged.end(), p1, nums1.end());
            break;
        }
        if (*p1 < *p2) {
            merged.push_back(*p1++);
        } else {
            merged.push_back(*p2++);
        }
    }
    return merged;
}