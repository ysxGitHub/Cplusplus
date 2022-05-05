/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/

#include<vector>
#include<iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    int mut = m*n;
    int row_down=0, col_down=0, row_up=m-1, col_up=n-1;
    int i;
    while(ans.size()<=mut){
        /*
        (0,0)(0,1)(0,2)
        (1,0)(1,1)(1,2)
        (2,0)(2,1)(2,2)
        */
        for(i=col_down; i<=col_up; i++){
            // cout<<"a "<<row_down<<","<<i<<"; ";
            ans.emplace_back(matrix[row_down][i]);
        }
        row_down++;
        for(i=row_down; i<=row_up; i++){
            // cout<<"b "<<i<<","<<col_up<<"; ";
            ans.emplace_back(matrix[i][col_up]);
        }
        col_up--;
        for(i=col_up; i>=col_down; i--){
            // cout<<"c "<<row_up<<","<<i<<"; ";
            ans.emplace_back(matrix[row_up][i]);
        }        
        row_up--;
        for(i=row_up; i>=row_down; i--){
            // cout<<"d "<<i<<","<<col_down<<"; ";
            ans.emplace_back(matrix[i][col_down]);
        }          
        col_down++;
        if(row_down>row_up){
            break;
        }
        // cout<<row_down<<","<<row_up<<","<<col_down<<","<<col_up<<"; ";

    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>>nums={{1,2,3},{5,6,7},{9,10,11}};
    vector<int>ans = spiralOrder(nums);
    for(auto&n: ans){
        cout<<n<<' ';
    }
    return 0;
}
