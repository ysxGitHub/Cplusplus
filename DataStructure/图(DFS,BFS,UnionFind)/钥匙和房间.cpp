/*
有 n 个房间，房间按从 0 到 n - 1 编号。最初，除 0 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。

当你进入一个房间，你可能会在里面找到一套不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。你可以拿上所有钥匙去解锁其他房间。

给你一个数组 rooms 其中 rooms[i] 是你进入 i 号房间可以获得的钥匙集合。如果能进入 所有 房间返回 true，否则返回 false。
*/

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size()-1;
    queue<vector<int>>que;
    que.push(rooms[0]);
    vector<bool>seen(n+1, 0);
    seen[0] = 1;
    while(!que.empty()){
        vector<int>cur = que.front();
        que.pop();
        for(const auto&next: cur){
            if(seen[next]) continue;
            que.push(rooms[next]);
            seen[next]=1;
        }
    }
    for(const auto&t: seen){
        if(!t) return false;
    }
    return true;
}