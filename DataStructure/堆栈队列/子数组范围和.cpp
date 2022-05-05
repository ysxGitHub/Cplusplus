/*
给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。

返回 nums 中 所有 子数组范围的 和 。

子数组是数组中一个连续 非空 的元素序列。
*/

#include<vector>
#include<stack>
#include<iostream>
using namespace std;

// 暴力破解
long long subArrayRanges1(vector<int>& nums) {
    long long ans = 0;
    for(int i=0; i<nums.size(); i++){
        int minnum = nums[i], maxnum = nums[i];
        for(int j=i+1; j<nums.size(); j++){
            if(nums[j]>maxnum){
                maxnum = nums[j];
            }
            if(nums[j]<minnum){
                minnum = nums[j];
            }
            ans += (maxnum - minnum);
        }
    }
    return ans;
}


void getLeft(vector<int>& nums, vector<int>& leftGreater, vector<int>& leftLess){
    int  n = nums.size();
    stack <int> decrease, increase;
    for(int i=0; i<n; i++){
        while(!decrease.empty()&&nums[decrease.top()]<nums[i]){
            decrease.pop();
        }
        leftGreater[i] = decrease.empty() ? -1 : decrease.top();
        decrease.emplace(i);
    }
    
    for(int i=0; i<n; i++){
        while(!increase.empty()&&nums[increase.top()]>nums[i]){
            increase.pop();
        }
        leftLess[i] = increase.empty() ? -1 : increase.top();
        increase.emplace(i);
    }   

}


void getRight(vector<int>& nums, vector<int>& rightGreater, vector<int>& rightLess){
    int  n = nums.size();
    stack <int> decrease, increase;
    for(int i=n-1; i>=0; i--){
        while(!decrease.empty()&&nums[decrease.top()]<=nums[i]){
            decrease.pop();
        }
        rightGreater[i] = decrease.empty() ? n : decrease.top();
        decrease.emplace(i);
    }
    
    for(int i=n-1; i>=0; i--){
        while(!increase.empty()&&nums[increase.top()]>=nums[i]){
            increase.pop();
        }
        rightLess[i] = increase.empty() ? n : increase.top();
        increase.emplace(i);
    }   

}



long long subArrayRanges(vector<int>& nums) {
    long long sum = 0;

    int n = nums.size();
    vector<int> leftGreater(n), leftLess(n), rightGreater(n), rightLess(n);
    getLeft(nums, leftGreater, leftLess);
    getRight(nums, rightGreater, rightLess);
    
    for(int i=0; i<n; i++){
        sum += (nums[i]*((long long)i - leftGreater[i])*((long long)rightGreater[i] - i));
        sum -= (nums[i]*((long long)i - leftLess[i])*((long long)rightLess[i] - i));
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    vector<int> nums={4,-2,-3,4,1};
    cout<<subArrayRanges(nums)<<endl;
    return 0;
}
