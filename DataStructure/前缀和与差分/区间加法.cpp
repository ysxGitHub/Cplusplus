/*
假设你有一个长度为 n 的数组，初始情况下所有的数字均为0，你将会被给出k个更新的操作。
    其中，每个操作会被表示为一个三元组: [startIndex, endIndex, inc]，
    你需要将子数组 A[startIndex...endIndex] (包括startlndex和endIndex)增加inc。
请你返回k次操作后的数组。
*/

#include<iostream>
#include<vector>
using namespace std;


vector<int>diff;
void Difference(int left, int right, int inc){
    diff[left] += inc;
    diff[right+1] -= inc;
}

vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    diff.resize(length, 0);
    for(int i=0; i<updates.size(); i++){
        Difference(updates[i][0], updates[i][1], updates[i][2]);
    }
    for(int i=1; i<length+1; i++){
        diff[i] += diff[i-1];
    }
    return diff;
}


int main(int argc, char const *argv[])
{
    int length = 5;
    vector<vector<int>> updates={{0,1,-1},{0,1,3}};
    vector<int>nums = getModifiedArray(5, updates);
    for(auto&n: nums){
        cout<<n<<", ";
    }
    return 0;
}
