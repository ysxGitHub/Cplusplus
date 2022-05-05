/*
��һ���ַ��� s?������ÿһ����ĸ�Ĵ�д��Сд��ʽ ͬʱ?������ s?�У��ͳ�����ַ���?s?�� ���� �ַ�����
�ȷ�˵��"abABB"?�������ַ�������Ϊ?'A' ��?'a'?ͬʱ�����ˣ���?'B' ��?'b'?Ҳͬʱ�����ˡ�
Ȼ����"abA"?���������ַ�����Ϊ?'b'?�����ˣ���?'B'?û�г��֡�

����һ���ַ���?s?�����㷵��?s?���?�������ַ���?������ж���𰸣����㷵��?����?���ֵ�һ����
����������������ַ��������㷵��һ�����ַ�����
*/

#include<iostream>
#include<queue>
using namespace std;

string finddiff(string s){
    queue<char>c;
    for(int i=0; i<s.length(); i++){
        if(s[i]>90){
            if(s.find((char)(s[i]-32))>200){
                c.push(s[i]);
            }
        }else{
            if(s.find((char)(s[i]+32))>200){
                c.push(s[i]);
            }
        }
    }
    if(c.empty()){
        return s;
    }
    else{
        return "";
    }
}



string longestNiceSubstring(string s) {
    int lens = s.length();
    string ans="";
    if (lens==1){
        return "";
    }
    for(int i=0; i<lens-1; i++){
        for(int j=1; j<lens-i; j++){
            string tmp = finddiff(s.substr(i, j+1));
            if(tmp.length()>ans.length()){
                ans = tmp;
            }
        }
    }
    return ans;
}

/******************�ֶ���֮*******************/
void dfs(const string & s, int start, int end, int & maxPos, int & maxLen) {
    if (start >= end) {
        return;
    }
    int lower = 0, upper = 0;
    for (int i = start; i <= end; ++i) {
        if (islower(s[i])) {
            lower |= 1 << (s[i] - 'a');
        } else {
            upper |= 1 << (s[i] - 'A');
        }
    }
    if (lower == upper) {
        if (end - start + 1 > maxLen) {
            maxPos = start;
            maxLen = end - start + 1;
        }
        return;
    } 
    int valid = lower & upper;
    int pos = start;
    while (pos <= end) {
        start = pos;
        while (pos <= end && valid & (1 << (tolower(s[pos]) - 'a'))) {
            ++pos;
        }
        dfs(s, start, pos - 1, maxPos, maxLen);
        ++pos;
    }
}

string longestNiceSubstring1(string s) {
    int maxPos = 0, maxLen = 0;
    dfs(s, 0, s.size() - 1, maxPos, maxLen);
    return s.substr(maxPos, maxLen);
}

//�ֶ���֮
string longestNiceSubstring3(string s){
    if(s.length()<2){
        return "";
    }
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if((c <= 'Z' && s.find((char)(c + 32))>200) || (c >= 'a' && s.find((char)(c - 32))>200)){
            string s1 = longestNiceSubstring3(s.substr(0, i));
            string s2 = longestNiceSubstring3(s.substr(i+1));
            if(s1.length() >= s2.length())
                return s1;
            return s2;
        }
    }
    return s;
}





int main(int argc, char const *argv[])
{
    string s = "aaAaAabb";
    cout<<longestNiceSubstring(s)<<endl;
    cout<<longestNiceSubstring3(s)<<endl;
    return 0;
}


