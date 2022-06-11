/*
当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。

给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
*/


int monotoneIncreasingDigits(int n) {
    string s = to_string(n);
    int ns = s.size();
    int flag = ns;
    for(int i=ns-1; i>0; --i){
        if(s[i]<s[i-1]){
            flag = i;
            s[i-1]--;
        }
    }
    for(int i=ns-1; i>=flag; --i){
        s[i] = '9';
    }
    return stoi(s);
}