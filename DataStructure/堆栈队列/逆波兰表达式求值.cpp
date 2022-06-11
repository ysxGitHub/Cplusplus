/*
根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

注意 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
*/

inline void ppp(stack<int>&stk, int &a, int &b){
    a = stk.top();
    stk.pop();
    b = stk.top();
    stk.pop();
}
int evalRPN(vector<string>& tokens) {
    stack<int>stk;
    int a=0, b=0;
    for(auto&s: tokens){
        if(s=="+"){
            ppp(stk, a, b);
            stk.push(a+b);
        }
        else if(s=="-"){
            ppp(stk, a, b);
            stk.push(b-a);
        }
        else if(s=="*"){
            ppp(stk, a, b);
            stk.push(a*b);
        }
        else if(s=="/"){
            ppp(stk, a, b);
            stk.push(b/a);
        }else{
            stk.push(stoi(s));
        }
    }
    return stk.top();
}