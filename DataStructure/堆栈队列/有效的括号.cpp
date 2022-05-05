/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/

bool isValid(string s) {
    stack<char>stk;
    for(char c: s){
        if(c==')'||c==']'||c=='}'){
            if(stk.empty()) return false;
            if(c==')'&&stk.top()!='(') return false;
            if(c==']'&&stk.top()!='[') return false;
            if(c=='}'&&stk.top()!='{') return false;
            stk.pop();
        }else{
            stk.push(c);
        }
    }
    return stk.empty()?true:false;
}

