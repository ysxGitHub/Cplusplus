/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。
    不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    unordered_map<char, int>wind, need;
    int left=0, right=0, valid=0;
    for(auto&c : p){
        need[c]++;
    }

    while(right<s.size()){
        char c = s[right];
        right++;
        if(need.count(c)){
            wind[c]++;
            if(wind[c]==need[c]){
                valid++;
            }
        }

        while(right-left>=p.size()){
            if(valid==need.size()){
                ans.emplace_back(left);
            }
            char d = s[left];
            left++;
            if(need.count(d)){
                if(need[d]==wind[d]){
                    valid--;
                }
                wind[d]--;
            }

        }

    }
    return ans;
}

vector<int> findAnagrams1(string s, string p) {
    int start = 0, n=p.size();
    vector<int>ans;
    unordered_map<char, int>wind, phash;
    for(char c : p){
        phash[c]++;
    }

    for(int i=0; i<s.size(); i++){

        wind[s[i]]++;

        if(wind.size() == phash.size()){
            bool same = 1;
            for(auto & c : phash){
                if(wind.count(c.first) == 0){
                    same = 0;
                    break;
                }
                if(wind[c.first] != c.second){
                    same = 0;
                    break;
                }
            }
            if(same){
                ans.emplace_back(start);
            }
        }

        if(i + 1 >= n){
            char c = s[start];
            wind[c]-=1;
            if(wind[c]==0){
                wind.erase(c);
            }
            start++;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> ans = findAnagrams("abaababab","aab");  
    for(auto&n : ans){
        cout<<n<<", ";
    } 
    return 0;
}
