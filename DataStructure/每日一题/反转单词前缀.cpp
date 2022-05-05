/*
给你一个下标从 0 开始的字符串 word 和一个字符 ch 。
找出 ch 第一次出现的下标 i ，反转 word 中从下标 0 开始、直到下标 i 结束（含下标 i ）的那段字符。
    如果 word 中不存在字符 ch ，则无需进行任何操作。

例如，如果 word = "abcdefd" 且 ch = "d" ，那么你应该 反转 从下标 0 开始、
    直到下标 3 结束（含下标 3 ）。结果字符串将会是 "dcbaefd" 。

*/
#include<iostream>
using namespace std;

string reversePrefix(string word, char ch) {
    string ans = word;
    int id = word.find(ch);
    if(id > 300){
        return word;
    }else{
        int j = 0;
        for(int i = id; i>=0; i--){
            ans[j] = word[i];
            j++;
        }

    }
    return ans;
}


int main(int argc, char const *argv[])
{
    string word = "abcdefd";
    char ch = 'd';
    cout<<reversePrefix(word, ch);
    return 0;
}


