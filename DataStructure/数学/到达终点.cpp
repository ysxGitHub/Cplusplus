/*
给定四个整数 sx , sy ，tx 和 ty，如果通过一系列的转换可以从起点 (sx, sy) 到达终点 (tx, ty)，
    则返回 true，否则返回 false。

从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。
*/
#include<vector>
#include<iostream>
using namespace std;

bool reachingPoints(int sx, int sy, int tx, int ty) {
    if(sx==tx&&sy==ty) return true;
    else if(tx==ty) return false;
    else{
        //每次逆推只能有tx、ty中较大值减去若干个较小值
        while(tx>0&&ty>0){
            if(tx>ty){
                //tx - sx是目标与起始值在x的差距，我们需要一次减去n * ty达到快速逼近sx的目的
                tx -= max(1, (tx-sx)/ty)*ty;
            }else{
                //ty - sy是目标与起始值在y的差距，我们需要一次减去n * tx达到快速逼近sy的目的
                ty -= max(1, (ty-sy)/tx)*tx;
            }
            if(sx==tx&&sy==ty) return true;
        }
    }
    return false;
}