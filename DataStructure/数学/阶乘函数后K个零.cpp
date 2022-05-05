/*
f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。

例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。
*/

#include<iostream>  
using namespace std;

#define ll long long


int trailingZeroes(ll n) {
    int cnt;
    for(ll d=n; d/5>0; d/=5){
        cnt += d/5;
    }
    return cnt;
}

int preimageSizeFZF(int k) {
    ll left = k * 4ll, right = k * 5ll + 1ll;

    while(left <= right){
        ll mid = left + (right - left)/2;
        if(trailingZeroes(mid)>k){
            right = mid - 1;
        }
        else if(trailingZeroes(mid)<k){
            left = mid + 1;
        }
        else{
            return 5;
        }
    }

    return 0;
}


int main(int argc, char const *argv[])
{
    cout<<preimageSizeFZF(1000000000)<<endl;
    // cout<<10%10<<endl;
    return 0;
}
