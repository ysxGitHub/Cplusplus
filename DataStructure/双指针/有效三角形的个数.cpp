/*
给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int res = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int left = j+1, right = n-1;
            int sum = nums[i] + nums[j];
            while(left<=right){
                int mid = (left+right)/2;
                if(nums[mid]<sum){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            res += right - j;
        }
    }
    return res;
}


int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int res = 0;
    for (int i = n - 1; i >= 2; --i) {
        int left = 0, right = i - 1;
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                res += right - left;
                --right;
            } else {
                ++left;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,5,6,7};
    triangleNumber(nums);
    return 0;
}
