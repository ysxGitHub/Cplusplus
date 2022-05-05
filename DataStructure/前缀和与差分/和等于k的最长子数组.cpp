/*
给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长连续子数组长度。
    如果不存在任意一个符合要求的子数组，则返回 0。
*/
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int>hash;
    // 这个初始化很重要，应对0~i的和等于k时 ***********
    hash[0] = -1; 
    int res = 0;
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        // 计算前缀和
        sum += nums[i];
        // 找到了和等于k的子数组，计算子数组长度
        if(hash.count(sum - k)){
            res = max(res, i - hash[sum - k]);
        }
        // 如果sum已经存在了，就不再记录了，保存最早的下标
        /*
            {3,1,2,1,1,1,1,2}
            hash = (3,0), (4,1), (6,2), (7,3), (8,4),... 
                   3-4=-1 4-4=0  6-4=2  7-4=3  8-4=4 ...
                                        (3,0)  (4,1) ...
                                        3-0=3  4-1=3 ...
        */
        if(!hash.count(sum)){
            hash[sum] = i;
        }
    }
    return res;
}



int main(int argc, char const *argv[])
{
    vector<int> nums={3,1,2,1,1,1,1,2};
    cout<<maxSubArrayLen(nums, 4)<<endl;
    return 0;
}

