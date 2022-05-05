#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;


void solution(vector<int>& ans, int n){

}

int main(int argc, char const *argv[]){
    vector<vector<int>> n1 ={{3,7,4}, {4,5,1,10,3}};
    vector<int>nums;
    unordered_set<int>cnt;
    for(auto& n2: n1){
        for(auto&num: n2){
            if(!cnt.count(num)){
                nums.push_back(num);
                cnt.insert(num);
            }
        }
    }
    for(auto&num: nums){
        cout<<num<<", ";
    }

    return 0;
}
