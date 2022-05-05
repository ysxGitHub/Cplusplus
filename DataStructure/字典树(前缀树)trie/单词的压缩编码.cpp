/*
单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：
words.length == indices.length
助记字符串 s 以 '#' 字符结尾
对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的
    子字符串 恰好与 words[i] 相等
给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int minimumLengthEncoding1(vector<string>& words) {
    unordered_set<string> word;
    int ans = 0;
    for(string& s: words) word.insert(s);
    for(string& s: word){
        for(int i=1; i<s.size(); i++){
            word.erase(s.substr(i));
        }
    }
    for(string s: word){
        ans += s.size()+1;
    }
    return ans;
}


struct Node
{
    int cnt;
    Node** son;
    Node(){
        cnt = 0;
        son = new Node*[26];
        for(int i=0; i<26; i++){
            son[i] = nullptr;
        }
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    Node* insert(string word){
        Node* p = root;
        for(int i=0; i<word.size(); i++){
            int c = word[i] - 'a';
            if(!p->son[i]){
                p->son[i] = new Node();
            }
            p->cnt++;
            p = p->son[i];
        }
        return p;
    }
    int find(string word){
        Node* p = root;
        for(int i=0; i<word.size(); i++){
            int c = word[i] - 'a';
            if(!p->son[i]){
                return 0;
            }
            p = p->son[i];
        }
        return p->cnt;
    }

};

int minimumLengthEncoding(vector<string>& words) {
    unordered_map<Node*, int>nodes;
    Trie te;
    int ans=0;
    for(int i=0; i<words.size(); i++){
        string s = words[i];
        reverse(s.begin(), s.end());
        nodes[te.insert(s)] = i;
    }
    for(auto&node: nodes){
        if(node.first->cnt==0){
            ans += (words[node.second].size() + 1);
        }
    }

    return ans;

}

int main(int argc, char const *argv[])
{
    vector<string> words={"time", "time", "me"};
    cout<<minimumLengthEncoding(words)<<endl;
    cout<<minimumLengthEncoding1(words)<<endl;
    return 0;
}
