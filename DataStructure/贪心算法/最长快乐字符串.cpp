/*
如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。

给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：

s 是一个尽可能长的快乐字符串。
s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
s 中只含有 'a'、'b' 、'c' 三种字母。
如果不存在这样的字符串 s ，请返回一个空字符串 ""。

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


string longestDiverseString(int a, int b, int c) {
    string ans;
    vector<pair<int, char>> arr= {{a, 'a'},{b, 'b'},{c, 'c'}};
    while(1){
        // 排序->降序
        sort(arr.begin(), arr.end(), [](const pair<int, char>&a, const pair<int, char>&b){
            return a.first > b.first;
        });
        // 标记是否添加完所有的元素
        bool flag = 0;
        for(auto&a : arr){
            int size = ans.size();
            // 判断是否还可以添加
            if(size>=2&&ans[size-1]==a.second&&ans[size-2]==a.second){
                continue;
            }
            if(a.first>0){
                ans += a.second;
                a.first--;
                flag=1;
                // 添加最多的元素后，跳出
                break;
            }
        }
        // 所有的元素添加完成
        if(flag==0){
            break;
        }

    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout<<longestDiverseString(2,2,7)<<endl;
    return 0;
}
