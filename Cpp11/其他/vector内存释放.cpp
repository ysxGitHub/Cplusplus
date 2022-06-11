#include <vector>
#include <iostream>
using namespace std;


int test()
{
    // vector释放内存
    vector<int>vec(10, 0);
    vector<int>().swap(vec);

    return 0;
}


