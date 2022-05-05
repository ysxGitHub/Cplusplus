/*
现有一份 n + m 次投掷单个 六面 骰子的观测数据，骰子的每个面从 1 到 6 编号。观测数据中缺失了 n 份，
    你手上只拿到剩余 m 次投掷的数据。幸好你有之前计算过的这 n + m 次投掷数据的 平均值 。

给你一个长度为 m 的整数数组 rolls ，其中 rolls[i] 是第 i 次观测的值。同时给你两个整数 mean 和 n 。

返回一个长度为 n 的数组，包含所有缺失的观测数据，且满足这 n + m 次投掷的 平均值 是 mean 。
    如果存在多组符合要求的答案，只需要返回其中任意一组即可。如果不存在答案，返回一个空数组。

k 个数字的 平均值 为这些数字求和后再除以 k 。

注意 mean 是一个整数，所以 n + m 次投掷的总和需要被 n + m 整除。
*/

#include<vector>
#include<iostream>
using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int sum = mean * (n + m);
    int missingSum = sum;
    for (int & roll : rolls) {
        missingSum -= roll;
    }
    if (missingSum < n || missingSum > 6 * n) {
        return {};
    }

    // 在缺失的 n 个观测数据中，有 remainder 个观测数据是 quotient+1，
    // 其余观测数据都是 quotient。

    int quotient = missingSum / n, remainder = missingSum % n;
    vector<int> missing(n);
    for (int i = 0; i < n; i++) {
        missing[i] = quotient + (i < remainder ? 1 : 0);
    }
    return missing;
}


vector<int> missingRolls1(vector<int>& rolls, int mean, int n) {
    vector<int>nums = {6,5,4,3,2,1};
    vector<int>ans;
    int m = rolls.size();
    int remaining = (m + n)*mean;
    for(auto r : rolls) remaining -= r;
    if (remaining < n || remaining > 6 * n) return {};
    for(int i=1; i<=n; i++){
        for(auto num: nums){
            if(remaining-num>=n-i){
                remaining-=num;
                ans.emplace_back(num);
                break;
            }
        }
    }
    if(remaining!=0||ans.size()<n) ans = {};
    return ans;
}