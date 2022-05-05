/*
给你一个数组 nums ，请你完成两类查询。

其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，   
    其中 left <= right

实现 NumArray 类：

    NumArray(int[] nums) 用整数数组 nums 初始化对象
    void update(int index, int val) 将 nums[index] 的值 更新 为 val
    int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间
        （ 包含 ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）

*/
#include<bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int>tree;
    int N;

    void built_tree(vector<int>& nums, vector<int>&tree, int root, int start, int end){
        if(start==end){
            tree[root] = nums[start];
            return ;
        }
        int mid = (end - start)/2 + start;
        int left_root = root*2 + 1;
        int right_root = root*2 + 2;
        built_tree(nums, tree, left_root, start, mid);
        built_tree(nums, tree, right_root, mid+1, end);
        tree[root] = tree[left_root] + tree[right_root];
    }
    void update_tree(vector<int>&tree, int root, int start, int end, int index, int value){
        if(start==end){
            tree[root] = value;
            return ;
        }
        int mid = (end - start)/2 + start;
        int left_root = root*2 + 1;
        int right_root = root*2 + 2;       
        if(index>=start&&index<=mid){
            update_tree(tree, left_root, start, mid, index, value);
        }else{
            update_tree(tree, right_root, mid+1, end, index, value);
        }
        tree[root] = tree[left_root] + tree[right_root];
    }
    int query_tree(vector<int>&tree, int root, int start, int end, int left, int right){
        if(right<start||left>end){
            return 0;
        }else if((left<=start&&right>=end)||start==end){
            return tree[root];
        }else{
            int mid = (end - start)/2 + start;
            int left_root = root*2 + 1;
            int right_root = root*2 + 2;                
            int left_sum = query_tree(tree, left_root, start, mid, left, right);
            int right_sum = query_tree(tree, right_root, mid+1, end, left, right);
            return left_sum + right_sum;
        }
    }

public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        tree.resize(N*10);
        built_tree(nums, tree, 0, 0, N-1);
    }
    
    void update(int index, int val) {
        update_tree(tree, 0, 0, N-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query_tree(tree, 0, 0, N-1, left, right);
    }
};

int main(int argc, char const *argv[])
{
    unordered_set<pair<int, int>>test;
    test.emplace(1,2);
    return 0;
}
