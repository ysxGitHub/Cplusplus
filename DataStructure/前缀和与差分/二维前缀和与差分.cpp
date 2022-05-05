#include<iostream>
#include<vector>
using namespace std;

void pre_sum(vector<vector<int>>& nums, vector<vector<int>>& sum_arr){

    // *nums = {{1,2,3},
    // *        {4,5,6},
    // *        {7,8,9}}
    // *sum_arr = {{1,       3,         6},
    // *           {5,  5+3-1+5=12, 6+12-3+6=21},
    // *          {12, 12+12-5+8=27, 21+27-12+9=45}}
    
    int m = nums.size(); // 行
    int n = nums[0].size(); //列
    sum_arr[0][0] = nums[0][0];
    for(int i=1; i<m; i++){
        sum_arr[i][0] = sum_arr[i-1][0] + nums[i][0];
    }
    for(int j=1; j<n; j++){
        sum_arr[0][j] = sum_arr[0][j-1] + nums[0][j];
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            sum_arr[i][j] = sum_arr[i-1][j] + sum_arr[i][j-1] - sum_arr[i-1][j-1] + nums[i][j];
        }
    }

}

int Prefix_Sum(vector<vector<int>>& sum_arr, int x1, int y1, int x2, int y2){
    if(!x1&&!y1){
        return sum_arr[x2][y2];
    }
    if(!x1){
        return (sum_arr[x2][y2] - sum_arr[x2][y1-1]);
    }
    if(!y1){
        return (sum_arr[x2][y2] - sum_arr[x1-1][y2]);
    }
    return (sum_arr[x2][y2] - sum_arr[x2][y1-1] - sum_arr[x1-1][y2] + sum_arr[x1-1][y1-1]);
}


void Difference(vector<vector<int>>& diff, int x1, int y1, int x2, int y2, int v){

    diff[x1][y1] += v;
    diff[x2+1][y1] -= v;
    diff[x1][y2+1] -= v;
    diff[x1+1][y2+1] += v;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> nums = {{1,2,3},
                        {4,5,6},
                        {7,8,9}};
    vector<vector<int>> sum_arr=nums;
    pre_sum(nums, sum_arr);

    cout<<Prefix_Sum(sum_arr, 0, 1, 1, 2)<<endl;
    cout<<Prefix_Sum(sum_arr, 1, 0, 1, 1)<<endl;
    // for(auto& ns: sum_arr){
    //     for(auto& n: ns){
    //         cout<<n<<"  ";
    //     }
    //     cout<<endl;
    // }

    // 差分 
    vector<vector<int>> diff={{0,0,0,0},
                              {0,0,0,0},
                              {0,0,0,0},
                              {0,0,0,0}};
    vector<vector<int>> sum_arr2 = diff;
    Difference(diff, 0, 0, 1, 1, 3);
    Difference(diff, 1, 0, 2, 1, 3);
    pre_sum(diff, sum_arr2);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            nums[i][j] += sum_arr2[i][j];
            cout<<nums[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}


