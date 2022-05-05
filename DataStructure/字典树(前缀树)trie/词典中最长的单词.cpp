/*
给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 
    词典中其他单词逐步添加一个字母组成。
若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。
*/
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>

using namespace std;

string longestWord(vector<string>& words) {
    string ans;
    sort(words.begin(), words.end(), [](const string a, const string b){
        return a.size()==b.size()? a>b : a.size()<b.size();
    });
    unordered_set<string> cnt;
    cnt.emplace("");
    for(string& s: words){
        if(cnt.count(s.substr(0,s.size()-1))){
            cnt.emplace(s);
            ans = s;
        }

    }
    return ans;
}

int main(int argc, char const *argv[])
{

    return 0;
}
