/*
定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
*/
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>mymap;
    vector<int> result;
    for(int i=0; i<nums.size(); i++){
        if(mymap.find(target-nums[i])==mymap.end()){
            mymap[nums[i]] = i;
        }else{
            result.push_back(mymap[target-nums[i]]);
            result.push_back(i);
        }
    }
    return result;
}

// 除去重复的答案版 eg: nums = [1,2,3,1,2], target = 3
vector<vector<int>> twoSumTarget(vector<int>& nums, int target) {
    // nums 数组必须有序
    sort(nums.begin(), nums.end());
    int lo = 0, hi = nums.size() - 1;
    vector<vector<int>> res;
    while (lo < hi) {
        int sum = nums[lo] + nums[hi];
        int left = nums[lo], right = nums[hi];
        if (sum < target) {
            while (lo < hi && nums[lo] == left) lo++;
        } else if (sum > target) {
            while (lo < hi && nums[hi] == right) hi--;
        } else {
            res.push_back({left, right});
            while (lo < hi && nums[lo] == left) lo++;
            while (lo < hi && nums[hi] == right) hi--;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int>nums={2, 7, 11, 15, 3};

    int target = 10;

    vector<int>result = twoSum(nums, target);

    cout<<result[0]<<"  "<<result[1]<<endl;

    return 0;
}
