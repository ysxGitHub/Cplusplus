/*
一只蚂蚁坐在由白色和黑色方格构成的无限网格上。开始时，网格全白，蚂蚁面向右侧。每行走一步，蚂蚁执行以下操作。

(1) 如果在白色方格上，则翻转方格的颜色，向右(顺时针)转 90 度，并向前移动一个单位。
(2) 如果在黑色方格上，则翻转方格的颜色，向左(逆时针方向)转 90 度，并向前移动一个单位。

编写程序来模拟蚂蚁执行的前 K 个动作，并返回最终的网格。

网格由数组表示，每个元素是一个字符串，代表网格中的一行，黑色方格由 'X' 表示，白色方格由 '_' 表示，蚂蚁所在的位置由 'L', 'U', 'R', 'D' 表示，分别表示蚂蚁 左、上、右、下 的朝向。只需要返回能够包含蚂蚁走过的所有方格的最小矩形。
*/
#include <map>
#include <vector>
#include <iostream>
using namespace std;

const int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
const char chs[4] = {'R', 'D', 'L', 'U'};

vector<string> printKMoves(int K) {
    int x=0, y=0; // 记录当前位置
    int l=0, r=0, d=0, u=0; // 记录最大最小位置
    int flag = 0; // 记录朝向，flag++ 顺时针旋转，flag-- 逆时针旋转
    map<pair<int, int>, char>mp;
    while(K--){
        // 在白色区域种
        if(mp.count({x,y})==0||mp[{x,y}]=='_'){
            mp[{x,y}]='X';
            flag = (flag+1)%4;
            x = dirs[flag][0];
            y = dirs[flag][1];
        }
        // 在黑色区域
        else{
            mp[{x,y}]='_';
            flag = flag == 0 ? 3 : flag-1;
            x = dirs[flag][0];
            y = dirs[flag][1];
        }
        l = min(l, x);
        r = max(r, x);
        d = min(d, y);
        u = max(u, y);
    }
    vector<string>ans(r-l+1, string(u-d+1, '_'));
    for(const auto& it: mp){
        ans[it.first.first-l][it.first.second-d] = it.second;
    }
    ans[x-l][y-d] = chs[flag];
    return ans;
}

int main(int argc, char const *argv[])
{

    return 0;
}

