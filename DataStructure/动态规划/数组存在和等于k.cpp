/*
给定一个数组 nums 和 一个目标值 k，找到和等于 k 的子序列 返回 1。
    如果不存在任意一个符合要求的子序列，则返回 0。
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


bool dp_subset(vector<int>& nums, int sum){

    int length = nums.size();
    // dp nums[...i] 是否能组成 sum 
    vector<vector<bool>>subset(length, vector<bool>(sum+1));

    for(int i=0; i<length; i++) subset[i][0] = true;

    for(int j=1; j<sum+1; j++) subset[0][j] = false;

    if(nums[0]<sum+1) subset[0][nums[0]] = true;
    
    
    for(int i=1; i<length; i++){
        for(int j=1; j<sum+1; j++){
            // 该数 大于 当前和
            if(nums[i]>j){
                // 不考虑加入此数, 直接 等于 前一个等于 当前和 状态
                subset[i][j] = subset[i-1][j];
            }
            else{
                // 前一个等于 当前和 状态 以及 前一个状态 和减掉 当前数值 都不成立时
                if(subset[i-1][j-nums[i]]==false&&subset[i-1][j]==false){
                    subset[i][j] = false;
                }else{
                    subset[i][j] = true;
                }
            }
        }
    }
    return subset[length-1][sum];
}


int main(int argc, char const *argv[])
{
    vector<int>nums = {1,2,3,5};
    cout<<dp_subset(nums, 9)<<endl;
    return 0;
}

