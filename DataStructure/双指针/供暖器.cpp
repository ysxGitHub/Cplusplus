/*
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int findlower(vector<int>& heaters, int target){
//     int left = 0, right = heaters.size()-1;
//     while(left<=right){
//         int mid = left + (right-left)/2;
//         if(heaters[mid]<target){
//             left = mid+1;
//         }else if(heaters[mid]>target){
//             right = mid-1;
//         }else{
//             return mid;
//         }
//     }
//     return right;
// }
// int findup(vector<int>& heaters, int target){
//     int left = 0, right = heaters.size()-1;
//     while(left<=right){
//         int mid = left + (right-left)/2;
//         if(heaters[mid]>target){
//             right = mid-1;
//         }else if(heaters[mid]<target){
//             left = mid+1;
//         }else{
//             return mid;
//         }
//     }
//     return left;
// }
// 1.二分法
int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    for (int i = 0; i < houses.size(); i++) {
        int up_pos = upper_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
        int cur_min = 1e9;
        if (up_pos != heaters.size())
            cur_min = min(cur_min, heaters[up_pos] - houses[i]);
        if (up_pos - 1 >= 0)
            cur_min = min(cur_min, houses[i] - heaters[up_pos - 1]);
        ans = max(ans, cur_min);
    }
    return ans;
}

// 2.双指针
int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    for (int i = 0, j = 0; i < houses.size(); i++) {
        int curDistance = abs(houses[i] - heaters[j]);
        while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
            j++;
            curDistance = min(curDistance, abs(houses[i] - heaters[j]));
        }
        ans = max(ans, curDistance);
    }
    return ans;
}
