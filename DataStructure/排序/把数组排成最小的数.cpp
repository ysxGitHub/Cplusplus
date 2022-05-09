/*
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
*/
#include <queue>
#include <iostream>
using namespace std;

struct cmp{
    bool operator()(string&a, string&b){
        return a+b>b+a?1:0;
    }
};
string minNumber(vector<int>& nums) {
    priority_queue<string, vector<string>, cmp> pq;
    for(auto&num: nums){
        pq.push(to_string(num));
    }
    string ans;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    return ans;
}