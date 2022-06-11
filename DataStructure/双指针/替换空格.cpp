/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
*/

string replaceSpace(string s) {
    int cntSpace = 0;
    for(char&c: s){
        if(c==' ') cntSpace++;
    }
    int n = s.size(), newn = n + cntSpace*2;
    s.resize(newn);
    for(int i=n-1, j=newn-1; i>=0; --i){
        if(s[i]!=' '){
            s[j--] = s[i];
        }else{
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        }
    }
    return s;
}