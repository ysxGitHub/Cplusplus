/*
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：
    void push(int x) 将元素 x 压入栈顶。
    int pop() 移除并返回栈顶元素。
    int top() 返回栈顶元素。
    boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

*/

#include<iostream>
#include<queue>

using namespace std;

class MyStack {
queue<int> que1;
queue<int> que2;
public:
    MyStack() {}
    
    void push(int x) {
        que1.emplace(x);
    }
    
    int pop() {
        int len = que1.size();
        while(len>1){
            que2.emplace(que1.top());
            que1.pop();
            len--;
        }
        int ans = que1.top();
        que1.pop();
        len = que2.size();
        while(len>0){
            que1.emplace(que2.top());
            que2.pop();
            len--;
        }        
        return ans;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};