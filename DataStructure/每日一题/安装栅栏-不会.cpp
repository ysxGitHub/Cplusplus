/*
在一个二维的花园中，有一些用 (x, y) 坐标表示的树。由于安装费用十分昂贵，
    你的任务是先用最短的绳子围起所有的树。
    只有当所有的树都被绳子包围时，花园才能围好栅栏。你需要找到正好位于栅栏边界上的树的坐标。
*/
#include <iostream>
#include <vector>
using namespace std;

/*二维凸包（Andrew 算法）*/

int cross(const vector<int> & p, const vector<int> & q, const vector<int> & r) {
    return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
}

vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    int n = trees.size();
    if (n < 4) {
        return trees;
    }
    /* 按照 x 大小进行排序，如果 x 相同，则按照 y 的大小进行排序 */
    sort(trees.begin(), trees.end(), [](const vector<int> & a, const vector<int> & b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
    vector<int> hull;
    vector<bool> used(n, false);
    /* hull[0] 需要入栈两次，不进行标记 */
    hull.emplace_back(0);
    /* 求出凸包的下半部分 */
    for (int i = 1; i < n; i++) {
        while (hull.size() > 1 && cross(trees[hull[hull.size() - 2]], trees[hull.back()], trees[i]) < 0) {
            used[hull.back()] = false;
            hull.pop_back();
        }
        used[i] = true;
        hull.emplace_back(i);
    }
    int m = hull.size();
    /* 求出凸包的上半部分 */
    for (int i = n - 2; i >= 0; i--) {
        if (!used[i]) {
            while (hull.size() > m && cross(trees[hull[hull.size() - 2]], trees[hull.back()], trees[i]) < 0) {
                used[hull.back()] = false;
                hull.pop_back();
            }
            used[i] = true;
            hull.emplace_back(i);
        }
    }
    /* hull[0] 同时参与凸包的上半部分检测，因此需去掉重复的 hull[0] */
    hull.pop_back();
    vector<vector<int>> res;
    for(auto & v : hull) {
        res.emplace_back(trees[v]);
    }
    return res;
}