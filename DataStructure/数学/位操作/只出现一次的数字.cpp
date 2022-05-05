/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
找出那个只出现了一次的元素。

*/
#include<vector>
#include<iostream>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for(auto& n: nums){
        result^=n;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    // 异或
    cout<<(2^5)<<endl;
    cout<<(2^2)<<endl;
    cout<<(2^0)<<endl;
    vector<int>nums={1,4,1,4,3};
    cout<<singleNumber(nums)<<endl;
    return 0;
}
