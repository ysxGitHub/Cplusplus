/*
给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，
    计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。
*/

// 与构造不同二叉树类似
#include<vector>
#include<iostream>

using namespace std;

bool isOpt(char c){
    if(c=='+'||c=='-'||c=='*'){
        return true;
    }else{
        return false;
    }
}
int optNum(int a, int b, char o){
    if(o=='+'){
        return a+b;
    }else if(o=='-'){
        return a-b;
    }else if(o=='*'){
        return a*b;
    }else{
        return -1;
    }
}

vector<int> diffWaysToCompute(string expression) {
    int n = expression.size();
    vector<int>res;
    for(int i=0; i<n; i++){
        char c = expression[i];
        if(isOpt(c)){
            vector<int> num1 = diffWaysToCompute(expression.substr(0, i));
            vector<int> num2 = diffWaysToCompute(expression.substr(i+1));
            for(auto n1: num1){
                for(auto n2:num2){
                    res.emplace_back(optNum(n1, n2, c));
                }
            }
        }
    }
    if(res.empty()) res.emplace_back(stoi(expression));
    return res;
}