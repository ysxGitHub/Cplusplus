/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，
    第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。
*/
#include<vector>
#include<iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0, j=n-1;
    int size = 0;
    while(i<j){
        size = max(size, (j-i)*min(height[i], height[j]));
        // 这里必须用if else 不能用if if
        if(height[i]>height[j]){
            j--;
        }else{
            i++;
        }
    }
    return size;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
