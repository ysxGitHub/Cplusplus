/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

注意： 子序列与子串的区别

0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成

利用移动窗口法
*/

#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;


int lengthOfLongestSubstring(string s) {
    unordered_map<char, int>mywin;
    int res = 0;
    int left = 0;
    int right=0;
    while(right<s.length()){
        char c = s[right];
        right++;
        mywin[c]++;
        while(mywin[c] > 1){
            // 将left移动到right，并将>1的元素减1.
            char b = s[left];
            mywin[b]--;
            left++;
        }
        res = max(res, right - left);
    }
    return res;
}

int lengthOfLongestSubstring1(string s) {
    unordered_set<char>look;
    int left = 0, maxlen = 0;

    for(int right=0; right<s.size(); right++){
        // 删除左边的看到过的字符（包括与当前字符不同的字符），直到删除到现在遇到的
        while(look.find(s[right])!=look.end()){
            look.erase(s[left]);
            left++;
        }
        maxlen = max(maxlen, right-left+1);
        look.insert(s[right]);
    }
    return maxlen;
}

int lengthOfLongestSubstring2(string s) {
    unordered_map<char, int>look;
    int ans = 0, start = 0;
    for(int i=0; i<s.size(); i++){
        look[s[i]]++;
      
        if(look.size() == i - start + 1){
            ans = max(ans, i - start + 1);
        } 
        
        while(i - start + 1 > look.size()){
            char d = s[start];
            look[d]--;
            if(look[d]==0){
                look.erase(d);
            }
            ++start;
        }
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    string s = "pwwkew";

    cout<<lengthOfLongestSubstring1(s)<<endl;
    cout<<lengthOfLongestSubstring2(s)<<endl;
    // cout<<s.find("a");

    return 0;
}

