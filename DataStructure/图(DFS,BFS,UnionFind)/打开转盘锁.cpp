/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。
*/
#include<vector>
#include<queue>
#include<iostream>
#include<unordered_set>
using namespace std;

int openLock(vector<string>& deadends, string target) {
    queue<string>que;
    unordered_set<string>seen={deadends.begin(), deadends.end()};
    if(target=="0000") return 0;
    if(seen.count("0000")) return -1;
    que.push("0000");
    int level = 0;
    while(!que.empty()){
        int size = que.size();
        for(int i=0; i<size; i++){
            string s = que.front();
            // cout<<s<<", ";
            que.pop();
            for(int i=0; i<4; i++){
                string s1 = s;
                if(s[i]=='0'){
                    s1[i]++;
                    if(s1==target) return ++level;
                    if(seen.count(s1)==0){
                        que.push(s1);
                        seen.insert(s1);
                    }
                    s1 = s;
                    s1[i]='9';
                    if(s1==target) return ++level;
                    if(seen.count(s1)==0){
                        que.push(s1);
                        seen.insert(s1);
                    }
                }
                else if(s[i]=='9'){
                    s1[i]='0';
                    if(s1==target) return ++level;
                    if(seen.count(s1)==0){
                        que.push(s1);
                        seen.insert(s1);
                    }
                    s1 = s;
                    s1[i]--;
                    if(s1==target) return ++level;
                    if(seen.count(s1)==0){
                        que.push(s1);
                        seen.insert(s1);
                    }
                }
                else{
                    s1[i]++;
                    if(s1==target) return ++level;
                    if(seen.count(s1)==0){
                        que.push(s1);
                        seen.insert(s1);
                    }
                    s1=s;
                    s1[i]--;
                    if(s1==target) return ++level;
                    if(seen.count(s1)==0){
                        que.push(s1);
                        seen.insert(s1);
                    }
                }

            }
        }
        level++;
    }
    return -1;
}