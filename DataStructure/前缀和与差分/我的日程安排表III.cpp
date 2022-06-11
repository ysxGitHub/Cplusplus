/*
当 k 个日程安排有一些时间上的交叉时（例如 k 个日程安排都在同一时间内），就会产生 k 次预订。

给你一些日程安排 [start, end) ，请你在每个日程安排添加后，返回一个整数 k ，表示所有先前日程安排会产生的最大 k 次预订。

实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。

MyCalendarThree() 初始化对象。
int book(int start, int end) 返回一个整数 k ，表示日历中存在的 k 次预订的最大值。
*/

#include <map>

using namespace std;
class MyCalendarThree {
private:
    map<int, int>cnt;
public:
    MyCalendarThree() {

    }
/*
        10(+)-------20(-)
                                                                        50(+)-------60(-)
        10(+)------------------------------------------------40(-)
5(+)--------15(-)
5(+)----10(-)
                            25(+)-----------------------------------------------55(-)
*/

    int book(int start, int end) {
        int ans = 0, maxbook = 0;
        cnt[start]++;
        cnt[end]--;
        for(const auto&[_, freq]: cnt){
            maxbook+=freq;
            ans = max(ans, maxbook);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
