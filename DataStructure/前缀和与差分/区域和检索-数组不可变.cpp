/*
给定一个整数数组  nums，处理以下类型的多个查询:

计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
实现 NumArray 类：

NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j) 返回数组 nums 中索引 left 和 right 之间的元素的 总和 ，
    包含 left 和 right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )

*/
#include<iostream>
#include<vector>

using namespace std;

class NumArray {
vector<int>sumarr;
public:
    NumArray(vector<int>& nums) {
        sumarr.resize(nums.size());
        sumarr[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            sumarr[i] = sumarr[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return sumarr[right];
        }else{
            return sumarr[right] - sumarr[left-1];
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,4,7,-4};
    NumArray na(nums);

    cout<<na.sumRange(1,4);

    return 0;
}
