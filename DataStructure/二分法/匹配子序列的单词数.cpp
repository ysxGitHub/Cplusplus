/*
给定字符串 s 和字符串数组 words, 返回  words[i] 中是s的子序列的单词个数 。

字符串的 子序列 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。

例如， “ace” 是 “abcde” 的子序列。
*/
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 二分法搜索
int numMatchingSubseq(const string& s, const vector<string>& words) {
    int n = s.size();
    vector<vector<int>>char2Idx(26);
    for(int i=0; i<n; ++i){
        char2Idx[s[i]-'a'].push_back(i);
    }
    int ans = 0;
    for(auto&word: words){
        int j=0, flag=0;
        for(auto&ch: word){
            int c = ch-'a';
            if(char2Idx[c].size()==0) {flag=1; break;}
            int pos = lower_bound(char2Idx[c].begin(), char2Idx[c].end(), j)-char2Idx[c].begin();
            if(pos==char2Idx[c].size()) {flag=1; break;}
            j = char2Idx[c][pos] + 1;
        }
        if(!flag) ++ans;
    }
    return ans;
}


/*
因为 S 很长，所以寻找一种只需遍历一次 S 的方法，避免暴力解法的多次遍历。

将所有单词根据首字母不同放入不同的桶中。例如当 words = ['dog', 'cat', 'cop']，根据首字母不同可以分为 'c' : ('cat', 'cop'), 'd' : ('dog',)。换句话说，每个桶中的单词就是该单词正在等待匹配的下一个字母。在遍历 S 的同时，将匹配到单词根据下一个需要匹配的字母移动到不同的桶中。

例如，有字符串 S = 'dcaog'：

初始化 heads = 'c' : ('cat', 'cop'), 'd' : ('dog',)；
遍历 S[0] = 'd' 后，heads = 'c' : ('cat', 'cop'), 'o' : ('og',)；
遍历 S[1] = 'c' 后，heads = 'a' : ('at',), 'o' : ('og', 'op')；
遍历 S[2] = 'a' 后，heads = 'o' : ('og', 'op'), 't': ('t',) ;
遍历 S[3] = 'o' 后，heads = 'g' : ('g',), 'p': ('p',), 't': ('t',)；
遍历 S[0] = 'g' 后，heads = 'p': ('p',), 't': ('t',)。

算法:
使用长度为 26 的数组 heads 做桶，每个字母对应一个桶。访问 S 中的每个字母时，将该字母对应桶中的所有单词，根据下一个等待匹配字母放入到不同的桶中。如果已经匹配到单词的最后一个字母，那么子序列单词数加 1。
*/
int numMatchingSubseq(string S, vector<string>& words) {
    vector<queue<pair<int, int>>> buckets(26);
    for(int i = 0; i < words.size(); i++){
        buckets[words[i][0]-'a'].push({i, 0});
    }
    int res = 0;
    for(auto&c: S){
        // 拿出 c-'a' 的数据
        queue<pair<int, int>> & q = buckets[c-'a'];
        for(int i = q.size(); i > 0; i--){
            // 得到对应的单词位置，与该单词中的位置
            auto [wordIndex, posIndex] = q.front();
            q.pop();
            posIndex++; // 该单词中的位置+1
            // 判断是否到达该单词的结尾
            if(posIndex == words[wordIndex].length()){
                res++;
            }
            else{
                buckets[words[wordIndex][posIndex] - 'a'].push({wordIndex, posIndex});
            }
        }
    }
    return res;
}
