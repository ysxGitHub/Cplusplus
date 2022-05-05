#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<ctime>

template<class T>
void printAll(const T& vp)
{
    for(class T::const_iterator it=vp.begin(); it!=vp.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}


class greaterTwo
{
public:
    bool operator()(int a)
    {
        return a>2;
    }

};

// copy replace swap
void test01()
{
    vector<int>v1;
    vector<int>v2;

    for(int i=0; i<6; i++)
    {
        v1.push_back(i);
    }

    // copy
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    printAll<vector<int>>(v2);

    // 替换
    replace(v1.begin(), v1.end(), 5, 0);
    printAll<vector<int>>(v1);

    // 按条件替换
    replace_if(v1.begin(), v1.end(), greaterTwo(), 7);
    printAll<vector<int>>(v1);

    // 交换
    swap(v1,v2);
    printAll<vector<int>>(v1);
}

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    test01();

    // test02();

    return 0;
}
