/*
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；
    否则，返回 false 。
如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。
*/

#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n<=0){return false;}
    else if(n==1){return true;}
    else if(n%2!=0){return false;}
    else{
        for(int i=0; i<31; i++){
            if((2<<i)==n){
                return true;
            }
        }
        return false;
    }
}

bool isPowerOfTwo1(int n) {
    if(n<=0){return false;}
    /*
    8: 1000
    7: 0111
    16:10000
    15:01111 
    */ 

    // 位运算符优先级很低   
    return (n&(n-1))==0;
}

int main(int argc, char const *argv[])
{
    cout<<isPowerOfTwo1(0);
    // cout<<(2<<1)<<endl;
    return 0;
}
