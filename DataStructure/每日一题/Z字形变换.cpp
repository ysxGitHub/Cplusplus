/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
*/

#include <vector>
#include <iostream>

using namespace std;

string convert1(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    vector<string> tmp(numRows);
    string ans;
    int j = 0, flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        tmp[j] += s[i];
        if (flag == 0)
        {
            j++;
        }
        else
        {
            j--;
        }
        if (j == numRows - 1)
        {
            flag = 1;
        }
        if (j == 0)
        {
            flag = 0;
        }
    }
    for (auto &ss : tmp)
    {
        ans += ss;
    }
    return ans;
}

string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    vector<string> tmp(numRows);
    string ans;
    // 周期
    int period = 2 * numRows - 2;
    for (int i = 0; i < s.size(); i++)
    {
        int mod = i % period;
        if (mod < numRows)
        {
            tmp[mod] += s[i];
        }
        else
        {
            tmp[period - mod] += s[i];
        }
    }
    for (auto &ss : tmp)
    {
        ans += ss;
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    return 0;
}
