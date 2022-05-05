/*
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
    需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
*/

#include<vector>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;


string removeDuplicateLetters(string s) {
    vector<char> stk;
    unordered_map <char, int> cnt;
    unordered_set <char> seen;
    // 统计个元素的个数
    for(char c : s) cnt[c]++;

    for(char c : s){
        if(seen.count(c)==0){
            while(!stk.empty() && stk.back()>c && cnt[stk.back()]){
                // 从栈中弹出大于当前的字典序的元素(弹出的元素的后面还可以遇到)，
                seen.erase(stk.back());
                stk.pop_back();
            }
            // 并将c加入栈中
            seen.insert(c);
            stk.emplace_back(c);
        }
        // 遇到一次就减减
        cnt[c]--;
    }
    string ans;
    for(char c: stk){
        ans += c;
    } 
    return ans;
}


int main(int argc, char const *argv[])
{
    cout<<removeDuplicateLetters("cdbacb")<<endl;
    return 0;
}
