#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[2][2];

    int b[2][2] = {{1,2},
                  {3,4}};

    int c[][2] = {{1,2},
                  {3,4}};

    int d[2][2] = {1,2,3,4};

    cout<<sizeof(a)<<endl;
    cout<<sizeof(a[0])<<endl;
    cout<<sizeof(a[0][0])<<endl;
    // 行数
    cout<<sizeof(a)/sizeof(a[0])<<endl;
    // 列数
    cout<<sizeof(a[0])/sizeof(a[0][0])<<endl;

    cout<<&a[0][0]<<endl;
    cout<<a<<endl;
    cout<<a[1]<<endl;

    int score[3][3]={
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };
    string name[] = {"张三","李四","王五"};
    for(int i=0; i<3; i++)
    {
        int sum_score=0;
        for(int j=0; j<3; j++)
        {
            sum_score += score[i][j];
        }
        cout<<name[i]<<"总分数: "<<sum_score<<endl;
    }


    return 0;
}
