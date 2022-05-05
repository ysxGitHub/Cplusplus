/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
*/

#include <iostream>
#include <cstring>
using namespace std;


bool isPalindrome(int x) {
    char a[100];
    sprintf(a,"%d",x);
    int lens = strlen(a);
    int i = 0;
    int j = lens-1;
    while(i<lens){
        if(a[i]!=a[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    cout<<isPalindrome(1122211);
    return 0;
}
