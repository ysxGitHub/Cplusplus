/*
这里有 n 个航班，它们分别从 1 到 n 进行编号。

有一份航班预订表 bookings ，表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi] 
    意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。

请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> diff;

void difference(int left, int right, int inc){
    diff[left] += inc;
    if(right + 1 < diff.size()){
        diff[right + 1] -= inc;
    }
}
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    diff.resize(n);
    for(int i=0; i<bookings.size(); i++){
        difference(bookings[i][0]-1, bookings[i][1]-1, bookings[i][2]);
    }
    for(int i=1; i<n; i++){
        diff[i] += diff[i-1];
    }
    return diff;
}