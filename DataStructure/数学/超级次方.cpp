/*
你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
*/

#include<iostream>
#include<vector>

using namespace std;

int mod = 1337;

int qpow(int a, int b){
    if(b==0) return 1;
    a %= mod;
    if(b%2==1){
        return qpow(a, b - 1)*a%mod;
    }else{
        int tmp = qpow(a, b/2)%mod;
        return tmp*tmp%mod;
    }
}

int superPow(int a, vector<int>& b) {
    if(b.empty()) return 1;
    int last = b.back();
    b.pop_back();
    int tmp1 = qpow(a, last);
    int tmp2 = qpow(superPow(a, b), 10);
    return tmp1*tmp2%mod;
}
