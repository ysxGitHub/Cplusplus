/*
给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，
    其中，每个斐波那契数字都可以被使用多次。
*/
#include<iostream>
#include<vector>
using namespace std;



void fibona(int n, vector<int>& nums){
    if(n==1){
        nums.push_back(1);
        return ;
    }else if(n==2){
        nums.push_back(1);
        nums.push_back(1);
        return ;
    }
    else{
        int ans = 0;
        int prev = 1;
        int cur = 1;
        nums.push_back(1);
        nums.push_back(1);
        for(int i=2; i<n; i++){
            ans = prev + cur;
            nums.push_back(ans);
            prev = cur;
            cur = ans;
        }
        return ; 
    }
}

void subfib(int k, vector<int>& nums, int& ans){
    if(k==0){
        return;
    }
    for(int i=(nums.size()-1); i>=0; i--){
        if(nums[i]<=k){
            ans++;
            k = k - nums[i];
            subfib(k, nums, ans);
            break;
        }
    }
}

int findMinFibonacciNumbers(int k) {
    int ans = 0;
    vector<int>nums;
    fibona(46,nums);
    for(auto& n : nums){
        cout<<n<<"  ";
    }
    subfib(k,nums,ans);
    return ans;
}


int main(int argc, char const *argv[])
{
    
    cout<<findMinFibonacciNumbers(3);
    return 0;
}
