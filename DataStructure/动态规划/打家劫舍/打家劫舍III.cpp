/*
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到
    “这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，
    房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
*/
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// first 表示 i-2 天的最多钱数, second 表示 i-1 天的最多钱数,
pair<int, int>helper(TreeNode* root){
    if(root==nullptr) return make_pair(0,0);
    auto left = helper(root->left);
    auto right = helper(root->right);
    // 抢劫今天, 就需要加上 i-2 天的最多钱数
    int robm = root->val + left.first + right.first;
    // 不抢劫今天, 就需要判读 i-1 天 还是 i-2 天的 最多钱数
    int no_robm = max(left.first, left.second) + max(right.first, right.second);
    // 返回 (不抢劫今天, 抢劫今天)
    return make_pair(no_robm, robm);
}

int rob(TreeNode* root) {
    int num1 = helper(root).first, num2 = helper(root).second;
    return num1>num2?num1:num2;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
