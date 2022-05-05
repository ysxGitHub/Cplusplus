/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），
    可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

*/
#include<iostream>
#include<vector>

using namespace std;

int findDuplicate1(vector<int>& nums) {
    int n = nums.size();
    int fast = 0, slow=0;
    do{
        fast = nums[nums[fast]];
        slow = nums[slow];
    }while(fast!=slow);
    fast = 0; 
    while(fast!=slow){
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

/*
    nums = [1,2,2,2,4,6]
     idx    1,2,3,4,5,6
     cnt    1 4 4 5 5 6 
    目标 要找到第一个cnt[i]>idx的位置
        cnt为单调递增的
*/
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n-1;
    int ans = -1;
    while(left<=right){
        int mid = (left+right)>>1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += nums[i]<=mid;
        }
        if(cnt<=mid){ // 小于等于 mid 的元素个数 所有重复元素在右边
            left = mid + 1;
        }else{
            right = mid - 1;
            ans = mid;
        }
    }
    return ans;
}