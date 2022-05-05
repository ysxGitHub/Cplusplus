/*
图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，
    平滑处理后单元格的值为该单元格的平均灰度。

每个单元格的  平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。
    （即，需要计算蓝色平滑器中 9 个单元格的平均值）。

如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格
    （即，需要计算红色平滑器中 4 个单元格的平均值）。

*/
#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int m = img.size(), n = img[0].size();
    vector<vector<int>>ans(m, vector<int>(n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int cnt = 0, sum = 0;
            for(int a=i-1; a<=i+1; a++){
                for(int b=j-1; b<=j+1; b++){
                    if(a>=0&&a<m&&b>=0&&b<n){
                        cnt++;
                        sum+=img[a][b];
                    }
                }
            }
            ans[i][j] = sum/cnt;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
