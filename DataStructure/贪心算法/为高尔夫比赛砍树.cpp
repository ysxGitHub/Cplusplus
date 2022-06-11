/*
你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：

0 表示障碍，无法触碰
1 表示地面，可以行走
比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。

你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。

你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。

可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。
*/

int ans = 0;
vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int cutOffTree(vector<vector<int>>& forest) {
    vector<vector<int>> data;
    for(int i = 0; i < forest.size(); ++i){
        for(int j = 0; j < forest[0].size(); ++j){
            if(forest[i][j] > 1){
                data.push_back({i, j});
            }
        }
    }

    auto com =[&](vector<int>& a, vector<int>& b){
        return forest[a[0]][a[1]] < forest[b[0]][b[1]];
    };
    sort(data.begin(), data.end(), com);
    int ai = 0, aj = 0;
    for(int i = 0; i < data.size(); ++i){
        int t = bfs(forest, ai, aj, data[i][0], data[i][1]);
        if(t == -1) return -1;
        else ans += t;
        ai = data[i][0];
        aj = data[i][1];
    }

    return ans;
}

int bfs(vector<vector<int>>& forest, int i, int j, int endi, int endj){
    if(i == endi && j == endj) return 0;
    vector<vector<int>> vis(forest.size(), vector<int>(forest[0].size(), 0));
    queue<pair<int, int>> q;
    int ret = 1;
    q.push({i, j});
    vis[i][j] = 1;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; ++i){
            pair<int, int>& temp = q.front();
            for(int j = 0; j < 4; ++j){
                int newi = temp.first + dir[j][0];
                int newj = temp.second + dir[j][1];
                if(newi == endi && newj == endj){
                    return ret;
                }
                if(newi >= 0 && newj >= 0 && newi < forest.size() && newj < forest[0].size()){
                    if(vis[newi][newj] == 0 && forest[newi][newj] >= 1){
                        q.push({newi, newj});
                        vis[newi][newj] = 1;
                    }
                }
            }
            q.pop();
        }
        ++ret;
    }
    return -1;
}