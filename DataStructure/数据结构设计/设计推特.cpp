/*

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<vector>

using namespace std;

class Twitter {
    struct Node{
        // 订阅的人
        unordered_set<int> followee;
        // 发出的推特
        list<int> twee;
    };
    int systemTime, maxMess;
    // 每个推特对应的时间
    unordered_map<int, int>tweeToTime;
    //user 
    unordered_map<int, Node>user;
public:
    Twitter() {
        systemTime = 0;
        maxMess = 10;
    }
    void init(int userId){
        user[userId].followee.clear();
        user[userId].twee.clear();
    }
    void postTweet(int userId, int tweetId) {
        if(user.find(userId)==user.end()){
            init(userId);
        }
        // 如果推文到达上限，先pop再push
        if(user[userId].twee.size()==maxMess){
            user[userId].twee.pop_back();
        }
        user[userId].twee.emplace_front(tweetId);
        tweeToTime[tweetId] = ++systemTime;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(list<int>::iterator it = user[userId].twee.begin(); it!=user[userId].twee.end(); it++){
            ans.emplace_back(*it);
        }
        for(auto&fee: user[userId].followee){
            // 排除自己关注自己的推文
            if(fee==userId){continue;}
            int i=0;
            vector<int> res;
            list<int>::iterator it  = user[fee].twee.begin();
            // 这个while一定i<10
            while(i<ans.size()&&it!=user[fee].twee.end()){
                if(tweeToTime[ans[i]]>tweeToTime[*it]){
                    res.emplace_back(ans[i]);
                    ++i;
                }else{
                    res.emplace_back(*it);
                    ++it;
                }
                // 达到最大展示推文数量
                if(res.size()==maxMess){break;}
            }
            // 这里res.size()<maxMess，不能等于
            while(i<ans.size()&&res.size()<maxMess){
                res.emplace_back(ans[i]);
                ++i;
            }
            while(it!=user[fee].twee.end()&&res.size()<maxMess){
                res.emplace_back(*it);
                ++it;
            }
            // 更新最新的推文，可以继续下次比较
            ans.assign(res.begin(),res.end());
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(user.find(followerId)==user.end()){
            init(followerId);
        }
        if(user.find(followeeId)==user.end()){
            init(followeeId);
        }  
        user[followerId].followee.insert(followeeId);      
    }
    
    void unfollow(int followerId, int followeeId) {
        user[followerId].followee.erase(followeeId);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
