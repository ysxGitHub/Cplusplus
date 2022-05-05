/*
DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。

例如，"ACGAATTCCG" 是一个 DNA序列 。
在研究 DNA 时，识别 DNA 中的重复序列非常有用。

给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。
    你可以按 任意顺序 返回答案。
*/

#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

vector<string> findRepeatedDnaSequences1(string s) {
    unordered_map<string, int>cnt;
    int n = s.size();
    vector<string> ans;
    for(int i=0; i<n; i++){
        string ts = s.substr(i, 10);
        cnt[ts]++;
        if(cnt[ts]==2) ans.push_back(ts);  
    }
    return ans;
}


// 字符哈希
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;

    const int P = 13331;
    int n = s.size();
    vector<ull> h(n), p(n);
    
    h[0] = s[0];
    p[0] = 1;

    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] * P + s[i];
        p[i] = p[i - 1] * P;
    }

    unordered_map<ull, int> hashmap;
    for (int i = 0; i + 10 - 1 < n; i++) {
        int j = i + 10 - 1;
        ull hash;
        if(i==0){
            hash = h[j];
        }else{
            hash = h[j] - h[i - 1] * p[j - i + 1];
        }
        hashmap[hash]++;
        if (hashmap[hash] == 2) ans.push_back(s.substr(i, 10));
    }
    return ans;    
}
