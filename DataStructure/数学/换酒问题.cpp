/*
小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。

如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。

请你计算 最多 能喝到多少瓶酒。

*/

int numWaterBottles(int numBottles, int numExchange) {
    //当前酒的数量 低于 最低限度，一瓶也换不了，最多喝 numBottles 瓶
    if( numExchange > numBottles) return numBottles;
    //如果两者相同，只能拿喝完的 空瓶 换一瓶，直接加上 1 就完事
    if( numExchange == numBottles) return numBottles + 1;

    int sumNum = numBottles; // 当前能喝 numBottles

    //其实可以假想先找老板白嫖一瓶，拿我手里有的 numExchange -1 个空瓶 + 从老板那里借来的一瓶喝完后，又换成新的一瓶，再还给老板，这样相当于 用 numExchange - 1 个空瓶就喝到了 一瓶新的酒，所以需要判断 拿到手的酒的数量 与 numExchange -1 是否是倍数关系，如果是，那么能喝的就要加上 -1，对应测试用例15  4
    if( numBottles %(numExchange-1) == 0) sumNum += -1 + numBottles /(numExchange-1);
    else{
        //不是倍数关系，直接加上就完事  对应测试用例  9  3
        sumNum += numBottles /(numExchange-1);
    }

    //返回即可
    return sumNum;
}

/*
由于换酒过程本质是：我们只在乎喝到 [酒水]

1 瓶酒 等价于 空瓶加酒水

换酒的过程需要我们必须用瓶子装酒水，而我们不能借酒瓶，3 空瓶换 1 瓶酒，本质是总保留 1 个空瓶用于装酒

2 空瓶 等价于 1 酒水

所以我们开始的 9 瓶酒 就是有 9 个空瓶，手里要保留 1 个空瓶装酒，所以用于交换的只有 8 个空瓶。而 2 个空瓶等价于 1 酒水，所以我们能换到 8/2 = 4 瓶酒水。答案就是 9+4 = 13。写成公式就是：
*/
int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + (numBottles - 1) / (numExchange - 1);
}