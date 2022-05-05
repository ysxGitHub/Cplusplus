/*
给你一个数组 rectangles ，其中 rectangles[i] = [li, wi] 表示第 i 个矩形的长度为 li 、宽度为 wi 。

如果存在 k 同时满足 k <= li 和 k <= wi ，就可以将第 i 个矩形切成边长为 k 的正方形。
    例如，矩形 [4,6] 可以切成边长最大为 4 的正方形。

设 maxLen 为可以从矩形数组 rectangles 切分得到的 最大正方形 的边长。

请你统计有多少个矩形能够切出边长为 maxLen 的正方形，并返回矩形 数目 。

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countGoodRectangles(vector<vector<int>>& rectangles) {
    int maxlen=0;
    unordered_map<int, int>ans;
    for(auto& rects: rectangles){
        if(rects[0]>=rects[1]){
            if(ans.find(rects[1])==ans.end()){
                ans[rects[1]] = 1;
            }else{
                ans[rects[1]] += 1;
            }
            if(maxlen<rects[1]){
                maxlen = rects[1];
            }
        }else{
            if(ans.find(rects[0])==ans.end()){
                ans[rects[0]] = 1;
            }else{
                ans[rects[0]] += 1;
            }   
            if(maxlen<rects[0]){
                maxlen = rects[0];
            }         
        }
    }
    return ans[maxlen];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> rectangles={{1,2},{3,4},{4,5},{4,7},{3,5},{4,6}};
    cout<<countGoodRectangles(rectangles)<<endl;
    return 0;
}
