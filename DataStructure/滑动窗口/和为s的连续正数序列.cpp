/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> ans;
    int start=1, sum=0;
    for(int i = 1; i<=target/2+1; i++){
        sum += i;
        while(sum>=target){
            if(sum==target){
                vector<int>temp;
                for(int k=start; k<=i; k++){
                    temp.emplace_back(k);
                }
                ans.emplace_back(temp);
            }
            sum -= start;
            ++start;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
