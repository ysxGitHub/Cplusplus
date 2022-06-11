/*
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
*/
#include<vector>
#include<iostream>
using namespace std;

int thirdMax(vector<int>& nums) {
    int n = nums.size();
    long long third=INT64_MIN, second=INT64_MIN, first=INT64_MIN;
    for(int i=0; i<n; i++){
        if(nums[i]>first){
            third = second;
            second = first;
            first = nums[i];
        }else if(first>nums[i]&&nums[i]>second){
            third = second;
            second = nums[i];
        }else if(second>nums[i]&&nums[i]>third){
            third = nums[i];
        }
    }
    return third==INT64_MIN?first:third;
}