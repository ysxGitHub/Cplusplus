/*
现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。

给定一个字符串列表 words ，作为这门语言的词典，words 中的字符串已经 按这门新语言的字母顺序进行了排序 。

请你根据该词典还原出此语言中已知的字母顺序，并 按字母递增顺序 排列。若不存在合法字母顺序，返回 "" 。若存在多种可能的合法字母顺序，返回其中 任意一种 顺序即可。

字符串 s 字典顺序小于 字符串 t 有两种情况：

在第一个不同字母处，如果 s 中的字母在这门外星语言的字母顺序中位于 t 中字母之前，那么 s 的字典顺序小于 t 。
如果前面 min(s.length, t.length) 字母都相同，那么 s.length < t.length 时，s 的字典顺序也小于 t 。
*/

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

string alienOrder(vector<string>& words) {
    vector<vector<int>> graph(26); // 建图
    vector<int> indegree(26); // 入度
    vector<bool> seen(26, false); // 该字母是否出现过
    queue<int>q; //
    int cnt = 0; // 字母出现的个数
    int n = words.size();
    string res="";
    for(const auto&word: words){
        for(const auto&c: word){
            if(seen[c-'a']==false) cnt++;
            seen[c-'a']=true;
        }
    }
    for(int i=0; i<n-1; ++i){
        string p = words[i], q = words[i+1];
        int ok=0, plen = p.size(), qlen = q.size();
        int minlen = min(plen, qlen);
        for(int j=0; j<minlen; ++j){
            if(p[j]==q[j]) continue;
            ok = 1;
            indegree[q[j]-'a']++;
            graph[p[j]-'a'].emplace_back(q[j]-'a');
            break;
        }
        if(!ok&&plen>=qlen) return "";
    }
    for(int i=0; i<26; ++i){
        if(indegree[i]==0&&seen[i]){
            q.emplace(i);
        }
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        res += (cur+'a');
        for(const auto&ne: graph[cur]){
            indegree[ne]--;
            if(indegree[ne]==0){
                q.emplace(ne);
            }
        }
    }
    return res.size()==cnt?res:"";
}


int main(int argc, char const *argv[])
{

    return 0;
}



