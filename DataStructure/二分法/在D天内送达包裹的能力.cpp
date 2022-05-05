/*
传送带上的包裹必须在 days 天内从一个港口运送到另一个港口。

传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量（weights）的顺序往传送带上
    装载包裹。我们装载的重量不会超过船的最大运载重量。

返回能在 days 天内将传送带上的所有包裹送达的船的最低运载能力
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int cntWeigths(vector<int>& weights, int allwei){
    int days = 0;
    int tmpwei = 0;
    for(auto&w: weights){
        tmpwei += w;
        if(tmpwei > allwei){
            days++;
            tmpwei = w;
        }
    }
    return ++days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    while(left <= right){
        int mid = left + (right - left)/2;
        int mdays = cntWeigths(weights, mid);
        if(mdays>days){
            left = mid + 1;
        }
        else if(mdays<=days){
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
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout<<shipWithinDays(weights, 3);
    return 0;
}
