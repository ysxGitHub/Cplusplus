/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
*/
#include<iostream>
#include<vector>
using namespace std;



void moveZeroes1(vector<int>& nums) {
    int left = 0, right = 0;
    while(right < nums.size()){
        if(nums[right]!=0){
            nums[left++] = nums[right];
        }
        right++;
    }
    for(int i = left; i<nums.size(); i++){
        nums[i] = 0;
    }
}


void moveZeroes(vector<int>& nums) {
    int i=0;
    int j=0;
    for(i; i<nums.size(); i++){
        if(nums[i]!=0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}



int main(int argc, char const *argv[])
{
    vector<int>nums={0,1,0,2,3};
    moveZeroes2(nums);
   
    for(auto& n: nums){
        cout<<n<<" ";
    }
    return 0;
}
