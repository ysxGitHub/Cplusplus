/*
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；
    否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。
*/

#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;


bool checkInclusion(string s1, string s2) {
    unordered_map<char, int>wind, need;
    int left=0, right=0, valid=0;
    for(auto&c: s1){need[c]++; }

    while(right<s2.size()){
        char c = s2[right];
        // 右边界增加
        right++;
        // 如果当前字符是需要的字符
        if(need.count(c)){
            // 窗口的字符数增加
            wind[c]++;
            // 窗口的该字符数等于需要的该字符时
            if(wind[c]==need[c]){valid++; }
        }
        // 窗口满足长度
        while(right-left>=s1.size()){
            // 检查需要的字符是否都满足
            if(valid==need.size()){
                return 1;
            }
            char d = s2[left];
            // 左边界移动
            left++;
            // 左边的字符是需要的字符，则valid--
            if(need.count(d)){
                if(need[d]==wind[d]) {valid--; }
                wind[d]--;
            }
        }
    }
    return 0;
}


bool checkInclusion1(string s1, string s2) {
    unordered_map<char, int>wind, need;
    int start=0, n=s2.size();
    for(auto&c : s2){
        need[c]++;
    }
    for(int i=0; i<s1.size(); i++){
        wind[s1[i]]++;
        
        if(wind.size()==need.size()){
            bool same = 1;
            for(auto&c : need){
                if(wind.count(c.first)==0){
                    same=0;
                    break;
                }
                if(wind[c.first]!=c.second){
                    same=0;
                    break;
                }
            }
            if(same){
                return true;
            }
        }

        if(i+1>=n){
            char c = s1[start];
            wind[c]-=1;
            if(wind[c]==0){
                wind.erase(c);
            }
            ++start;
        }

    }
    return false;
}

int main(int argc, char const *argv[])
{
    cout<<checkInclusion1("abcds", "dcbac");
    return 0;
}
