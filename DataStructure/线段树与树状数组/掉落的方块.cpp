/*
在无限长的数轴（即 x 轴）上，我们根据给定的顺序放置对应的正方形方块。

第 i 个掉落的方块（positions[i] = (left, side_length)）是正方形，其中 left 表示该方块最左边的点位置(positions[i][0])，side_length 表示该方块的边长(positions[i][1])。

每个方块的底部边缘平行于数轴（即 x 轴），并且从一个比目前所有的落地方块更高的高度掉落而下。在上一个方块结束掉落，并保持静止后，才开始掉落新方块。

方块的底边具有非常大的粘性，并将保持固定在它们所接触的任何长度表面上（无论是数轴还是其他方块）。邻接掉落的边不会过早地粘合在一起，因为只有底边才具有粘性。

 

返回一个堆叠高度列表 ans 。每一个堆叠高度 ans[i] 表示在通过 positions[0], positions[1], ..., positions[i] 表示的方块掉落结束后，目前所有已经落稳的方块堆叠的最高高度。
*/
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> fallingSquares(vector<vector<int>>& positions) {
    vector<pair<int, pair<int, int>>>cnt;
    vector<int>ans;
    ans.push_back(positions[0][1]);
    // hight, left, right
    cnt.push_back({positions[0][1], {positions[0][0], positions[0][0]+positions[0][1]-1}});
    int maxhi = positions[0][1];
    for(int i=1; i<positions.size(); ++i){
        int left = positions[i][0], right = positions[i][0]+positions[i][1]-1;
        int maxh = 0;
        for(const auto&c: cnt){
            // 四种重叠情况
            if((right>=c.second.first&&right<=c.second.second)||(c.second.first<=left&&c.second.second>=right)||(c.second.first>=left&&c.second.second<=right)||(left>=c.second.first&&left<=c.second.second)){
                maxh = max(maxh, c.first);
            }
        }
        cnt.push_back({maxh+positions[i][1], {left, right}});
        maxhi = max(maxhi, maxh+positions[i][1]);
        ans.push_back(maxhi);
    }
    return ans;
}


