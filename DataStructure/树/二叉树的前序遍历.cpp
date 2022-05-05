#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void Traversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    nums.push_back(root->val);
    // 前序遍历
    Traversal(root->left);
    // 中序遍历
    Traversal(root->right);
    // 后序遍历
}

vector<int> preorderTraversal1(TreeNode *root)
{
    Traversal(root);
    return nums;
}


vector<int> preorderTraversal(TreeNode *root)
{
    // vector<int> nums;
    // if(root==nullptr){
    //     return nums;
    // }
    // nums.push_back(root->val);
    // nums.insert(nums.end(),preorderTraversal(root->left).begin(),preorderTraversal(root->left).end());
    // nums.insert(nums.end(),preorderTraversal(root->right).begin(),preorderTraversal(root->right).end());
}


int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    vector<int> nums = preorderTraversal1(root);
    for (auto &n : nums)
    {
        cout << n << endl;
    }

    return 0;
}
