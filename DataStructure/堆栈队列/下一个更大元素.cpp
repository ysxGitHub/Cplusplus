/*
Q1. 给你一个数组 nums，请你返回一个等长的结果数组，结果数组中对应索引存储着下一个更大元素，
    如果没有更大的元素，就存 -1。

Q2.nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，
    并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

*/
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;


vector<int> nextGreaterElement(vector<int>& nums){
    vector<int> ans(nums.size(), -1);
    stack<int> s;
    // 倒着放入栈
    for(int i = nums.size() - 1; i>=0; i--){
        // 小个子的走开
        while(!s.empty()&&s.top()<nums[i]){
            s.pop();
        }
        // 比当前个子大的下一位元素是否存在
        ans[i] = s.empty() ? -1 : s.top();
        // 将当前元素加入队列
        s.push(nums[i]);
    }
    return ans;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> ans;
    stack<int>s;
    for(int i=nums2.size()-1; i>=0; i--){
        while(!s.empty()&&nums2[i]>s.top()){
            s.pop();
        }
        ans[nums2[i]] = s.empty()? -1 : s.top();
        s.emplace(nums2[i]);
    }
    vector<int> res;
    for(auto&n: nums1){
        res.emplace_back(ans[n]);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,1,2,4,3};
    nums = nextGreaterElement(nums);
    for(auto&n: nums){
        cout<<n<<", ";
    }
    return 0;
}
