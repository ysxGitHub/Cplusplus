/*
给你两个整数 left 和 right ，表示区间 [left, right] ，
    返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。

*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int mask = 1 << 30; // 最高位开始
    int anw = 0;
    while(mask > 0 && (left&mask) == (right&mask)) { //寻找相同前缀
        anw |= left&mask;
        mask >>= 1;
    }
    return anw;   
}


int rangeBitwiseAnd1(int left, int right) {
    int shift = 0;   
    // 找到公共前缀
    while (left < right){
        left = left >> 1;
        right = right >> 1;
        shift += 1;
    }
    return left << shift;
}

int main(int argc, char const *argv[])
{
    // cout<<(1&2)<<endl;
    // cout<<(2&3&4&5)<<endl;
    // cout<<(4&7)<<endl;
    // cout<<(11&12)<<endl;
    cout<<rangeBitwiseAnd(1,2147483647)<<endl;
    cout<<floor(log2(8))<<endl;
    // int a = 1;
    // cout<<~a<<endl;
    cout<<rangeBitwiseAnd1(2,5)<<endl;
    return 0;
}
