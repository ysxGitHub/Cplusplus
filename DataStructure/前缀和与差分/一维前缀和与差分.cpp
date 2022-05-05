#include<iostream>
#include<vector>

using namespace std;

int Prefix_Sum(vector<int>& sum_arr, int m, int n){
    /*
    前缀和
        sum[m, n] = arr_sum[n] - arr_sum[m-1] m>0
        sum[0, n] = arr_sum[n] m=0;

    */ 

    if(n>=sum_arr.size()){
        return -10000;
    }
    else if(m==0){
        return sum_arr[n];
    }
    else{
        return (sum_arr[n] - sum_arr[m-1]);
    }
}

void Difference(vector<int>& diff, int l, int r, int v){
    /*
    nums[m, n]+v
        先求 arr_diff[m]+v, arr_diff[n+1]-v
        再求 arr_sum

         arr = 1, 2, 3, 4, 5, 6
    arr_diff = 1, 1, 1, 1, 1, 1  
    arr_sum  = 1, 2, 3, 4, 5, 6     
    */
    diff[l] += v;
    diff[r+1] -= v;

}


int main(int argc, char const *argv[])
{
    vector<int> nums={1,2,3,4,5,6};
    // 前缀和
    // arr = 1, 2, 3,  4, 5,  6
    // arr_sum = 1, 3, 6, 10, 15, 21    
    vector<int> sum_arr;
    sum_arr.resize(nums.size());

    sum_arr[0] = nums[0];
    for(int i=1; i<nums.size(); i++){
        sum_arr[i]  = sum_arr[i-1]+nums[i];
    }

    cout<<Prefix_Sum(sum_arr, 0, 2)<<endl;
    cout<<Prefix_Sum(sum_arr, 1, 4)<<endl;
    cout<<Prefix_Sum(sum_arr, 2, 5)<<endl;

    vector<int> nums2={1,3,7,5,2};
    // 差分 
    vector<int> diff={0,0,0,0,0,0}; //5 + 1
    Difference(diff, 2,4,5);
    Difference(diff, 1,3,2);
    Difference(diff, 0,2,-3);
    for(int i=1; i<nums2.size(); i++){
        diff[i] += diff[i-1]; 
    }
    for(int i=0; i<nums2.size(); i++){
        nums2[i] += diff[i]; 
        cout<<nums2[i]<<"  ";
    }    

    return 0;
}

