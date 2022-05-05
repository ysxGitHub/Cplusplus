/*
给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。

s 的 旋转操作 就是将 s 最左边的字符移动到最右边。 

例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
*/

bool rotateString(string s, string goal) {
    if(s.size()!=goal.size()) return 0;
    int n = s.size();
    for(int i=1; i<=n; i++){
        if(s.substr(i,n)+s.substr(0,i)==goal) return 1;
    }
    return 0;
}