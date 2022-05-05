/*
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，
    请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
    如果不存在，则返回  -1

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
    对于本题而言，当 needle 是空字符串时我们应当返回 0 。
    这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strStr1(string haystack, string needle) {
    if(needle.empty()){
        return 0;
    }
    int lenh = haystack.length();
    int lenn = needle.length();
    int i = 0, j;
    while(i < (lenh-lenn)+1){
        j = 0;
        while(j < lenn){
            if(haystack[i+j]==needle[j]){
                j++;
                if(j==lenn){
                    return i;
                }
            } 
            else{
                break;
            }   
        }
        i++;
    }
    return -1;
}


/*
abcabd
a       0  -1
ab      0  -1
abc     0  -1
abca    1   0
abcab   2   1
abcabd  0  -1
*/
//我会每一步都写上注释
void Next(string needle, vector<int>& next) {
    // 初始化
    next.push_back(-1);
    int k = -1;
    for (int i = 1; i < needle.length(); ++i) {
        //我们此时知道了 [0,i-1]的最长前后缀，但是k+1的指向的值和i不相同时，我们则需要回溯
        //因为 next[k]就时用来记录子串的最长公共前后缀的尾坐标（即长度）
        //就要找 k+1前一个元素在next数组里的值,即next[k+1]
        while (k != -1 && needle[k + 1] != needle[i]) {
            k = next[k];
        }
        // 相同情况，就是 k的下一位，和 i 相同时，此时我们已经知道 [0,i-1]的最长前后缀
        //然后 k - 1 又和 i 相同，最长前后缀加1，即可
        if (needle[k+1] == needle[i]) {
            ++k;
        }
        next.push_back(k);

    }
}


int kmp (string hasyarr, string nearr) {
    int halen = hasyarr.length();
    int nelen = nearr.length();
    //获取next 数组
    vector<int>next;
    Next(nearr, next);
    // 初始化
    int j = 0;
    for (int i = 0; i < halen; ++i) {
        //发现不匹配的字符，然后根据 next 数组移动指针，移动到最大公共前后缀的，
        //前缀的后一位,和咱们移动模式串的含义相同
        while (j > 0 && hasyarr[i] != nearr[j]) {
            j = next[j - 1] + 1;
            // cout<<i<<"   "<<j<<endl;
            //超出长度时，可以直接返回不存在
            if (nelen - j > halen - i) {
                return -1;
            }
        }
        //如果相同就将指针同时后移一下，比较下个字符
        if (hasyarr[i] == nearr[j]) {
            ++j;
        }
        //遍历完整个模式串，返回模式串的起点下标
        if (j == nelen) {
            return i - nelen + 1;
        }
    }
    return -1;
}



int strStr(string haystack, string needle) {
    // 当 needle 是空字符串时我们应当返回 0
    if (needle.length() == 0) {
        return 0;
    }
    // 当 haystack 是空字符串时我们应当返回 -1
    if (haystack.length() == 0) {
        return -1;
    }
    return kmp(haystack, needle);
}

int main(int argc, char const *argv[])
{
    string haystack = "aabaaabaaac";
    string needle = "aabaaac";

    cout<<strStr1(haystack, needle)<<endl;
    return 0;
}

