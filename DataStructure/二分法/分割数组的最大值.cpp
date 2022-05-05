/*
给定一个非负整数数组 nums 和一个整数 m ，你需要将这个数组分成 m 个非空的连续子数组。
    设计一个算法使得这 m 个子数组各自和的最大值最小。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 计算可以分割出几个和为maxnum这样的子数组
int split(vector<int>& nums, int maxnum){
    int cnt=1, sums=0;
    for(auto&n: nums){
        sums+=n;
        if(sums>maxnum){
            cnt++;
            sums=n;
        }
    }
    return cnt;
}

int splitArray(vector<int>& nums, int m) {
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);
    while (left <= right){
        int mid = left + (right - left)/2;
        int mm = split(nums, mid);
        if(mm > m){
            left = mid + 1;
        }
        else if(mm <= m){
            right = mid - 1;
        }
        // else{
        //     right = mid - 1;
        // }
    }
    return left;
}

int main(int argc, char const *argv[])
{
    vector<int> nums={2,7,9,2,1,2,3,6};
    // cout<<split(nums,10);
    cout<<splitArray(nums, 10)<<endl;
    return 0;
}
