/*
给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。

但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，才能得到最大的结果，
    并且返回相应的字符串格式的表达式。你的表达式不应该含有冗余的括号。
*/
#include<iostream>
#include<vector>
using namespace std;

string optimalDivision(vector<int>& nums) {
    string ans;
    if(nums.size()==1){
        ans += to_string(nums[0]);
        return ans;
    }
    if(nums.size()==2){
        ans = to_string(nums[0]) + "/" + to_string(nums[1]);
        return ans;
    }
    ans = to_string(nums[0]) + "/(";
    for(int i=1; i<nums.size(); i++){
        ans += to_string(nums[i]) + "/";
    }
    ans.pop_back();
    ans += ")";
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
