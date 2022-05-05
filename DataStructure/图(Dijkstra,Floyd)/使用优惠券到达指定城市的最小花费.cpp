/*
有多条高速公路连接着0到n-1号的n个城市。你有一个二维数组 highways，其中 
    highways[i] = [city1i, city2i, tolli] 标识 有一条连接 city1i 到 city2i 城市的高速公路，
    如果汽车支付 tolli 的费用，可以通过高速公路到达 city2i, 反过来 city2i 到 city1i 也成立。

你还有一个已知条件 discounts 代表着你有多少优惠券。当你穿过高速公路的时候可以通过优惠券支付，
    此时仅需支付 tolli / 2 的金额（向下取整）即可通过。每张优惠券只能使用一次，
    每条高速公路只能用一张优惠券。

返回从城市 0 出发到达 城市 n-1 的最小花费， 如果没有任何可行方案，请返回 -1。

Input: 
    n = 5, highways = [[0,1,4],[2,1,3],[1,4,11],[3,2,3],[3,4,2]], discounts = 1
Output: 
    9
Explanation:
    Go from 0 to 1 for a cost of 4.
    Go from 1 to 4 and use a discount for a cost of 11 / 2 = 5.
    The minimum cost to go from 0 to 4 is 4 + 5 = 9.


Input: 
    n = 4, highways = [[1,3,17],[1,2,7],[3,2,5],[0,1,6],[3,0,20]], discounts = 20
Output: 
    8
Explanation:
    Go from 0 to 1 and use a discount for a cost of 6 / 2 = 3.
    Go from 1 to 2 and use a discount for a cost of 7 / 2 = 3.
    Go from 2 to 3 and use a discount for a cost of 5 / 2 = 2.
    The minimum cost to go from 0 to 3 is 3 + 3 + 2 = 8.


Input: 
    n = 4, highways = [[0,1,3],[2,3,2]], discounts = 0
Output: 
    -1
Explanation:
    It is impossible to go from 0 to 3 so return -1.


Constraints:
    2 <= n <= 1000
    1 <= highways.length <= 1000
    highways[i].length == 3
    0 <= city1i, city2i <= n - 1
    city1i != city2i
    0 <= tolli <= 10^5
    0 <= discounts <= 500
    There are no duplicate highways
*/

#include<vector>
#include<iostream>
#include<queue>
using namespace std;

static constexpr int INF = INT32_MIN/2;

int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
    
}