/*
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
    创建一个根节点，其值为 nums 中的最大值。
    递归地在最大值 左边 的 子数组前缀上 构建左子树。
    递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template <typename T>
vector<int> sort_indexes(const vector<T>& v) 
{

	// 初始化索引
	vector<int> idx(v.size());
	for (int i = 0; i < idx.size(); i++) idx[i] = i;

	// 根据vector的值对索引排序
	sort(idx.begin(), idx.end(),
		[&v](int i1, int i2) -> bool{return v[i1] > v[i2]; }); //C++11 Lambda表达式

	return idx;
}

TreeNode* builtTree(vector<int>& nums, int lo, int hi){
    if(lo>hi){
        return nullptr;
    }
    int maxnum = -1;
    int maxid = -1;
    for(int i=lo; i<=hi; i++){
        if(nums[i]>maxnum){
            maxnum = nums[i];
            maxid = i;
        }
    }
    TreeNode* root = new TreeNode(maxnum);
    root->left = builtTree(nums, lo, maxid-1);
    root->right = builtTree(nums, maxid+1, hi);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return builtTree(nums, 0, nums.size()-1);
}


int main(int argc, char const *argv[])
{
    vector<int>nums = {2,3,4,2,0};
    

    return 0;
}
