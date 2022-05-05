/*
字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列
 beginWord -> s1 -> s2 -> ... -> sk：

    每一对相邻的单词只差一个字母。
    对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
    sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的
    最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
*/
#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>wordCnt(wordList.begin(), wordList.end());
    if(wordCnt.count(endWord)==0) return 0;
    queue<string>que;
    for(auto& s: wordList){
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=beginWord[i]){
                cnt++;
                if(cnt>1){
                    break;
                }
            }
        }
        if(cnt==1) {
            if(s==endWord) return 2;
            que.push(s);
            wordCnt.erase(s);
        }
    }
    wordCnt.erase(beginWord);
    int level = 2;
    while(!que.empty()){
        int size = que.size();
        for(int i=0; i<size; i++){
            string cur = que.front();
            que.pop();
            for(auto& s: wordList){
                if(wordCnt.count(s)==0) continue;
                int cnt = 0;
                for(int i=0; i<cur.size(); i++){
                    if(cur[i] != s[i]){
                        cnt++;
                        if(cnt>1){
                            break;
                        }
                    }
                }
                if(cnt==1) {
                    if(s==endWord) return level+1;
                    que.push(s);
                    wordCnt.erase(s);
                }
            }
        }
        level++;
    }
    return 0;
}