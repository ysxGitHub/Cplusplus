/*
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int&x, int&y){
        long sx = 10, sy = 10;
        while (sx <= x) {
            sx *= 10;
        }
        while (sy <= y) {
            sy *= 10;
        }
        return sy * x + y > sx * y + x;});

    if (nums[0] == 0) return "0";
    string ans;
    for(auto&num:nums){
        ans+=to_string(num);
    }
    return ans;
}