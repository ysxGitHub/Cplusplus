/*
输入描述:
    输入有两行，第一行n

    第二行是n个字符串，字符串之间用空格隔开

输出描述:
    输出一行排序后的字符串，空格隔开，无结尾空格

输入例子1:
    5
    c d a bb e

输出例子1:
    a bb c d e
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n=0;
    vector<string> cnt;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        cnt.push_back(s);
    }
    sort(cnt.begin(), cnt.end());
    for(auto&ss: cnt){
        cout<<ss<<" ";
    }
    return 0;
}