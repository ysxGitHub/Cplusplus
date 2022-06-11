/*
下一个数。给定一个正整数，找出与其二进制表达式中1的个数相同且大小最接近的那两个数（一个略大，一个略小）。
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> findClosedNumbers(int num) {
    if(num==2147483647) return {-1, -1};
    int n=__builtin_popcount(num);
    int a,b;
    for(a=num+1;a>0;++a){
        if(__builtin_popcount(a)==n) break;
    }
    for(b=num-1;b>0;--b){
        if(__builtin_popcount(b)==n) break;
    }
    return {a>0?a:-1,b>0?b:-1};
}

vector<int> findClosedNumbers2(int num) {
    int before = -1, next = -1;
    for(int i=1, cnt=num&1;i<32;i++){
        int ret = num&(1<<i);
        if(ret != 0){
            if(before ==-1 && (num&(1<<(i-1))) == 0){
                before=num|(1<<(i-1)); before=before&(~(1<<i));
                for(int j=i-2,k=cnt;j>=0;j--,k--) before= k>0?before|(1<<j):before&(~(1<<j));
            }
            cnt++;
        }else if(ret==0 && next ==-1 && i!=31 && (num&(1<<(i-1))) != 0){
            next = num|(1<<i); next = next&(~(1<<(i-1)));
            for(int j=i-2, k=cnt-1;j>=0;j--) next=j>=k?next&(~(1<<j)):next|(1<<j);
        }else if(before !=-1 && next != -1) break;
    }
    return {next, before};
}
