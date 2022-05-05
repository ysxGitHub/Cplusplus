/*
给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。

题目保证至少有一个词不在禁用列表中，而且答案唯一。

禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。
*/
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int>cnt;
    unordered_set<string> ban(banned.begin(), banned.end());
    string tmp;
    int maxcnt = 0;
    string ans;
    int n = paragraph.size();
    for(int i=0; i<n; i++){
        char c = paragraph[i];
        if(c>='A'&&c<='Z'){
            tmp += c+32;
        }else if(c>='a'&&c<='z'){
            tmp += c;
        }
        if(c==' '||c==','||c=='!'||c=='?'||c==';'||c=='.'||i==n-1){
            if(!tmp.empty()){
                cnt[tmp]++;
                if(cnt[tmp]>maxcnt&&ban.count(tmp)==0){
                    ans = tmp;
                    maxcnt = cnt[tmp];
                }
                tmp.clear();
            }
        }
    }
    return ans;
}