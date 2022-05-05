/*
给定两个由一些 闭区间 组成的列表，firstList 和 secondList ，
    其中 firstList[i] = [starti, endi] 而 secondList[j] = [startj, endj] 。
    每个区间列表都是成对 不相交 的，并且 已经排序 。

返回这 两个区间列表的交集 。

形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b 。

两个闭区间的 交集 是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 
    的交集为 [2, 3] 。
*/
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, 
                                         vector<vector<int>>& secondList) {

    int m = firstList.size(), n = secondList.size();
    vector<vector<int>>ans;
    int i=0, j=0;
    while(i<m&&j<n){
        // 找左边的最大值，右边的最小值
        int left = max(firstList[i][0], secondList[j][0]);
        int right = min(firstList[i][1], secondList[j][1]);
        if(left<=right) ans.push_back({left, right});
        // 右区间小的移动，因为已经包括这部分了
        if(firstList[i][1]>secondList[j][1]) j++;
        else i++;
    }
    return ans;
}