/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

// 堆
int findKthLargest1(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());
    for(int i=1; i<k; i++){
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }
    return nums.front();
}

// 优先队列
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for(auto&n: nums){
        pq.emplace(n);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
