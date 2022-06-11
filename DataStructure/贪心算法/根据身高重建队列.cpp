/*
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
先按身高降序排列，身高相等的按排名升序排列
排序完的people： [[7,0], [7,1], [6,1], [5,0], [5,2]，[4,4]]

插入的过程：
插入[7,0]：[[7,0]]
插入[7,1]：[[7,0],[7,1]]
插入[6,1]：[[7,0],[6,1],[7,1]]
插入[5,0]：[[5,0],[7,0],[6,1],[7,1]]
插入[5,2]：[[5,0],[7,0],[5,2],[6,1],[7,1]]
插入[4,4]：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
*/

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [&](const vector<int>&a, const vector<int>&b){
        return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];
    });
    vector<vector<int>>que;
    for(int i=0; i<people.size(); ++i){
        int pos = people[i][1];
        que.insert(que.begin()+pos, people[i]);
    }
    return que;
}
