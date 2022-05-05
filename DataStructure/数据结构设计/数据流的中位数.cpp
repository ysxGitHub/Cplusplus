/*
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>

using namespace std;

class MedianFinder1 {
private:
    priority_queue<int, vector<int>, greater<int>> maxpq; // (小根堆的元素较大)
    priority_queue<int, vector<int>, less<int>> minpq; // (大根堆的元素较小)
public:
    MedianFinder1() {

    }

    void addNum(int num) {
        // 当小根堆的容量大于大根堆时，先将num插入小根堆，再弹出小根堆的顶部元素，放入到大根堆中。
        if(maxpq.size()>minpq.size()){
            maxpq.emplace(num);
            minpq.emplace(maxpq.top());
            maxpq.pop();
        }else{
            minpq.emplace(num);
            maxpq.emplace(minpq.top());
            minpq.pop();
        }
    }

    double findMedian() {
        if(maxpq.size()>minpq.size()){
            return maxpq.top();
        }
        else if(maxpq.size()<minpq.size()){
            return minpq.top();
        }
        else{
            return (maxpq.top() + minpq.top()) / 2.0;
        }
    }
};

/*
当我们尝试添加一个数 num 到数据结构中，我们需要分情况讨论：
    1.初始有序集合为空时，我们直接让左右指针指向 num 所在的位置。
    2.有序集合为中元素为奇数时，left 和 right 同时指向中位数。如果 num 小于等于中位数，
    那么只要让 left 左移，否则让 right 右移即可。
    3.有序集合为中元素为偶数时，left 和 right 分别指向构成中位数的两个数。
        a.当 num 成为新的唯一的中位数，那么我们让 left 右移，right 左移，
            这样它们即可指向 num 所在的位置；
        b.当 num 大于等于 right，那么我们让 left 右移即可；
        c.当 num 小于 right 指向的值，那么我们让 right 左移，注意到如果 num 恰等于 left 指向的值，
            那么 num 将被插入到 left 右侧，使得 left 和 right 间距增大，
            所以我们还需要额外让 left 指向移动后的 right。
*/
class MedianFinder {
private:
    // multiset
    multiset<int> nums;
    multiset<int>::iterator left, right;

public:
    MedianFinder() {

    }

    void addNum(int num) {
        int n = nums.size();
        nums.insert(num);
        if(!n){
            left = right = nums.begin();
        }
        else if(n&1){
            if(num < *left){
                --left;
            }else{
                ++right;
            }
        }else{
            if(num < *right && num >= *left){
                ++left;
                --right;
            }
            else if(num >= *right){
                ++left;
            }
            else if(num < *left){
                --right;
            }

        }

    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};


int main(int argc, char const *argv[])
{

    return 0;
}
