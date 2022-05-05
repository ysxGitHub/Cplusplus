/*

*/
#include<vector>
#include<iostream>
using namespace std;

vector<int>c;

int lowbit(int x){return x&(-x);}


void update(int x, int y, int n){
    for(int i=x;i<=n;i+=lowbit(i))   //x为更新的位置,y为更新后的数,n为数组大小
        c[i] += y;
}


int getsum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans += c[i];
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
