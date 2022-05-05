/*
给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 表示一个坐标轴平行的矩形。
    这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。

如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。

*/

#include<bits/stdc++.h>
using namespace std;

struct pair_hash {
    inline int operator()(const pair<int,int> & p) const {
        return p.first * 100 + p.second;
    }
};

bool isRectangleCover(vector<vector<int>>& rectangles) {

    int minX1 = INT_MAX, minY1 = INT_MAX;
    int maxX2 = INT_MIN, maxY2 = INT_MIN;

    unordered_set<pair<int, int>, pair_hash>points;
    long long trueArea = 0;
    for(auto rect: rectangles){
        int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];

        // 寻找叠加后的矩形各个顶点
        minX1 = min(minX1, x1);
        minY1 = min(minY1, y1);
        maxX2 = max(maxX2, x2);
        maxY2 = max(maxY2, y2);

        // 计算真实的各矩形面积之和
        trueArea += (long long)(x2-x1)*(y2-y1);

        auto point1 = make_pair(x1, y1);
        auto point2 = make_pair(x1, y2);
        auto point3 = make_pair(x2, y1);
        auto point4 = make_pair(x2, y2);

        // 保证奇数个数的顶点留下 ，如 1，3个相同的顶点
        // 最终的完美矩形一定是有 4个不同的 顶点组成
        for(auto point: {point1, point2, point3, point4}){
            if(points.count(point)) points.erase(point);
            else points.insert(point);
        }
    }
    long long area = (long long)(maxX2 - minX1) * (maxY2 - minY1);
    // 判断 完美矩形的面积 是否与 真实的各矩形面积之和 相等
    if(area!=trueArea) return false;
    // 是否只剩4个顶点
    if(points.size()!=4) return false;
    // 完美矩形的顶点是否在其中？
    if(!points.count(make_pair(minX1, minY1))) return false;
    if(!points.count(make_pair(minX1, maxY2))) return false;
    if(!points.count(make_pair(maxX2, minY1))) return false;
    if(!points.count(make_pair(maxX2, maxY2))) return false;

    return true;
} 
