/*
给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
*/

// 沿着 hash 值小于 k 的进行切分
int longestSubstring(string s, int k) {
    if(k<=1) return s.size();
    if(s.empty()||s.size()<k) return 0;

    int hash[26] = {0};

    for(const auto&c: s) ++hash[c-'a'];

    int i=0;
    // 查找 hash 值大于 k 的位置
    while(i<s.size()&&hash[s[i]-'a']>=k) ++i;
    // hash 值全部大于 k
    if(i==s.size()) return s.size();

    // 左边 hash 值全都 大于 k 进一步处理
    int l = longestSubstring(s.substr(0, i), k);

    // 查找 hash值下一个大于 k 的位置
    while(i<s.size()&&hash[s[i]-'a']<k) ++i;

    // 左边 hash 值 大于 k 进一步处理
    int r = longestSubstring(s.substr(i), k);

    return max(l, r);
}
