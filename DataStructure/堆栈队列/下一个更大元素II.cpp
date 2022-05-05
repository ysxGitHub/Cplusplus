/*
给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），
    返回 nums 中每个元素的 下一个更大元素 。

数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，
    这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。

解题技巧：数组加倍 + 遇见环形  记得取模
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int>s;
    for(int i = 2*n-1; i>=0; i--){
        while(!s.empty()&&nums[i%n] >= s.top()){
            s.pop();
        }
        ans[i%n] = s.empty() ? -1 : s.top();
        s.emplace(nums[i%n]);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,1,2,4,3};
    nums = nextGreaterElements(nums);
    for(auto&n: nums){
        cout<<n<<", ";
    }
    return 0;
}
