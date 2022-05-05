/*
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
*/
#include<iostream>
#include<vector>

using namespace std;

int singleNonDuplicate1(vector<int>& nums) {
    int result = 0;
    for(auto& n: nums){
        result^=n;
    }
    return result;
}

/*

通过观察，我们可以发现：如果是成对的话，下标的开始-结束应该为偶数-奇数，而如果出现了奇数-偶数的话,
    代表前面出现了单独的数，改变了“奇偶性”,否则，单独的数在该数的后面。
故我们可以先判断中间坐标 mid 的奇偶性，再根据它的奇偶性选择跟前一个数还是后一个数比较。

*/
int singleNonDuplicate1(vector<int>& nums) {
    int left = 0;
    int right = nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        // 如果是成对的话，下标的开始-结束应该为偶数-奇数，
        if(mid%2==0){
            if(mid+1<=nums.size()-1&&[mid]==nums[mid+1]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }else{
            if(mid-1>=0&&nums[mid]==nums[mid-1]){
                left = mid+1;
            }else{
                right = mid-1;
            } 
        }
    }
    return nums[left];
}


int main(int argc, char const *argv[])
{
    
    return 0;
}


