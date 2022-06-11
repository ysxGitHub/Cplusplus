/*
给定一个字符串 s，计算 s 的 不同非空子序列 的个数。因为结果可能很大，所以返回答案需要对 10^9 + 7 取余 。

字符串的 子序列 是经由原字符串删除一些（也可能不删除）字符但不改变剩余字符相对位置的一个新字符串。

例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
abac
a  0+1      = 1   a=1
ab 1+1      = 2   b=2
aba 1+2+1   = 4   a=4
abaa 4+2+1  = 7   a=7
                  a+b=9
*/

/*
最开始的思路是用Trie来表示所有可能subseq.
遍历string S，对Trie中每个节点新建叶节点。
提交后果然答案对了，但是Memory Limit Exceed。

转念一想，没必要存下所有节点，只需要知道当前节点的数量就好了。
Trie中一个节点对应一个seq。
假设当前有N个不同的seq，每个seq加上一个新的字母，又是新的N个不同sequence了。
但新的seq中，有一部分原来就有。
比如新的字母是'a'，那么原来以'a'结尾的seq，每一个都会存在新的这N个seq中。

*/
int distinctSubseqII(string s) {
    long endWith[26]={}, mod = 1e9+7;
    for(auto&c: s){
        // 遍历字符串更新dp数组
        endWith[c-'a'] = accumulate(begin(endWith), end(endWith), 1L)%mod;
        cout<<c<<": "<<endWith[c-'a']<<endl;
    }
    return accumulate(begin(endWith), end(endWith), 0L)%mod;
}

int main(int argc, char const *argv[])
{
    distinctSubseqII("abaa");
    return 0;
}
