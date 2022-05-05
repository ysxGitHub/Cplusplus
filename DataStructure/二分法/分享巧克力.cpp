/*

你有一大块巧克力，它由一些甜度不完全相同的小块组成。我们用数组 sweetness 来表示每一小块的甜度。

你打算和 K 名朋友一起分享这块巧克力，所以你需要将切割 K 次才能得到 K+1 块，
    每一块都由一些 连续 的小块组成。

为了表现出你的慷慨，你将会吃掉 总甜度最小 的一块，并将其余几块分给你的朋友们。

请找出一个最佳的切割策略，使得你所分得的巧克力 总甜度最大，并返回这个 最大总甜度。

输入：sweetness = [1,2,3,4,5,6,7,8,9], K = 5
输出：6
解释：你可以把巧克力分成 [1,2,3], [4,5], [6], [7], [8], [9]

输入：sweetness = [5,6,7,8,9,1,2,3,4], K = 8
输出：1
解释：只有一种办法可以把巧克力分成 9 块。

输入：sweetness = [1,2,2,1,2,2,1,2,2], K = 2
输出：5
解释：你可以把巧克力分成 [1,2,2], [1,2,2], [1,2,2]。 

0 <= K < sweetness.length <= 10^4
1 <= sweetness[i] <= 10^5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int findSweet(vector<int>& sweetness, int midsweet){
    int cursweet = 0, cuts = 0;
    for(auto&sw: sweetness){
        cursweet += sw;
        if(cursweet >= midsweet){
            cuts++;
            cursweet = 0;
        }
    }
    return cuts;
}

int maximizeSweetness(vector<int>& sweetness, int k){
    int left = *min_element(sweetness.begin(), sweetness.end());
    int right = accumulate(sweetness.begin(), sweetness.end(), 0);
    if(sweetness.size() == k + 1){
        return left;
    }
    if(k==0){
        return right;
    }
    int ans = 0;
    right = right / (k+1);
    while(left<=right){
        int mid = left + (right - left)/2;
        int mk = findSweet(sweetness, mid);
        if(mk > k){
            // ?
            ans = max(ans, mid);
            left = mid + 1;
        }
        else if(mk <= k){
            right = mid - 1;
        }
        // else{
        //     right = mid - 1;
        // }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> sweetness={1,2,3,4,5,6,7,8,9};
    cout<<maximizeSweetness(sweetness, 5)<<endl;   
    return 0;
}



