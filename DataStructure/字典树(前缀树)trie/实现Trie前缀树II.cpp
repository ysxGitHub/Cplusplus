/*
前缀树（trie ，发音为 "try"）是一个树状的数据结构，用于高效地存储和检索一系列字符串的前缀。
    前缀树有许多应用，如自动补全和拼写检查。

实现前缀树 Trie 类：

Trie() 初始化前缀树对象。

void insert(String word) 将字符串 word 插入前缀树中。

int countWordsEqualTo(String word) 返回前缀树中字符串 word 的实例个数。

int countWordsStartingWith(String prefix) 返回前缀树中以 prefix 为前缀的字符串个数。

void erase(String word) 从前缀树中移除字符串 word 。
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;
#define N 26

struct TrieNode
{
    char ch;
    int cnt;
    TrieNode** son;
    TrieNode(char c){
        ch = c;
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
        root = new TrieNode(' ');
    }

    void insert(string word) {
        TrieNode * p = root;
        for(int i=0; i<word.length(); i++){
            int c = word[i] - 'a';
            if(!p->son[c]){
                p->son[c] = new TrieNode(word[i]);
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

    int countWordsEqualTo(string word) {
        TrieNode * p = findP(word);
        if(p==nullptr){return 0;}
        return p->cnt;
    }

    void traverse(TrieNode * p, string& prefix, string& path, vector<string>&res, int& ans){
        if(p->cnt!=0){
            ans+=p->cnt;
            res.emplace_back(prefix+path);
            // 注意这里不能返回，可能后面还有word
            // return;
        }
        for(int i=0; i<N; i++){
            if(p->son[i]){
                path += p->son[i]->ch;
                traverse(p->son[i], prefix, path, res, ans);
                path.pop_back();
            }
        }
    }

    int countWordsStartingWith(string prefix) {
        TrieNode * p = findP(prefix);
        if(p==nullptr){return 0;}
        string path;
        vector<string>res;
        int ans=0;
        traverse(p, prefix, path, res, ans);
        return ans;
    }

    void erase(string word) {
        TrieNode * p = findP(word);
        p->cnt--;
    }
};


int main(int argc, char const *argv[])
{
    /*
    ["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith",
    "erase", "countWordsEqualTo", "countWordsStartingWith", "erase",
    "countWordsStartingWith"]
    [[], ["apple"], ["apple"], ["apple"], ["app"],
    ["apple"], ["apple"], ["app"], ["apple"], ["app"]]

    */
    Trie tree;
    tree.insert("apple");
    tree.insert("apple");
    cout<<tree.countWordsEqualTo("apple")<<endl;
    cout<<tree.countWordsStartingWith("app")<<endl;
    tree.erase("apple");
    cout<<tree.countWordsEqualTo("apple")<<endl;
    cout<<tree.countWordsStartingWith("app")<<endl;
    tree.erase("apple");
    cout<<tree.countWordsStartingWith("app")<<endl;
    cout<<"*************"<<endl;
    int a = -1;
    ~a;
    cout<<a<<endl;
    return 0;
}
