/*

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<bool> lamp = {0,0,0,0,0,0,0,1,0,1};
    // n = 3 * k + 1;  n = 3 * k + 2 也行， 第一步 2-4 后剩两个暗灯相邻
    int n = lamp.size();

    // 先将暗灯 i 的下一个灯 i+1 按一下
    for(int i=0; i<n-2; i++){
        if(!lamp[i]){
            lamp[i] = 1;
            lamp[i+1] = !lamp[i+1];
            lamp[i+2] = !lamp[i+2];            
        }
    }
    /*
    存在四种情况：
        1. n-1, n-2 都亮 直接返回
        2-3. n-1, n-2 一亮一暗
        4. n-1, n-2 都暗, 这时需要按下 n-1  
    2-4. 后只剩一个亮灯
    */ 
    if(lamp[n-1] && lamp[n-2]){
        return true;
    }

    if(!lamp[n-1] && !lamp[n-2]){
        lamp[0] = 0;
        lamp[n-1] = 1;
        lamp[n-2] = 1;
    }

    /*
    现在只有 1 个灯亮: 1 / n-1 / n-2
    将暗灯三个一组，每次按中间的灯
    */ 
    if(lamp[0]){

    }
    else if(lamp[n-2]){

    }
    else{

    }

    // for(int i=1; i<n; i+=3) lamp[i] = 0;

    // 最后，将所有的灯都按一下，灯泡全亮

    for(bool l: lamp){
        cout<<l<<",";
    }

    return 0;
}
