/*
给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 
    “对于每个 0 <= i < len(arr) / 2，都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，
    返回 true；否则，返回 false。
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

bool canReorderDoubled(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int& a, int& b){
        return abs(a)<abs(b);
    });
    unordered_map<int, int>cnt;
    for(int a: arr) cnt[a]++;
    int ans = arr.size()/2;
    for(int a: arr){
        if(!cnt[a]) continue;
        cnt[a]--;
        if(cnt.count(a*2)&&cnt[a*2]>0){
            ans--;
            cnt[a*2]--;
        }else if(a%2==0&&cnt.count(a/2)&&cnt[a/2]>0){
            ans--;
            cnt[a/2]--;               
        }
    }
    return !ans?1:0;
}