/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
    例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

*/

#include<vector>
#include<iostream>

using namespace std;


// 二分法
int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    vector<int>pokers(size, 0);
    // 牌堆
    int piles = 0;
    for(int i=0; i<size; i++){
        int poker = nums[i];
        int left = 0;
        int right = piles;

        while(left<right){
            int mid = (left+right)/2;
            if(pokers[mid]>=poker){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        if(left==piles){
            piles++;
        }
        pokers[left] = poker;
    }
    return piles;
}

// dp
int lengthOfLIS1(vector<int>& nums) {
    int size = nums.size();
    if(size==1){
        return 1;
    }
    vector<int>ans(size, 0);
    ans[0] = 1;
    int res=0;
    for(int i=1; i<size; i++){
        for(int j=i-1; j>=0; j--){
            if(nums[i]>nums[j]){
                ans[i] = max(ans[i], ans[j]+1);
            }
        }
        if(ans[i]==0){ans[i]=1;}
        // cout<<ans[i]<<"  ";
        if(ans[i]>res){
            res = ans[i];
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums={4,10,4,3,8,9};
    cout<<lengthOfLIS(nums);
    cout<<endl;
    cout<<lengthOfLIS1(nums);
    return 0;
}
