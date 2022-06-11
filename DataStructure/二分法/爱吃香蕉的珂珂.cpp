/*
珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，
    将在 H 小时后回来。

珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。
    如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// f(x)  注意：double x 很重要
int countH(vector<int>& piles, double x){
    int ans=0;
    for(auto&p: piles){
        ans += ceil(p/x);
    }
    return ans;
}

int minEatingSpeed(vector<int>& piles, int h) {
    if(piles.size()==1){return ceil(piles[0] / (double)h); }

    //二分左边界
    int left = 1;
    int right = 1000000000;
    while(left<=right){
        int mid = left + (right - left)/2;
        int mh = countH(piles, mid);
        if(mh>h){
            left = mid + 1;
        }
        else if(mh<=h){
            right = mid - 1;
        }
        // else{
        //     right = mid - 1;
        // }
    }
    return left;
}


int main(int argc, char const *argv[])
{
    vector<int> piles = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    int h = 823855818;
    cout<<minEatingSpeed(piles, h)<<endl;

    return 0;
}
