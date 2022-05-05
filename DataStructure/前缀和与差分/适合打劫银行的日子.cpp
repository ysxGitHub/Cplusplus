/*
你和一群强盗准备打劫银行。给你一个下标从 0 开始的整数数组 security ，其中 security[i] 是第 i 
    天执勤警卫的数量。日子从 0 开始编号。同时给你一个整数 time 。

如果第 i 天满足以下所有条件，我们称它为一个适合打劫银行的日子：

第 i 天前和后都分别至少有 time 天。
第 i 天前连续 time 天警卫数目都是非递增的。
第 i 天后连续 time 天警卫数目都是非递减的。
更正式的，第 i 天是一个合适打劫银行的日子当且仅当：security[i - time] >= security[i - time + 1]
     >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].

请你返回一个数组，包含 所有 适合打劫银行的日子（下标从 0 开始）。返回的日子可以 任意 顺序排列。
*/
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    /*
    使用一个数组存储第 i 天之前的天数不增加，另一个数组存储第 i 天之后的天数不减少。
    */ 
    vector<int>ans;
    int n = security.size();
    vector<int>decrease(n);
    vector<int>increase(n);
    for(int i=1; i<n; i++){
        // 前一天比后一天大，则在前一天的基础上加一
        if(security[i-1] >= security[i]){
            decrease[i] = decrease[i-1] + 1;
        }
        // 后一天比前一天的小，则在后一天的基础上加一
        if(security[n-i] >= security[n-i-1]){
            increase[n-i-1] = increase[n-i] + 1;
        }
    }
    for(int i=time; i<n-time; i++){
        if(increase[i]>=time&&decrease[i]>=time){
            ans.emplace_back(i);
        }   
    }

    return ans;

}

vector<int> goodDaysToRobBank1(vector<int>& security, int time) {
    vector<int>ans;
    int n = security.size();
    vector<int> trend(n, 0);
    for(int i=1; i<n; i++){
        if(security[i] > security[i-1]){
            trend[i] = 1;
        }
        else if(security[i] < security[i-1]){
            trend[i] = -1;
        }
    }
    vector<int> increase(n, 0); //表示递增累计个数
    vector<int> decrease(n, 0); //表示递减累计个数
    for(int i=1; i<n; i++){
        increase[i] = increase[i-1] + (trend[i] == 1 ? 1 : 0);
        decrease[i] = decrease[i-1] + (trend[i] == -1 ? 1 : 0);
    }

    for(int i = time; i<n - time; i++){
        // i-time, i 不存在递增 ;  i  i+time 不存在递减
        if(increase[i]-increase[i-time]==0&&decrease[i+time]-decrease[i]==0) ans.emplace_back(i);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> security = {2,0,5,3,4};
                          //0,1,0,1,0,
                          //0,1,1,1,0,
    int time = 1;
    vector<int> ans = goodDaysToRobBank1(security, time);
    for(auto n: ans){
        cout<<n<<",";
    }
    return 0;
}
