/**

给定一个按照升序排列的整数数组 nums，和一个目标值 target。
    找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 */
#include <iostream>
#include <vector>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size()==0) return {-1, -1};
    vector<int>ans;
    int left=0, right=nums.size()-1, mid;
    // 搜索左边界
    while(left<=right){
        mid = left + (right - left)/2;
        if(nums[mid] >= target){
            right = mid-1;
        }
        else if(nums[mid]<target){
            left = mid+1;
        }
        // else{
        //     right = mid-1;
        // }
    }
    if(left>=nums.size()||nums[left]!=target)
        ans.emplace_back(-1);
    else
        ans.emplace_back(left);

    left=0, right=nums.size()-1;
    // 搜索右边界
    while(left<=right){
        mid = left + (right - left)/2;
        if(nums[mid]>target){
            right = mid-1;
        }
        else if(nums[mid]<=target){
            left = mid+1;
        }
        // else{
        //     left = mid+1;
        // }
    }
    if(right<0||nums[right]!=target){
        ans.emplace_back(-1);
    }else{
        ans.emplace_back(right);
    }

    return ans;
}