/*
1 1 2 3 5 8 13 21 34
*/
#include<iostream>
using namespace std;

int fib_rec(int N){
    if(N<0){
        return 0;
    }
    if(N==1||N==2){
        return 1;
    }else{
        return fib_rec(N-1)+fib_rec(N-2);
    }  
}

int fib(int N){

    if(N<0){
        return 0;
    }
    if(N==1||N==2){
        return 1;
    }else{
        int result = 1;
        int preResult = 1; // n - 2项
        int currentResult = 1; // n - 1项
        // 注意这里可以等于0
        for(int i=3; i<=N; i++){
            result = preResult+currentResult;
            preResult = currentResult;
            currentResult = result;
        }
        return result;
    }  

}


int main(int argc, char const *argv[])
{
    cout<<fib_rec(8)<<endl;
    cout<<fib(8)<<endl;

    return 0;
}


