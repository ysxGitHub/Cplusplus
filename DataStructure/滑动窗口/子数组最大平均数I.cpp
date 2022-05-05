/*
给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。

请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。

任何误差小于 10-5 的答案都将被视为正确答案。
*/
#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int start=0, sum=0;
    double ans = INT64_MIN;
    int n = nums.size();
    for(int i=0; i<n; i++){
        sum+=nums[i];
        if(i-start+1==k){
            ans = max(ans, (double)sum/k);
            sum -= nums[start];
            start++;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
