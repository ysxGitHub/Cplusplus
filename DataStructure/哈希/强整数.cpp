/*
给定三个整数 x 、 y 和 bound ，返回 值小于或等于 bound 的所有 强整数 组成的列表 。

如果某一整数可以表示为 xi + yj ，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个 强整数 。

你可以按 任何顺序 返回答案。在你的回答中，每个值 最多 出现一次。
*/

vector<int> powerfulIntegers(int x, int y, int bound) {
    // 1 <= x, y <= 100
    // 0 <= bound <= 106
    // 0<=i<=logx(bound)
    unordered_set<int>ans;
    for(int i=0; i<20&&pow(x, i)<=bound; ++i){
        int a = pow(x, i);
        for(int j=0; j<20&&pow(y, j)<=bound; ++j){
            int b = pow(y, j);
            if(a+b<=bound){
                ans.insert(a+b);
            }
        }
    }
    return {ans.begin(), ans.end()};
}