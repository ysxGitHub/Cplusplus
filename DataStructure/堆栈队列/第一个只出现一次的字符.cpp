/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
*/
#include <unordered_map>
#include <queue>
using namespace std;

char firstUniqChar(string s) {
    unordered_map<char, int> postition;
    queue<pair<char, int>>que;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(postition.count(c)==0){
            postition[c] = i;
            que.emplace(c, i);
        }else{
            postition[c] = -1;
            while(!que.empty()&&postition[que.front().first]==-1){
                que.pop();
            }
        }
    }
    return que.empty()?' ':que.front().first;
}