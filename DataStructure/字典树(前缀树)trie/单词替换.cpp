/*
在英语中，我们有一个叫做 词根(root) 的概念，可以词根后面添加其他一些词组成另一个较长的单词——我们
    称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 
    another(另一个)。

现在，给定一个由许多词根组成的词典 dictionary 和一个用空格分隔单词形成的句子 sentence。
    你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

你需要输出替换之后的句子。
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

#define N 26
struct TrieNode{
    int cnt;
    char ch;
    TrieNode** son;
    TrieNode(char a){
        cnt = 0;
        ch = a;
        son = new TrieNode*[N];
        for(int i=0; i<N; i++) son[i]=nullptr;
    }
};

class Trie{
private:
    TrieNode *root;
public:
    Trie(){root = new TrieNode(' ');}
    void insert(string word){
        TrieNode* p = root;
        for(int i=0; i<word.size(); i++){
            int c = word[i] - 'a';
            if(!p->son[c]){p->son[c] = new TrieNode(word[i]);}
            p = p->son[c];
        }
        ++p->cnt;
    }
    string query(string word){
        TrieNode* p = root;
        string res;
        for(int i=0; i<word.size(); i++){
            int c = word[i] - 'a';
            if(p->son[c]){
                res+=word[i];
                p = p->son[c];
                if(p->cnt){
                    return res;
                }
            }
            else{
                if(p->cnt){
                    return res;
                }
                else{
                    return "";
                }
            }
        }
        return res;
    }

};


string replaceWords(vector<string>& dictionary, string sentence) {
    Trie tree;
    for(auto&str: dictionary){
        tree.insert(str);
    }
    stringstream str(sentence);
    string word;
    string ans;
    while(str>>word){
        string res = tree.query(word);
        if(res.size()){
            ans+=res;
        }else{
            ans+=word;
        }
        ans+=' ';
    }
    ans.pop_back();
    return ans;
}

