/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
返回一个表示每个字符串片段的长度的列表。
*/

#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> partitionLabels1(string s) {
    unordered_map<char, int> cnt;
    unordered_map<char, int> seen;
    vector<int> ans;
    int start=0;
    for(char c:s) cnt[c]++;

    for(int i=0; i<s.size(); i++){
        seen[s[i]]++;
        if(seen.size()){
            bool flag=1;
            for(auto&ch : seen){
                if(cnt[ch.first]!=ch.second){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans.emplace_back(i-start+1);
                start = i+1;
                seen.clear();
            }
        }
    }
    return ans;
}

// 贪心 先记录每一个字符最后一次出现的位置, 再遍历一遍字符串
vector<int> partitionLabels(string s) {
    int start = 0, end = 0, n = s.size();
    vector<int> ans;
    int lastOnceAppear[26];
    for(int i=0; i<n; i++){
        lastOnceAppear[s[i]-'a'] = i;
    }

    for(int i=0; i<n; i++){
        end = max(end, lastOnceAppear[s[i]-'a']);
        if(end == i){
            ans.emplace_back(end - start + 1);
            start = end + 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
