/*
丑数 就是只包含质因数 2、3 和 5 的正整数。

给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
*/


bool isUgly(int n) {
    if(n<=0) return 0;
    if(n==1) return 1;
    while(n!=1){
        if(n%2==0){
            n/=2;
        }else if(n%3==0){
            n/=3;
        }else if(n%5==0){
            n/=5;
        }else{
            return false;
        }
    }
    return true;
}