/*
输入描述:
    多个测试用例，每个测试用例一行。

    每行通过空格隔开，有n个字符，n＜100

输出描述:
    对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开

输入例子1:
    a c bb
    f dddd
    nowcoder

输出例子1:
    a bb c
    dddd f
    nowcoder
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> ss;
    string s;
    while(cin>>s){
        ss.push_back(s);
        if(cin.get()=='\n'){
            sort(ss.begin(), ss.end());
            for(auto&s1: ss){
                cout<<s1<<" ";
            }
            cout<<endl;
            ss.clear();
        }
    }
    return 0;
}
