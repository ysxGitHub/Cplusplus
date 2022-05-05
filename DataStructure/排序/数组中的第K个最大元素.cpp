/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


// 优先队列
int findKthLargest1(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for(auto&n: nums){
        pq.emplace(n);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

int partition(vector<int>& nums, int lo, int hi){
    int privot = nums[hi];
    int i = 0, j = 0;
    for(i; i<hi; i++){
        // 这里必须是 >= 或 <
        if(nums[i]>=privot){
            swap(nums[i], nums[j]);
            j++;
        }
    }
    swap(nums[j], nums[hi]);
    return j;
}

// 快速选择
int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size()-1;
    k--;
    while(left<=right){
        int mid = partition(nums, left, right);
        if(mid > k){
            right = mid - 1;
        }else if(mid < k){
            left = mid + 1; 
        }else{
            return nums[mid];
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
