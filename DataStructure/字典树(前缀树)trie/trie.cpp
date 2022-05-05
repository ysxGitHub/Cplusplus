/*

*/

#include<iostream>
#include<vector>
#include<unordered_map>

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
 
// 方法1: 类似链表
class TrieLink{
private:
    TrieNode* root;
public:
    TrieLink(){root = new TrieNode(' ');}
    TrieLink(char c){root = new TrieNode(c);}
     
    void insert(string s){
        TrieNode * p = root;
        for(int i=0; i<s.length(); i++){
            int c = s[i] - 'a';
            if(!p->son[c]){
                p->son[c] = new TrieNode(s[i]);
            }
            p = p->son[c];
        }
        ++p->cnt;
    }

    int query(string s){
        TrieNode * p = root;
        for(int i=0; i<s.length(); i++){
            int c = s[i] - 'a';
            if(!p->son[c]){
                return 0;
            }
            p = p->son[c];
        }
        return p->cnt;
    }

};



class Trie{
private:
    vector<unordered_map<int, int>>trietable;
    vector<int>cnt;
    int idx;
public:
    Trie(){
        trietable.resize(256);
        cnt.resize(256, 0);
        idx = 0;
    }
    Trie(int size){
        trietable.resize(size);
        cnt.resize(size, 0);
        idx = 0;        
    }
    void insert(string s){
        int p = 0;
        for(int i=0; i<s.length(); i++){
            int c = s[i] - 'a';
            if(!trietable[p][c]){
                trietable[p][c] = ++idx;
            }
            p = trietable[p][c];
            cout<<p<<" ";
        }
        cout<<endl;
        ++cnt[p];
    }
    int query(string s){
        int p=0;
        for(int i=0; i<s.length(); i++){
            int c = s[i] - 'a';
            if(!trietable[p][c]){
                return 0;
            }
            p = trietable[p][c];
        }
        return cnt[p];
    }

    // int prefixQuery(string s){
    //     int p=0;
    //     int sum=0;
    //     for(int i=0; i<s.length(); i++){
    //         int c = s[i] - 'a';
    //         if(!trietable[p][c]){
    //             break;
    //         }
    //         p = trietable[p][c];
    //         sum+=cnt[p];
    //     }
    //     return sum;        
    // }

};



int main(int argc, char const *argv[])
{
    Trie tree;
    tree.insert("apple");
    cout<<tree.query("apple")<<endl;
    cout<<tree.query("app")<<endl;
    // cout<<tree.prefixQuery("aab")<<endl;
    cout<<tree.startsWith("app")<<endl;
    return 0;
}
