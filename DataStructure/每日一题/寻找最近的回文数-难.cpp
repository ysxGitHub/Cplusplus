/*
给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。
    如果不止一个，返回较小的那个。
“最近的”定义为两个整数差的绝对值最小。

longth分奇偶
n的前一半影响最大，所有只考虑前一部分+1，-1，+0等

n = "abcde"
找abc__, abc+1__, abc-1__, pow(10,n.longth())+1, pow(10,n.longth()-1)-1 之间的minabs， 最小值，不包括自身

n = "abcd"
找ab__, ab+1__, ab-1__, pow(10,n.longth())+1, pow(10,n.longth()-1)-1 之间的minabs，最小值，不包括自身
*/
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

vector<long> nums;
void getNum(string n, bool isqi){
    string n1 = n;
    string n2 = n;
    reverse(n2.begin(), n2.end());
    if(isqi) n1.pop_back();
    nums.emplace_back(stol(n1+n2));

    long nnum = stol(n) + 1;
    n1 = to_string(nnum);
    n2 = n1;
    reverse(n2.begin(), n2.end());
    if(isqi) n1.pop_back();
    nums.emplace_back(stol(n1+n2));

    nnum = stol(n) - 1;
    n1 = to_string(nnum);
    n2 = n1;
    reverse(n2.begin(), n2.end());
    if(isqi) n1.pop_back();
    nums.emplace_back(stol(n1+n2));

}

string nearestPalindromic(string n) {
    int size = n.size();
    bool isqi = size % 2;
    string nstr = n.substr(0, (size+1)/2);
    // 
    nums.emplace_back(pow(10, size) + 1);
    nums.emplace_back(pow(10, size-1) - 1);

    getNum(nstr, isqi);

    long ans = -1;
    long nnum = stol(n);
    if(nnum<10) return to_string(nnum-1);
    for(auto&ns: nums){
        if(ns==nnum) continue;
        if(ans == -1 || abs(nnum - ns) < abs(ans - nnum) ||( abs(nnum - ns) == abs(ans - nnum) && ans > ns)){
            ans = ns;
        }
    }
    return to_string(ans);
}


int main(int argc, char const *argv[])
{
    cout<<nearestPalindromic("12345");
    return 0;
}
