/*
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。
    这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。

void insert(String word) 向前缀树中插入字符串 word 。

boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；
    否则，返回 false 。

boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，
    返回 true ；否则，返回 false 。

*/
#include<iostream>
#include<string>

using namespace std;
#define N 26

struct TrieNode
{
    int cnt;
    TrieNode** son;
    TrieNode(){
        cnt = 0;
        son = new TrieNode*[N];
        for(int i=0; i<N; i++){
            son[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string word) {
        TrieNode * p = root;
        for(int i=0; i<word.length(); i++){
            int c = word[i] - 'a';
            if(!p->son[c]){
                p->son[c] = new TrieNode;
            }
            p = p->son[c];
        }
        ++p->cnt;
    }

    TrieNode * findP(string word){
        TrieNode * p = root;
        for(int i=0; i<word.length(); i++){
            int c = word[i] - 'a';
            if(!p->son[c]){
                return nullptr;
            }
            p = p->son[c];
        }
        return p;
    }

    bool search(string word) {
        TrieNode * p = findP(word);
        if(p==nullptr||p->cnt==0){return 0;}
        return 1;
    }

    bool startsWith(string prefix) {
        return findP(prefix)!=nullptr;
    }
};


int main(int argc, char const *argv[])
{
    Trie tree;
    tree.insert("apple");
    cout<<tree.search("apple")<<endl;
    cout<<tree.search("app")<<endl;
    // cout<<tree.prefixQuery("aab")<<endl;
    cout<<tree.startsWith("app")<<endl;
    return 0;
}
