/*
我们构建了一个包含 n 行( 索引从 1  开始 )的表。首先在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。

例如，对于 n = 3 ，第 1 行是 0 ，第 2 行是 01 ，第3行是 0110 。
给定行数 n 和序数 k，返回第 n 行中第 k 个字符。（ k 从索引 1 开始）
*/
#include <vector>
using namespace std;

// 超时
int kthGrammar(int n, int k) {
    vector<int> lastrow(1 << n, 0);
    for (int i = 1; i < n; ++i) {
        for (int j = (1 << (i-1)) - 1; j >= 0; --j) {
            lastrow[2*j] = lastrow[j];
            lastrow[2*j+1] = 1 - lastrow[j];
        }
    }
    return lastrow[k-1];
}

int kthGrammar(int n, int k) {
    if(n==1) return 0;
    return (~k&1)^kthGrammar(n-1, (k+1)/2);
}
/*
观察下面的规律，把每一行对半分开

1、0
2、0 | 1
3、01 | 10
4、0110 | 1001
5、01101001 | 10010110
6、0110100110010110 | 1001011001101001

发现每一行的前半段就是上一行，后半段就是上一行的每个值反过来（0变1，1变0）

可以分为两种情况
如果K在前半段，所对应的值就是上一行的第K个值
如果K在后半段，可以先算出K相对于后半段的位置，然后找出上一行这个位置的值，把值反过来
*/
int kthGrammar(int n, int k){
    if(n==1) return 0;
    // 当前行的长度
    int length = 1<<(n-1);
    // 如果K大于长度的一半，就是K所在位置是后半段
    if(k>length/2){
        // 先得到上一行的值，位置是K相对于后半段的位置
        int val = kthGrammar(n-1, k-length/2);
        return val==0?1:0;
    }else{
        // 值就是上一行K位置的值
        return kthGrammar(n - 1, k);
    }
}
