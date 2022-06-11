#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& nums, int n, int i){
    int l = i*2, r = i*2+1;
    int maxn = i;
    if(l<n && nums[l]>nums[maxn]){
        maxn = l;
    }
    if(r<n && nums[r]>nums[maxn]){
        maxn = r;
    }
    if(maxn!=i){
        swap(nums[i], nums[maxn]);
        heapify(nums, n, maxn);
    }
}


void build_heap(vector<int>& nums, int n){
    int parent = (n-1)/2;
    for(int i=parent; i>=0; --i){
        heapify(nums, n, i);
    }
}

void heap_sort(vector<int>& nums, int n){
    build_heap(nums, n);
    for(int i=n-1; i>=0; --i){
        swap(nums[i], nums[0]);
        heapify(nums, i, 0);
    }
}


int main(int argc, char const *argv[])
{
    vector<int>nums = {3,1};
    heap_sort(nums, nums.size());
    for(auto& n: nums){
        cout<<n<<" ";
    }
    return 0;
}

