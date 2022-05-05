/*
设计一个类似堆栈的数据结构，将元素推入堆栈，并从堆栈中弹出出现频率最高的元素。

实现 FreqStack 类:

FreqStack() 构造一个空的堆栈。
void push(int val) 将一个整数 val 压入栈顶。
int pop() 删除并返回堆栈中出现频率最高的元素。
如果出现频率最高的元素不只一个，则移除并返回最接近栈顶的元素。

解题思路：
那么，我们仔细思考一下 push 和 pop 方法，难点如下：
    1、每次 pop 时，必须要知道频率最高的元素是什么。
    2、如果频率最高的元素有多个，还得知道哪个是最近 push 进来的元素是哪个。
为了实现上述难点，我们要做到以下几点：
    1、肯定要有一个变量 maxFreq 记录当前栈中最高的频率是多少。
    2、我们得知道一个频率 freq 对应的元素有哪些，且这些元素要有时间顺序。
    3、随着 pop 的调用，每个 val 对应的频率会变化，所以还得维持一个映射记录每个 val 对应的 freq。
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;


class FreqStack {
private:
    int maxFreq;
    unordered_map<int, stack<int>> freqToNum;
    unordered_map<int, int> numToFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {

        numToFreq[val] += 1;

        int nowfre = numToFreq[val];
        
        if(maxFreq < nowfre){
            maxFreq = nowfre;
        }
        freqToNum[nowfre].emplace(val);

    }
    
    int pop() {
        int ans;
        ans = freqToNum[maxFreq].top();
        freqToNum[maxFreq].pop();
        --numToFreq[ans];
        if(freqToNum[maxFreq].empty()){
            freqToNum.erase(maxFreq);
            // 每个数出现的频率是连续的，例如5的频率，从1->2->3->4，有4频的5，必然有3频的5，
            // maxFreq对应的不同数字的Stack为空可以，减少maxFreq--指向少一频的栈
            --maxFreq;
        }
        return ans;

    }
};

// 