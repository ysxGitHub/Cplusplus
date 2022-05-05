/*
森林中有未知数量的兔子。提问其中若干只兔子 "还有多少只兔子与你（指被提问的兔子）颜色相同?" ，将答案收集到一个整数数组 answers 中，其中 answers[i] 是第 i 只兔子的回答。

给你数组 answers ，返回森林中兔子的最少数量。

向上取整公式：向上取整a / b => 向下取整 (a + b - 1) / b

一般地，如果有 x 只兔子都回答 y，则至少有 x / y+1 种不同的颜色，且每种颜色有 y+1 只兔子，因此兔子数至少为 (x / y+1) * (y+1)

*/
#include<vector>
#include<unordered_map>

using namespace std;


int numRabbits(vector<int>& answers) {
    unordered_map<int, int> cnt;
    int res = 0;
    for(auto& num: answers){
        cnt[num]++;
    }
    for(auto&[y, x]: cnt){
        res += (x+y)/(y+1)*(y+1);
    }
    return res;
}