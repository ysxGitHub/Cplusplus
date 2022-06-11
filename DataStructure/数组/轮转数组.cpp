/*
给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
*/
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

// 1
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> newArr(n);
    for (int i = 0; i < n; ++i) {
        newArr[(i + k) % n] = nums[i];
    }
    nums.assign(newArr.begin(), newArr.end());
}

// 2
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    int count = gcd(k, n);
    for (int start = 0; start < count; ++start) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % n;
            swap(nums[next], prev);
            current = next;
        } while (start != current);
    }
}

// 3
void rotate(vector<int>& nums, int k) {
    vector<int>ans;
    int n = nums.size();
    k = k%n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}