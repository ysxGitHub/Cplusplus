/*
求数组中比左边元素都大同时比右边元素都小的元素，返回这些元素的索引
要求时间复杂度 O(N)

输入：[2, 3, 1, 8, 9, 20, 12]
输出：3, 4
解释：数组中 8, 9 满足题目要求，他们的索引分别是 3、4

类似334
*/
#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

// 法1：dp
vector<int> find_middle_index(vector<int> nums) {
    vector<int> res;
    int n = nums.size();
    vector<int> left_max(n, INT_MIN);
    vector<int> right_min(n, INT_MAX);
    // dp 储存每一个元素左边最大的元素
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i - 1], nums[i - 1]);
    }
    // dp 储存每一个元素右边最小的元素
    for (int i = n - 2; i >= 0; i--) {
        right_min[i] = min(right_min[i + 1], nums[i + 1]);
    }
    // 
    for (int i = 0; i < n; i++) {
        if (left_max[i] < nums[i] && nums[i] < right_min[i]) {
            res.push_back(i);
        }
    }
    return res;
}

// 法2：单调栈
vector<int> find_middle_index1(vector<int> nums) {
    int n = nums.size();
    vector<int> ans;
    stack<int> stk;
    vector<int> rightmin(n, INT32_MAX);
    vector<int> leftmax(n, INT32_MIN);
    for(int i=n-1; i>=0; i--){
        while(!stk.empty()&&nums[i]<stk.top()){
            stk.pop();
        }
        rightmin[i] = stk.empty() ? nums[i] : stk.top();
        stk.emplace(nums[i]);
    }

    for(int i=0; i<n; i++){
        while(!stk.empty()&&nums[i]>stk.top()){
            stk.pop();
        }
        leftmax[i] = stk.empty() ? nums[i] : stk.top();
        stk.emplace(nums[i]);
    }
    for(int i=0; i<n; i++){
        if(nums[i]==leftmax[i]&&nums[i]==rightmin[i]){
            ans.emplace_back(i);
        }
    }
    return ans;

}


int main()
{
    vector<int> arr = {2,3,1,8,9,20,12};
    auto res = find_middle_index1(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
}
