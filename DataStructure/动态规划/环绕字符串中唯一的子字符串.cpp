/*
把字符串 s 看作是 “abcdefghijklmnopqrstuvwxyz” 的无限环绕字符串，所以 s 看起来是这样的：

"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...." . 
现在给定另一个字符串 p 。返回 s 中 唯一 的 p 的 非空子串 的数
*/

int findSubstringInWraproundString(string p) {
    // dp[α] 表示 p 中以字符 α 结尾且在 s 中的子串的最长长度
    int az[26] = {0};
    int maxlen = 1;
    az[p[0]-'a'] = 1;
    for(int i=1; i<p.size(); ++i){
        // 是否满足递增
        if(p[i-1]==p[i]-1||p[i-1]==p[i]+25){
            ++maxlen;
        }else{
            maxlen=1;
        }
        // 记录 p 中以字符 α 结尾且在 s 中的子串的最长长度
        if(az[p[i]-'a']<maxlen){
            az[p[i]-'a'] = maxlen;
        }
    }
    // 返回所有 dp 和
    return accumulate(az, az+26, 0);
}