/*
给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。

返回满足此条件的 任一数组 作为答案。
*/

vector<int> sortArrayByParity(vector<int>& nums) {
    int n=nums.size();
    int j=0;
    for(int i=0; i<n; i++){
        if(nums[i]%2==0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
    return nums;
}