/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
*/
#include<vector>
#include<iostream>

using namespace std;

vector<string>ans;
int cntl=0, cntr=0;

void backtrace(int n, int start, string path){
    if(n*2==start){
        ans.emplace_back(path);
        return;
    }
    for(char c: {'(', ')'}){
        if((cntl==n&&c=='(')||(cntr==n&&c==')')||cntr>cntl) continue;
        if(c=='(') cntl++;
        if(c==')') cntr++;
        path += c;
        backtrace(n, start+1, path);
        path.pop_back();
        if(c=='(') cntl--;
        if(c==')') cntr--;
    }
}

vector<string> generateParenthesis(int n) {
    string path;
    backtrace(n, 0, path);
    return ans;
}