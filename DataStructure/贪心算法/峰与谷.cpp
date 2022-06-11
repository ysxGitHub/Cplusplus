/*
在一个整数数组中，“峰”是大于或等于相邻整数的元素，相应地，“谷”是小于或等于相邻整数的元素。例如，在数组{5, 8, 4, 2, 3, 4, 6}中，{8, 6}是峰， {5, 2}是谷。现在给定一个整数数组，将该数组按峰与谷的交替顺序排序。
*/
#include <iostream>
#include <vector>
using namespace std;

void wiggleSort(vector<int>& nums) {
    for(int i=1; i<nums.size(); ++i){
        // index 为奇数时
        if(i%2==1){
            if(nums[i]>nums[i-1]){ // 大于前一个数进行交换
                swap(nums[i], nums[i-1]);
            }
        }else{ // index 为偶数时
            if(nums[i]<nums[i-1]){ // 小于前一个数进行交换
                swap(nums[i], nums[i-1]);
            }
        }
    }
}
