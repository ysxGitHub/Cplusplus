/*
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
*/

#include<iostream>
#include<vector>
using namespace std;


bool check(vector<vector<char>>& matrix, int m, int n, int i, int j, int len){
    for(int x=0; x<len; x++){
        for(int y=0; y<len; y++){
            if(x+i>=m||y+j>=n||matrix[x+i][y+j]=='0') return 0;
        }
    }
    return 1;
}
int culArea(vector<vector<char>>& matrix, int m, int n, int curlen){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(check(matrix, m, n, i, j, curlen)){
                return curlen*curlen;
            }
        }
    }
    return -1;
}

int maximalSquare1(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int right = min(m, n);
    int maxArea = 0, left = 1;
    while(left<=right){
        int mid = (left+right)/2;
        int curArea = culArea(matrix, m, n, mid);
        if(curArea==-1){
            right = mid - 1;
        }else{
            maxArea = max(maxArea, curArea);
            left = mid + 1;
        }
    }
    return maxArea;
}

// dp
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>>dp(m,vector<int>(n));
    int maxArea = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]=='1'){
                if(i==0||j==0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
            maxArea = max(maxArea, dp[i][j]*dp[i][j]);
        }
    }
    return maxArea;
}