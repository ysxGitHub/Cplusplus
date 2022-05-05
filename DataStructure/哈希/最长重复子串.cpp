/*
给你一个字符串 s ，考虑其所有 重复子串 ：即 s 的（连续）子串，在 s 中出现 2 次或更多次。
    这些出现之间可能存在重叠。

返回 任意一个 可能具有最长长度的重复子串。如果 s 不含重复子串，那么答案为 "" 。
*/

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// 超时
string longestDupSubstring1(string s) {
    unordered_map<string, int>cnt;
    int n = s.size();
    string ans;
    for(int i=0; i<n; i++){
        for(int j=1; j+i<n+1; j++){
            string ts = s.substr(i, j);
            cnt[ts]++;
            if(cnt[ts]>1){
                if(ts.size()>ans.size()) ans = ts;
            }
        }
    }
    return ans;
}


vector<ull> h, p;

string check(string s, int len) {
    int n = s.size();
    unordered_set<ull>cnt;

    for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        ull cur;
        if(i==0){
            cur = h[j];
        }else{
            cur = h[j] - h[i - 1] * p[j - i + 1];
        }
        if (cnt.count(cur)) return s.substr(i, len);
        cnt.insert(cur);
    }
    return "";
}

string longestDupSubstring(string s) {
    int P = 133331, n = s.length();
    h.resize(10+n), p.resize(10+n);

    p[0] = 1;
    h[0] = s[0];

    for (int i = 1; i < n; i++) {
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + s[i];
    }

    string ans = "";
    int l = 0, r = n;

    while (l < r) {
        int mid = (l + r + 1) >> 1;
        string t = check(s, mid);
        if (t.size() != 0) l = mid;
        else r = mid - 1;
        ans = t.size() > ans.size() ? t : ans;
    }
    return ans;
}

