/*
爱丽丝和鲍勃拥有不同总数量的糖果。给你两个数组 aliceSizes 和 bobSizes ，aliceSizes[i] 
    是爱丽丝拥有的第 i 盒糖果中的糖果数量，bobSizes[j] 是鲍勃拥有的第 j 盒糖果中的糖果数量。

两人想要互相交换一盒糖果，这样在交换之后，他们就可以拥有相同总数量的糖果。
    一个人拥有的糖果总数量是他们每盒糖果数量的总和。

返回一个整数数组 answer，其中 answer[0] 是爱丽丝必须交换的糖果盒中的糖果的数目，
    answer[1] 是鲍勃必须交换的糖果盒中的糖果的数目。如果存在多个答案，你可以返回其中 任何一个 。题目测试用例保证存在与输入对应的答案。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int>ans;
void find(int ch, vector<int>& small, vector<int>& big){
    for(int i=0; i<small.size(); i++){
        int target = small[i]+ch;
        int left = 0, right = big.size() - 1;
        while(left<=right){
            int mid = (left + right)/2;
            if(big[mid]>target){
                right = mid - 1;
            }
            else if(big[mid]<target){
                left = mid + 1;
            }
            else if(big[mid]==target){
                ans[0] = small[i];
                ans[1] = big[mid];
                return;
            }
        }
    }
}
vector<int> fairCandySwap1(vector<int>& aliceSizes, vector<int>& bobSizes) {
    ans.resize(2,0);
    sort(aliceSizes.begin(), aliceSizes.end());
    sort(bobSizes.begin(), bobSizes.end());
    int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
    if(sum1<sum2){
        int ch = (sum2 - sum1)/2;
        find(ch, aliceSizes, bobSizes);
    }else{
        int ch = (sum1 - sum2)/2;
        find(ch, bobSizes, aliceSizes);
        swap(ans[0], ans[1]);
    }
    return ans;
}

vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    vector<int>ans(2,0);
    int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);  
    int ch = (sum2 - sum1)/2;
    unordered_set<int>bob(bobSizes.begin(), bobSizes.end());
    for(int a: aliceSizes){
        if(bob.count(a+ch)){
            ans[0] = a, ans[1] = a+ch;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
