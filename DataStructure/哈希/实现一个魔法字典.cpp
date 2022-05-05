/*
设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。
    如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，
    使得所形成的新单词存在于你构建的字典中。

实现 MagicDictionary 类：
    MagicDictionary() 初始化对象
    void buildDict(String[] dictionary) 使用字符串数组 dictionary 设定该数据结构，
        dictionary 中的字符串互不相同
    bool search(String searchWord) 给定一个字符串 searchWord ，判定能否只将字符串中
        一个 字母换成另一个字母，使得所形成的新字符串能够与字典中的任一字符串匹配。如果可以，
        返回 true ；否则，返回 false 。
*/
#include<iostream>
#include<unordered_set>
using namespace std;


class MagicDictionary {
    unordered_set<string>dict;
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        dict={dictionary.begin(), dictionary.end()};

    }

    bool search(string searchWord) {
        for(auto&s: dict){
            if(s.size()!=searchWord.size()) continue;
            int cnt = 0;
            for(int i=0; i<searchWord.size(); i++){
                if(searchWord[i]!=s[i]) cnt++;
                if(cnt>1) break;
            }
            if(cnt==1) return true;
        }
        return false;
    }
};