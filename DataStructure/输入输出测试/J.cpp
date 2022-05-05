/*
多个测试用例，每个测试用例一行。
    每行通过,隔开，有n个字符，n＜100

输出描述:
    对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格

输入例子1:
    a,c,bb
    f,dddd
    nowcoder

输出例子1:
    a,bb,c
    dddd,f
    nowcoder
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> sss;
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        while(getline(ss, s, ',')){
            sss.push_back(s);
        }
        sort(sss.begin(), sss.end());
        int n = sss.size();
        for(int i=0; i<n; i++){
            if(i<n-1){
                cout<<sss[i]<<",";
            }else{
                cout<<sss[i]<<endl;
            }
        }
        sss.clear();
    }
    return 0;
}