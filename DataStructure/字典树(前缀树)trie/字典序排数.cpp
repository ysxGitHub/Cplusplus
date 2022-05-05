/*
给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。

你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> lexicalOrder(int n) {
    vector<int>ans(n);
    int num = 1;
    for(int i=0; i<n; i++){
        ans[i] = num;
        // 尝试在 number 后面附加一个零，即 number×10，
        // 如果 number×10≤n，那么说明 number×10 是下一个字典序整数；
        if(num*10<n){
            num*=10;
        }else{

            // 如果 number mod 10 = 9 或 number+1>n，那么说明末尾的数位已经搜索完成，退回上一位
            while(num%10==9||num+1>n){ //
                num/=10;
            }
            num++;
        }
    }
    return ans;
}