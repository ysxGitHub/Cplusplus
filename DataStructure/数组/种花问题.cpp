/*
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给你一个整数数组  flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false。
*/
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    if(size==1) {
        if(flowerbed[0]==1&&n>0) return 0;
        else return 1;
    }
    for(int i=0; i<size; ++i){
        if(i==0&&i+1<size&&!flowerbed[i]&&!flowerbed[i+1]){
            flowerbed[i] = 1;
            --n;
            continue;
        }
        if(i>0&&!flowerbed[i-1]&&!flowerbed[i]){
            if(i+1==size){
                flowerbed[i] = 1;
                --n;
            }else if(i+1<size&&!flowerbed[i+1]){
                flowerbed[i] = 1;
                --n;
            }
        }
    }
    return n<=0;
}