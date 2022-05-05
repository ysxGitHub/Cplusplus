/*
给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。
    分数可以以 任意 顺序返回。
eg: 
    输入：n = 4
    输出：["1/2","1/3","1/4","2/3","3/4"]
*/
#include<vector>
#include<iostream>

using namespace std;

//暴力解法  algorithm::__gcd-最大公约数
vector<string> simplifiedFractions(int n) {
    if(n==1){
        return {};
    }
    vector<string>ans;
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            int flag = 0;
            for(int k=2; k<i; k++){
                if((i%k==0&&j%k==0)){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans.push_back(to_string(j)+"/"+to_string(i));
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    simplifiedFractions(6);
    return 0;
}
