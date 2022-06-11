/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0) return 0;
    set<int>cnt(nums.begin(), nums.end());
    int pre=0, flag=1, maxL=0, ans=0;
    for(const auto&c: cnt){
        if(flag){
            pre = c;
            ans = maxL = 1;
            flag = 0;
            continue;
        }else{
            if(c==pre+1){
                maxL++;
            }else{
                maxL=1;
            }
            pre = c;
        }
        ans = max(maxL, ans);
    }
    return ans;
}