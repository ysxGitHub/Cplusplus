/*
给定一个二进制数组数据，返回将数组中存在的所有 1 组合到数组中任何位置所需的最小交换次数。

Input: [1,0,1,0,1]
Output: 1
Explanation: 
There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.

Input: [0,0,0,1,0]
Output: 0
Explanation: 
Since there is only one 1 in the array, no swaps needed.

Input: [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: 
One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].

Note:

1 <= data.length <= 10^5
0 <= data[i] <= 1

*/

#include <iostream>
#include <vector>
using namespace std;


int minSwaps(vector<bool>& data){
    int n = data.size();
    int cntOne = 0;
    for(int i=0; i<n; i++){
        if(data[i]) cntOne++;
    }
    int start=0, cntZero=0, ans=INT32_MAX;
    for(int i=0; i<n; i++){
        if(!data[i]) ++cntZero;

        if(i-start+1>=cntOne){
            ans = min(ans, cntZero);
            if(!data[start]) --cntZero;
            ++start;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<bool>data={0,0,0,0,0,1,1,1,1,1,1};
    cout<<minSwaps(data);
    return 0;
}
