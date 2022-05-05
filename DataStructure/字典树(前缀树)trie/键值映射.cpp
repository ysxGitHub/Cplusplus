/*
设计一个 map ，满足以下几点:

字符串表示键，整数表示值
返回具有前缀等于给定字符串的键的值的总和
实现一个 MapSum 类：

MapSum() 初始化 MapSum 对象
void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。
    如果键 key 已经存在，那么原来的键值对 key-value 将被替代成新的键值对。

int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
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

class MapSum {
private:
    TrieNode *root;
public:
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode* p = root;
        for(int i=0; i<key.size(); i++){
            int c = key[i] - 'a';
            if(!p->son[c]){p->son[c] = new TrieNode();}
            p = p->son[c];
        }
        p->cnt=val;
    }
    void traverse(TrieNode *p, int& ans){
        if(p->cnt){
            ans+=p->cnt;
        }
        for(int i=0; i<N; i++){
            if(p->son[i]){
                traverse(p->son[i], ans);
            }
        }

    }
    int sum(string prefix) {
        int ans = 0;
        TrieNode * p = root;
        for(int i=0; i<prefix.size(); i++){
            int c = prefix[i] -'a';
            if(!p->son[c]){
                return 0;
            }
            p = p->son[c];
        }
        traverse(p, ans);
        return ans;
    }
};
