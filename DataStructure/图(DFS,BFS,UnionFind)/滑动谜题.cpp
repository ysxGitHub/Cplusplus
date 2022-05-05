/*
在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示。
    一次 移动 定义为选择 0 与一个相邻的数字（上下左右）进行交换.

最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。

给出一个谜板的初始状态 board ，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
*/
#include<vector>
#include<queue>
#include<unordered_set>
#include<iostream>
using namespace std;


int slidingPuzzle(vector<vector<int>>& board) {
    vector<vector<int>>graph={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
    string path;
    int cnt = 0;
    unordered_set<string> seen;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            path += to_string(board[i][j]);
        }
    }
    queue<string>qs;
    qs.emplace(path);
    seen.insert(path);
    while(!qs.empty()){
        int n = qs.size();
        for(int i=0; i<n; i++){
            string cur = qs.front();
            qs.pop();
            if(cur=="123450"){
                return cnt;
            }
            int id0 = 0;
            for(id0; id0<6; id0++){
                if(cur[id0]=='0'){
                    break;
                }
            }   
            for(int id: graph[id0]){       
                swap(cur[id0], cur[id]); 
                if(!seen.count(cur)){
                    seen.insert(cur);
                    qs.emplace(cur);
                }
                swap(cur[id0], cur[id]);
            }          

        }
        cnt++;
    }

    return -1;     
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> board={{4,1,2},{5,0,3}};
    cout<<slidingPuzzle(board)<<endl;
    return 0;
}
