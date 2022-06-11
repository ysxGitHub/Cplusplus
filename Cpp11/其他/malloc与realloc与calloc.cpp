
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int*p1 = (int*)malloc(10*sizeof(int));
    int*p2 = (int*)calloc(10, sizeof(int));
    // malloc申请的空间的值是随机初始化的，calloc申请的空间的值是初始化为0的；

    // 给动态分配的空间分配额外的空间，用于扩充容量。
    realloc(p1, 20*sizeof(int));
    return 0;
}
