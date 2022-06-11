/*
给你一个字符串 s ，逐个翻转字符串中的所有 单词 。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

说明：
    输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
    翻转后单词间应当仅用一个空格分隔。
    翻转后的字符串中不应包含额外的空格。

*/
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

string reverseWords1(string s) {
    reverse(s.begin(), s.end());
    stringstream str(s);
    string s1;
    s.clear();
    while(str>>s1){
        reverse(s1.begin(), s1.end());
        s += s1;
        s += ' ';
    }
    s.pop_back();
    return s;
}

// 空间复杂度O(1)
string reverseWords2(string s) {
    // 反转整个string
    reverse(s.begin(), s.end());
    int len = s.size();
    int j = 0;
    int k = 0;
    for(int i=0; i<len; i++){
        // 遇到一个单词
        if(i>0&&s[i]==' '&&s[i-1]!=' '){
            k = i - 1;
            // 反转单词
            while(j<k){
                swap(s[j],s[k]);
                j++;
                k--;
            }
            // 寻找下一个单词的开始位置
            if(s[j]!=' '){
                // 不等于' '说明j在前一个单词中的某一位置
                while(s[j]!=' '){
                    j++;
                }
                j++;
            }else{
                // 等于' '说明j在前一个单词后的某一位置
                while(s[j]==' '){
                    j--;
                }
                j+=2;
            }

        }else{
            // 结尾处理
            if(i==len-1&&s[i]!=' '){
                k = i;
                while(j<k){
                    swap(s[j],s[k]);
                    j++;
                    k--;
                }
            }
        }
    }
    while(s.back()==' '){
        s.pop_back();
    }
    return s;
}

// 官方
string reverseWords(string s) {
    // 反转整个字符串
    reverse(s.begin(), s.end());

    int n = s.size();
    int idx = 0; // 新生的s的指针
    for (int start = 0; start < n; ++start) {
        // 找到一个单词了
        if (s[start] != ' ') {
            // 如果这个单词不是第一个单词，则填一个空白字符然后将idx移动到下一个单词的开头位置
            if (idx != 0) s[idx++] = ' ';

            // 循环遍历至单词的末尾
            int end = start;
            // s[idx++] = s[end++]相当于将后面的单词向前移动，结合s[start] != ' '可以将' '排除
            while (end < n && s[end] != ' ') s[idx++] = s[end++];

            // 反转整个单词
            reverse(s.begin() + idx - (end - start), s.begin() + idx);

            // 更新start，去找下一个单词
            start = end;
        }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
}


// 方法3
void removeSpace(string& s){
    int slow = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]!=' '){
            if(slow!=0) s[slow++] = ' ';
            while(i<s.size()&&s[i]!=' '){
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}

string reverseWords(string s) {
    removeSpace(s);
    reverse(s.begin(), s.end());
    int start = 0;
    for(int i=0; i<=s.size(); ++i){
        if(i==s.size()||s[i]==' '){
            reverse(s.begin()+start, s.begin()+i);
            start = i+1;
        }
    }
    return s;
}

int main(int argc, char const *argv[])
{

    string s = "hello world I Love You";
    reverse(s.begin(), s.end());
    return 0;
}
