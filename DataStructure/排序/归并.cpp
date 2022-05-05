#include<iostream>
#include<vector>

using namespace std;

// 时间复杂度NlogN
void merge(vector<int>& nums, vector<int>& tmp, int lo, int mid, int hi){
    
    for(int i = lo; i <= hi; i++) tmp[i] = nums[i];
    
    int i = lo, j = mid + 1;
    
    for(int p = lo; p <= hi; p++){
        if(i == mid + 1){
            nums[p] = tmp[j++];
        }
        else if(j == hi + 1){
            nums[p] = tmp[i++];
        }
        else if(tmp[i] < tmp[j]){
            nums[p] = tmp[i++];
        }
        else{
            nums[p] = tmp[j++];
        }

    }
}

void sort(vector<int>& nums, vector<int>& tmp, int lo, int hi){
    if(lo==hi){
        return ;
    } 
    int mid = (lo + hi) / 2;
    sort(nums, tmp, lo, mid);
    sort(nums, tmp, mid + 1, hi);
    merge(nums, tmp, lo, mid, hi);
}

void merge_sort(vector<int>& nums){
    int size = nums.size();
    vector<int> tmp(size, 0);
    sort(nums, tmp, 0, size-1);
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {9,8,3,2,1,0,6,7,5,4};
    merge_sort(nums);
    for(auto&n : nums){
        cout<<n<<" ";
    } 
    return 0;
}
