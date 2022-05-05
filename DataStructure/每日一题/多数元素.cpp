/*
给定一个大小为 n 的数组，找到其中的多数元素。
多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

*/
#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int>mp;
    for(auto i: nums){
        mp[i]+=1;
    }
    int maxs = 0;
    int max_num = 0;
    for(auto& n: mp){
        cout<<n.first<<"  "<<n.second<<endl;
        if(n.second>maxs){
            maxs = n.second;
            max_num = n.first;
        }
    }
    return max_num;
}


int majorityElement1(vector<int>& nums) {
    int size = nums.size();
    int mystack[size]={0};
    int top=-1;
    for(auto i: nums){
        if(top==-1){
            mystack[++top] = i;
        }
        else if(i==mystack[top]){
            mystack[++top] = i;
        }else{
            top--;
        }
    }
    return mystack[0];
}

/*
如a为多于一半的元素，是a时加一，不是a时减一
*/
int majorityElement2(vector<int>& nums) {
    int cand;
    int count=0;
    int top=-1;
    for(auto i: nums){
        if(count==0){
            cand=i;
            count++;
        }
        else if(i==cand){
            count++;
        }else{
            count--;
        }
    }
    return cand;
}


int main(int argc, char const *argv[])
{
    vector<int>nums={3,2,3};
    cout<<majorityElement2(nums);
    return 0;
}
