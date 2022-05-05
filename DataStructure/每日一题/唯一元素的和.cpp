/*
给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。

请你返回 nums 中唯一元素的 和 。

*/
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int>sums;
    int ans = 0;
    for(auto&n : nums){
        if(sums.find(n)==sums.end()){
            sums[n] = 1;
        }else{
            sums[n] += 1;
        }
    }
    for(auto&s : sums){
        if(s.second==1){
            ans+=s.first;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums={1,2,2,3,4,4,5};
    cout<<sumOfUnique(nums);
    return 0;
}
