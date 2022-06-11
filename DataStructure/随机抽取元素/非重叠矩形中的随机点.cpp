/*
给定一个由非重叠的轴对齐矩形的数组 rects ，其中 rects[i] = [ai, bi, xi, yi] 表示 (ai, bi) 是第 i 个矩形的左下角点，(xi, yi) 是第 i 个矩形的右上角角点。设计一个算法来随机挑选一个被某一矩形覆盖的整数点。矩形周长上的点也算做是被矩形覆盖。所有满足要求的点必须等概率被返回。

在一个给定的矩形覆盖的空间内任何整数点都有可能被返回。

请注意 ，整数点是具有整数坐标的点。

实现 Solution 类:

Solution(int[][] rects) 用给定的矩形数组 rects 初始化对象。
int[] pick() 返回一个随机的整数点 [u, v] 在给定的矩形所覆盖的空间内。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n;
    vector<int>sum;
    vector<vector<int>>_rects;
    Solution(vector<vector<int>>& rects):_rects(rects){
        _rects = rects;
        n = rects.size();
        sum.push_back(0);
        // 记录面积前缀和
        for(const auto&rect: rects){
            int m = rect[2]-rect[0]+1;
            int n = rect[3]-rect[1]+1;
            sum.push_back(sum.back()+m*n);
        }
    }

    vector<int> pick() {
        // 二分法查找落在哪个正方形区域
        int k = rand()%sum.back()+1;
        int left = 0, right = n;
        while(left<=right){
            int mid = (left+right)/2;
            if(sum[mid]>=k) right = mid-1;
            else left = mid+1;
        }
        vector<int>res = _rects[left-1];
        int x = res[2]-res[0]+1;
        int y = res[3]-res[1]+1;
        // 计算落在该正方形区域的位置
        return {rand()%x+res[0], rand()%y+res[1]};
    }
};