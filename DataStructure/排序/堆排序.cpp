#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& nums, int s, int n){
    int imax = n;
    int c1 = n*2+1;
    int c2 = n*2+2;
    if((c1 < s) && (nums[imax]<nums[c1])){
        // swap(nums[imax], nums[c1]);
        imax = c1;
    }
    if((c2 < s) && (nums[imax]<nums[c2])){
        // swap(nums[imax], nums[c2]);
        imax = c2;
    }
    if(imax!=n){
        swap(nums[imax], nums[n]);
        heapify(nums, s, imax);
    }
}


void build_heap(vector<int>& nums){
    int last_index = nums.size() - 1;
    int parent = (last_index-1)/2;
    for(int i=parent; i>=0; i--){
        heapify(nums, last_index+1, i);
    }
}

void HeapSort(vector<int>& nums){
    build_heap(nums);
    for(int i=nums.size()-1; i>=0; i--){
        swap(nums[i], nums[0]);
        heapify(nums, i, 0);
    }
}


int main(int argc, char const *argv[])
{
    vector<int>nums = {3,1};
    HeapSort(nums);
    for(auto& n: nums){
        cout<<n<<" ";
    }
    return 0;
}

