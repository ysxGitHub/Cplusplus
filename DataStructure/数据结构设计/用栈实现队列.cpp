/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：
    void push(int x) 将元素 x 推到队列的末尾
    int pop() 从队列的开头移除并返回元素
    int peek() 返回队列开头的元素
    boolean empty() 如果队列为空，返回 true ；否则，返回 false

*/

#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
stack<int> s1;
stack<int> s2;

public:
    MyQueue() { }

    void push(int x) {
        s1.emplace(x);
    }

    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }

    int peek() {
        // 注意这个s2.empty()很重要，保证了先进可以先出
        if(s2.empty()){
            while(!s1.empty()){
                s2.emplace(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
