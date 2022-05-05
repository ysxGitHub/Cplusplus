#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int partition(vector<int>& nums, int L, int R){
    int j=L;
    int pivot = nums[R];
    for(int i=L; i<R; i++){
        if(nums[i]<pivot){
            swap(nums[i], nums[j]);
            j++;
        }
    }
    // 
    swap(nums[j], nums[R]);
    return j;
}

void QuickSort(vector<int>& nums, int L, int R){
    if(L<R){
        int m = partition(nums, L, R);
        QuickSort(nums, L, m-1);
        QuickSort(nums, m+1, R);
    }
}



int main(int argc, char const *argv[])
{
    vector<int>nums={5,1,2,6,7,0,4};
    random_shuffle(nums.begin(), nums.end());
    QuickSort(nums, 0, nums.size()-1);

    for(auto& n : nums){
        cout<<n<<" ";
    }
    return 0;
}

