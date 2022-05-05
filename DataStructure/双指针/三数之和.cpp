/*

*/

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<unordered_set>
using namespace std;

vector<vector<int>>ans;
void backtrack(vector<int>& nums, vector<int>& path, int level){
    if(path.size()==3){
        if(accumulate(path.begin(), path.end(), 0)==0){
            ans.emplace_back(path);
        }
        return;
    }

    for(int i=level; i<nums.size(); i++){
        // 如果前面的相邻相等元素没有用过，则跳过
        if(i>level && nums[i]==nums[i-1]){
            continue;
        }
        path.emplace_back(nums[i]);
        backtrack(nums, path, i+1);
        path.pop_back();
    }

}

// 回溯法超时
vector<vector<int>> threeSum1(vector<int>& nums) {
    vector<int>path;
    sort(nums.begin(), nums.end());
    backtrack(nums, path, 0);
    return ans;
}

void twoSum(vector<int>& nums, int left, int right, int target){
    while(left<right){
        int sum = nums[left] + nums[right];
        int tmpLeft = nums[left], tmpRight = nums[right];
        if(target > sum){
            // while 要调过相同元素，防止重复添加相同 vector
            while(left<right&&nums[left]==tmpLeft){++left; }
        }
        else if(target < sum){
            while(left<right&&nums[right]==tmpRight){--right;}
        }
        else{
            // 注意这里添加的是 -target, target + nums[left] + nums[right] = 0;
            ans.push_back({-target, nums[left], nums[right]});
            while(left<right&&nums[left]==tmpLeft){++left; }
            while(left<right&&nums[right]==tmpRight){--right;}
        }

    }

}

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    // 先排序
    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        // 跳过相同元素
        if(i>0&&nums[i]==nums[i-1]){
            continue;
        }
        // 这里 right 的起始点要从下一个元素开始 i+1，不能取自己（重复）， 
        twoSum(nums, i+1, n-1, -nums[i]);
    }
    
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 0, 1, 2, -1, 1, -4};
    // -4, -1, -1, 0, 1, 2
    vector<vector<int>>ans = threeSum(nums);
    for(auto&nn: ans){
        cout<<nn[0]<<','<<nn[1]<<','<<nn[2]<<endl;
    }
    return 0;
}
