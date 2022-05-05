/*
有一个整型数组，数组元素不重复，数组元素先升序后降序，
例如：1,3,5,7,9,10,8,6,4,2，请写一个函数找出数组最大的元素。
*/
#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int>nums){
    int n = nums.size();
    int left = 0, right = n-1;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(nums[mid]<nums[mid+1]){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    // 寻找的是左边界
    return nums[left];
}

int main(int argc, char const *argv[])
{
    vector<int>nums={5,9,11,10,9,8,6,4,2};
    cout<<findMax(nums);
    return 0;
}
