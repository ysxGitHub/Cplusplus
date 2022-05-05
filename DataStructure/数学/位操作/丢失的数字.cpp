/*
给定一个包含 [0, n] 中 n 个数的数组 nums ，
找出 [0, n] 这个范围内没有出现在数组中的那个数。
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/*
有序数列的和减去已知的
*/
int missingNumber1(vector<int>& nums) {
    int total = nums.size();
    int allsum = total*(total+1)/2;
    for(auto& i : nums){
        allsum-=i;
    }
    return allsum;
}

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    // 先和新补的索引异或一下
    res ^= n;
    // 和其他的元素、索引做异或
    for (int i = 0; i < n; i++)
        res ^= i ^ nums[i];
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int>nums={0,1,2,4};
    cout<<missingNumber(nums)<<endl;
    cout<<missingNumber1(nums)<<endl;
    return 0;
}

