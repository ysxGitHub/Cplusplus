/*
给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

请你找出符合题意的 最短 子数组，并输出它的长度。
*/
#include <vector>
using namespace std;



/*
[2,6,4,8,10,9,15]
          -->end
 begin<--
*/
int findUnsortedSubarray(vector<int>& nums) {
    //初始化
    int len = nums.size();
    int min = nums[len-1];
    int max = nums[0];
    int begin = 0, end = -1;
    //遍历
    for(int i = 0; i < len; i++){
        if(nums[i] < max){      //从左到右维持最大值，寻找右边界end
            end = i;
        }else{
            max = nums[i];
        }
        if(nums[len-i-1] > min){    //从右到左维持最小值，寻找左边界begin
            begin = len-i-1;
        }else{
            min = nums[len-i-1];
        }
    }
    return end-begin+1;
}