/*
合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面
    的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。

给定一个数组 nums 代表了集合 S 发生错误后的结果。

请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
*/
#include<iostream>
#include<vector>

using namespace std;


vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int dup = -1;
    // 先将所有的数对应坐标，将已查询的数取相反数
    for(int i=0; i<n; i++){
        int idx = abs(nums[i]) - 1;
        if(nums[idx]<0){
            dup = abs(nums[i]);
        }else{
            nums[idx]*=-1;
        }
    }
    // 丢失的数，对应idx 中 数组的值没有变
    int miss = -1;
    for(int i=0; i<n; i++){
        if(nums[i]>0){
            miss = i + 1;
        }
    }
    return {dup, miss};
}

int main(int argc, char const *argv[])
{

    return 0;
}
