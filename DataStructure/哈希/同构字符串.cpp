/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
*/

#include<unordered_map>
#include<iostream>
using namespace std;
/*
1. add egg
    a->e
    d->g
    d->g
true
2. foo  bar
    f->b
    o->a
    o->r
false
*/

bool isIsomorphic(string s, string t) {
    int n = s.size();
    unordered_map<char, char>s1, t1;
    for(int i=0; i<n; i++){
        char x = s[i], y = t[i];
        if(s1.count(y)&&s1[y]!=x||t1.count(x)&&t1[x]!=y){
            return false;
        }
        s1[y] = x;
        t1[x] = y;
    }
    return true;
}