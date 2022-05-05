/*
给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，
    满足 i < j 且 |nums[i] - nums[j]| == k 。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。

*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int countKDifference(vector<int>& nums, int k) {
    if(nums.size()==1){
        return 0;
    }
    int ans = 0;  
    unordered_multiset<int>seen;
    seen.insert(nums[0]);
    for(int i=1; i<nums.size(); i++){
        ans+=seen.count(nums[i]-k) + seen.count(nums[i]+k);
        seen.insert(nums[i]);
    }
    return ans;
}


int countKDifference1(vector<int>& nums, int k) {
    int size = nums.size();
    if(size==1){
        return 0;
    }
    int ans = 0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(abs(nums[i]-nums[j])==k){
                ans++;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
