/*
给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。
*/

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int>stk;
    int j=0;
    for(int i=0; i<pushed.size(); i++){
        stk.push(pushed[i]);
        while(!stk.empty()&&stk.top()==popped[j]){
            j++;
            stk.pop();
        }
    }
    return stk.empty();
}
