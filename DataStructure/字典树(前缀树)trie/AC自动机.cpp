/*
1. 构建trie
2. 构建fail指针
    a.它是BFS来构建
    b.它第一层全部指向root
    c.fail指向：
        它的父亲的fail节点的同字符儿子
        若没找到，就继续跳fail，直达跳到root还没 指向root

    fail的含义：当前字符的最长后缀
3.匹配
    不断跳fail
*/

#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;
#define N 26

struct TrieNode
{
    int cnt;
    TrieNode* fail;
    TrieNode** son;
    TrieNode(){
        cnt = 0;
        fail = nullptr;
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
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * p = root;
        for(int i=0; i<word.length(); i++){
            int c = word[i] - 'a';
            if(!p->son[c]){
                p->son[c] = new TrieNode();
            }
            p = p->son[c];
        }
        ++p->cnt;
    }

    void failPre(){
        // BFS遍历
        queue<TrieNode*> q;
        for(int i=0; i<N; i++){
            TrieNode* son = root->son[i];
            if(son){
                // root的子节点的fail指向root
                son->fail = root;
                q.emplace(son);
            }
        }
        while(!q.empty()){
            TrieNode* f = q.front();
            q.pop();
            for(int i=0; i<N; i++){
                // 当前节点
                TrieNode* now = f->son[i];
                if(now){
                    // 当前节点的父节点的fail指向
                    TrieNode* ffail = f->fail;
                    /*
                    当前节点的 父节点的 fail指向的节点 的子节点不是 与当前节点同字符
                    继续跳fail，直到跳到root还没有，就时当前节点的fail指向root
                    */
                    while(ffail&&!ffail->son[i]){
                        ffail = ffail->fail;
                    }
                    // 找到当前节点的 父节点的 fail指向的节点 的子节点 与 当前节点同字符
                    if(ffail){
                        now->fail = ffail->son[i];
                    }
                    else{
                        now->fail = root;
                    }
                    q.emplace(now);
                }
            }
        }
    }

    int query(string s){
        int ans = 0;
        TrieNode* p = root;
        for(int i=0; i<s.length(); i++){
            int word = s[i] - 'a';

            // 如果p的子节点不等于word，要进行跳fail，直到跳到fail不在（即p等于root->fail）
            while(!p->son[word]&&p->fail){
                p = p->fail;
            }
            // 跳到一个p的子节点等于word，
            if(p->son[word]){
                p = p->son[word]; 
            }else{ // 没有能够跳到一个p的子节点等于word，则进行下一轮循环
                continue;
            }
            // 先记录下p，注意这里p已经跳到下一个存在word的节点处
            TrieNode* p2 = p;
            // 让p2替p跳fail
            while(p2->fail){
                ans += p2->cnt;
                p2 = p2->fail;
            }
        }
        return ans;
    }

};


int main(int argc, char const *argv[])
{
    Trie tree;
    tree.insert("she");
    tree.insert("her");
    tree.insert("he");
    tree.insert("this");
    tree.insert("his");
    tree.insert("is");
    tree.failPre();
    cout<<tree.query("sherthis");
    return 0;
}
