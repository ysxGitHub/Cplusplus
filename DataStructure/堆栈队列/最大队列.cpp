/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1
*/

#include <queue>
#include <iostream>
using namespace std;

class MaxQueue {
private:
    queue<int>que;
    deque<int>dq;
public:
    MaxQueue() {

    }

    int max_value() {
        if(dq.empty()) return -1;
        else return dq.front();
    }

    void push_back(int value) {
        while(!dq.empty()&&dq.back()<value){
            dq.pop_back();
        }
        dq.push_back(value);
        que.push(value);
    }

    int pop_front() {
        if(que.empty()) return -1;
        else{
            int num = que.front();
            if(num==dq.front()) dq.pop_front();
            que.pop();
            dq.pop_front();
            return num;
        }
    }
};