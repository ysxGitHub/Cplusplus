/*
给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。
    现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，
    要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

*/
#include<vector>
#include<iostream>
using namespace std;

vector<int> maxPreNum(vector<int>& nums, int k){
    vector<int>stk;
    int remain = nums.size() - k;
    // 用单调栈排除前面较小的元素
    for(int i=0; i<nums.size(); i++){
        while(remain&&!stk.empty()&&stk.back()<nums[i]){
            stk.pop_back();
            remain--;
        }
        stk.emplace_back(nums[i]);
    }
    // remain还有剩余，将数组后面的元素去掉
    while(remain){
        stk.pop_back();
        remain--;
    }
    return stk;
}

int compare(vector<int>& vx, int idx, vector<int>& vy, int idy) {
    int x = vx.size(), y = vy.size();
    while (idx < x && idy < y) {
        int tag = vx[idx++] - vy[idy++];
        // 如果两个数不相等直接返回
        if (tag != 0) return tag;
    }
    // 超出数组大小范围时 idx = x, return <0; 或 idy = y, return >0;
    return (x - idx) - (y - idy);
}

vector<int> mergeNums(vector<int>&vi, vector<int>&vj){
    int i=0, j=0, k=0, n1=vi.size(), n2=vj.size();
    int n = n1 + n2;
    vector<int> ans(n);
    while(k < n){
        if(compare(vi, i, vj, j)>0) ans[k++] = vi[i++];
        else ans[k++] = vj[j++];      
    }
    return ans;
}

vector<int> cmpNum(vector<int>&nums, vector<int>&maxNums){
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>maxNums[i]){
            return nums;
        }
        else if(nums[i]<maxNums[i]){
            return maxNums;
        }
    }
    return nums;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size(), n2 = nums2.size();
    if(n1 + n2==k){
        return mergeNums(nums1, nums2);
    }
    vector<int> maxNums(k, 0);
    for(int i = 0; i<=k; i++){
        if(i > n1){break; }
        int j = k - i;
        if(j > n2){continue; }
        // 用单调栈在 nums1 中找到 i 个较大的元素
        vector<int> vi = maxPreNum(nums1, i);
        // 用单调栈在 nums2 中找到 k-i 个较大的元素
        vector<int> vj = maxPreNum(nums2, j);
        // 合并两组较大的元素
        vector<int> tmp = mergeNums(vi, vj);
        // 比较现在是否为最大的组合
        maxNums = cmpNum(tmp, maxNums);
    }
    return maxNums;
}

int main(int argc, char const *argv[])
{
    /*
    [2,5,6,4,4,0]
    [7,3,8,0,6,5,7,6,2]
    15
    ans = 7,3,8   2,5,6,4,4  0,  5,7,6,2   0
    */ 
    vector<int>nums1 = {5,0,2,1,0,1,0,3,9,1,2,8,0,9,8,1,4,7,3};
    vector<int>nums2 = {7,6,7,1,0,1,0,5,6,0,5,0};
    vector<int> ans = maxNumber(nums1, nums2, 31);

    for(auto&n:ans){
        cout<<n<<", ";
    }
    return 0;
}
