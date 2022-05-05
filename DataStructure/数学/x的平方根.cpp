/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
*/
#include<vector>
#include<iostream>
using namespace std;

int mySqrt(int x) {
    int left = 0, right = x;
    while(left<=right){
        int mid = (right-left)/2 + left;
        // 取右边界
        if((long long)mid*mid<=x){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

    return right;
}

int main(int argc, char const *argv[])
{
    vector<int>nums = {1,2,3,4,5,5,6};
    int left = 0 , right = nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]>=5){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    cout<<left<<endl;

    return 0;
}
