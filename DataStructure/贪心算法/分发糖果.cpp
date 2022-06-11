/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：
    每个孩子至少分配到 1 个糖果。
    相邻两个孩子评分更高的孩子会获得更多的糖果。

请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
*/

/*
思路

规则定义： 设学生 AA 和学生 BB 左右相邻，A 在 B 左边；
左规则： 当 ratings_B>ratings_A 时，B 的糖比 A 的糖数量多。
右规则： 当 ratings_A>ratings_B 时，A 的糖比 B 的糖数量多。

相邻的学生中，评分高的学生必须获得更多的糖果 ！！！等价于！！！所有学生满足左规则且满足右规则。
*/
#include<vector>
#include<iostream>
#include<numeric>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int>candies(n, 1);
    for(int i=1; i<n; i++){
        if(ratings[i]>ratings[i-1])
            candies[i] = candies[i-1] + 1;
    }
    for(int i=n-2; i>=0;i--){
        if(ratings[i]>ratings[i+1])
            candies[i] = max(candies[i], candies[i+1]+1);
    }
    return accumulate(candies.begin(), candies.end(), 0);
}