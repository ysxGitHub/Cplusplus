/**

 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
    如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：
    对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
    如果 s 中存在这样的子串，我们保证它是唯一的答案。
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string minWindow(string s, string t)
{
    int ssize = s.size(), tsize = t.size();
    if (ssize < tsize){
        return "";
    }
    int left = 0, valid = 0, start = 0, minlen = INT32_MAX;
    unordered_map<char, int> wind, need;
    // 初始法需要用到的char的map
    for (auto &c : t)
        need[c]++;

    for (int right = 0; right < ssize; right++)
    {
        // right++表示移动右边界

        char c = s[right];
        // 这里不能直接使用need[c]>0，会创建不需要的字符，使need.size(变大)
        if (need.count(c))
        {
            wind[c]++;
            // 满足字符个数的需要，使valid++
            if (wind[c] == need[c])
                valid++;
        }
        // 窗口满足需要时
        // 这里是当valid满足需要的字符个数时，这里不能使用tsize，因为need里面的字符不重复
        while (valid == need.size())
        {
            // 长度是否最短
            if (right - left + 1 < minlen)
            {
                minlen = right - left + 1;
                start = left;
            }
            // 移动左边界left++
            char d = s[left];
            left++;
            // 当左边界是需要的字符时
            if (need.count(d))
            {
                // 去掉后将满足所有的需要字符
                if (wind[d] == need[d])
                    valid--;
                wind[d]--;
            }
        }
    }
    return minlen == INT32_MAX ? "" : s.substr(start, minlen);
}

int main(int argc, char const *argv[])
{
    cout<<minWindow("abcbwifh", "bcw");
    return 0;
}
