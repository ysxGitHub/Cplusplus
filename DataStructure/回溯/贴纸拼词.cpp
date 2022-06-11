/*
我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。

您想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母并重新排列它们。如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。

返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1 。

注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的，并且 target 被选择为两个随机单词的连接。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int ans = 16; //存放答案
int num = 0; //记录已经使用的贴纸数
vector<pair<string, int>>seen;

void solve(vector<string>& stickers, string& left){
    if(left == ""){ //成功贴出,且num<answer(在上一层控制)
        ans = num;
    }
    if(num>=ans-1){ //如果num>=answer-1,最终答案不会比answer小,终止搜索
        return ;
    }
    for(auto&sticker: stickers){
        if(sticker.find(left[0])!=sticker.npos){
            string s = sticker, copy = left; //拷贝sticker和left
            int pos = 0;
            for(int i=0; i<left.size(); ++i){ //删除left中能用s贴的所有字母
                if((pos=s.find(left[i]))!=s.npos){
                    s.erase(pos,1);
                    left.erase(i,1);
                    --i;
                }
            }
            ++num; //贴纸数+1
            if(find(seen.begin(), seen.end(), (pair<string, int>){left, num})==seen.end()){
                seen.push_back({left, num});
                solve(stickers, left);
            }
            left = copy; //回溯至原状态
            --num;
        }
    }
}

int minStickers(vector<string>& stickers, string target) {
    solve(stickers, target);
    return ans==16?-1:ans; //answer==16说明没找到
}
int main(int argc, char const *argv[])
{
    string s = "abcdef";
    string t = "abcdef";


    return 0;
}
