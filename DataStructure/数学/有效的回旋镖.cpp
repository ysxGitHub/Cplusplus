/*
给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，如果这些点构成一个 回旋镖 则返回 true 。

回旋镖 定义为一组三个点，这些点 各不相同 且 不在一条直线上 。
*/
#include <vector>
using namespace std;

// 向量乘积不等于 0
bool isBoomerang(vector<vector<int>>& points) {
    vector<int> v1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
    vector<int> v2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
    return v1[0] * v2[1] - v1[1] * v2[0] != 0;
}

// 两点是否共线
bool isBoomerang(vector<vector<int>>& points) {
    double a = points[0][0]-points[1][0];
    if(a==0){
        if(points[0][0]==points[2][0]) return false;
        else if(points[0][1]==points[1][1]) return false;
        else return true;
    }
    double k = (points[0][1]-points[1][1])/a;
    double m = (points[0][0]*points[1][1]-points[0][1]*points[1][0])/a;
    if(points[2][0]*k+m>=points[2][1]-0.001&&points[2][0]*k+m<=points[2][1]+0.001) return false;
    return true;
}