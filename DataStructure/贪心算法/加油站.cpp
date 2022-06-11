/*
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
    你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。
    如果存在解，则 保证 它是 唯一 的。
*/

#include<vector>
#include<iostream>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int sum = 0, maxsum = INT32_MIN;
    // 相当于图像中的坐标点和最低点
    int start = 0;
    for(int i=0; i<n; i++){
        sum += gas[i] - cost[i];
        if(sum>maxsum){
            // 经过第 i 个站点后，使 sum 到达新低
            // 所以站点 i + 1 就是最低点（起点）
            start = i + 1;
            maxsum = sum;
        }
    }
    // 肯定不行
    if(sum<0) return -1;
    //
    return start==n ? 0 : start;
}

int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int sum = 0, curSum = 0;
    int start = 0;
    for(int i=0; i<n; i++){
        curSum += gas[i] - cost[i];
        sum += gas[i] - cost[i];
        if(curSum<0){
            // 无法从 start 到 i, 只能从 i+1 开始
            start = i + 1;
            curSum = 0;
        }
    }
    if(sum<0) return -1;
    return start;
}

int main(int argc, char const *argv[])
{

    return 0;
}
