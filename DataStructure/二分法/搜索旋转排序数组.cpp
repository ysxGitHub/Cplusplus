/*
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
    使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
    （下标 从 0 开始 计数）。
    例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
*/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if(n==1) return  nums[0]==target ? 0 : -1;
    int left = 0, right = n - 1;
    /*
    如果 [l, mid - 1] 是有序数组，且 target 的大小满足 [nums[l],nums[mid])，
        则我们应该将搜索范围缩小至 [l, mid - 1]，否则在 [mid + 1, r] 中寻找。
    如果 [mid, r] 是有序数组，且 target 的大小满足 (nums[mid+1],nums[r]]，
        则我们应该将搜索范围缩小至 [mid + 1, r]，否则在 [l, mid - 1] 中寻找。
    */
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]==target) return mid;
        // 一定有一部分的数组是有序的
        if(nums[mid]>=nums[0]){ // 两阶段都有可能
            if(target>=nums[0]&&nums[mid]>target){ // target<nums[0] 一定在右边
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }else{ // 一定在第二阶段
            if(nums[mid]<target&&target<=nums[n-1]){ // target>nums[n-1] 一定在左边
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{

    return 0;
}
