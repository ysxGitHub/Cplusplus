/*
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
    返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
*/

#include<vector>
#include<iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if(size == 0){return 0;}
    // 这个初始化很关键，可以处理 size=1, 2的这两种情况，刚开始 left 与 right 指向同样位置
    // left = 0, ++left, return left+1;
    int left = 1, right = 1;
    while(right < size){
        // 当 前一个元素与当前元素不同时，将left的元素替换为right位置的元素，并将left右移一位
        if(nums[right] != nums[right-1]) {
            nums[left] = nums[right];
            ++left;
        }
        // right不断右移动
        ++right;
    }
    // 返回的就是left最后停止的位置
    return left;
}

int main(int argc, char const *argv[])
{
    vector<int>nums = {0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(nums)<<endl;
    return 0;
}
