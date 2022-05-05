/*
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。
    word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define N 26
struct TrieNode{
    int cnt;
    TrieNode** son;
    TrieNode(){
        cnt = 0;
        son = new TrieNode*[N];
        for(int i=0; i<N; i++) son[i]=nullptr;
    }
};

class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* p = root;
        for(int i=0; i<word.size(); i++){
            int c = word[i] - 'a';
            if(!p->son[c]){p->son[c] = new TrieNode();}
            p = p->son[c];
        }
        ++p->cnt;
    }
    void traverse(TrieNode* p, int idx, string& word, bool& ans){
        if(idx>=word.size()){
            if(p->cnt){
                ans|=1;
                return;
            }
            else{
                return;
            }
        }
        if(word[idx]=='.'){
            for(int i=0; i<N; i++){
                if(p->son[i]){
                    traverse(p->son[i], idx+1, word, ans);
                }
            }
        }else{
            int c = word[idx] - 'a';
            if(p->son[c]){
                traverse(p->son[c], idx+1, word, ans);
            }else{
                return ;
            }
        }
    }

    bool search(string word) {
        bool ans=0;
        traverse(root, 0, word, ans);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    /*

["addWord","addWord","addWord","addWord",
"search","search",
"addWord",
"search","search","search","search","search","search"]
[["at"],["and"],["an"],["add"],
["a"],[".at"],
["bat"],
[".at"],["an."],["a.d."],["b."],["a.d"],["."]]
    */
    WordDictionary wd;
    wd.addWord("at");
    wd.addWord("and");
    wd.addWord("an");
    wd.addWord("add");
    cout<<wd.search("a")<<endl;
    cout<<wd.search(".at")<<endl;
    wd.addWord("bat");
    cout<<wd.search(".at")<<endl;
    cout<<wd.search("an.")<<endl;
    cout<<wd.search("a.d.")<<endl;
    cout<<wd.search("b.")<<endl;
    cout<<wd.search("a.d")<<endl;
    cout<<wd.search(".")<<endl;
    return 0;
}
