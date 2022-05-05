/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，
    返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/
int searchInsert(vector<int>& nums, int target) {
    int right = nums.size()-1, left = 0;
    while(left<=right){
        int mid = (left+right)>>1;
        if(nums[mid]>=target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}   
