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

class compareNum
{
public:
    bool operator()(int a, int b)
    {
        return a>b;
    }
};

void print(int a)
{
    cout<<a<<" ";
}
// sort  random_shuffle  reverse
void test01()
{
    vector<int>v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(3);
    v1.push_back(4);

    // 降序
    cout<<"drop sort: ";
    sort(v1.begin(), v1.end(), compareNum());
    printAll<vector<int>>(v1);

    // 打乱
    cout<<"shuffle: ";
    random_shuffle(v1.begin(), v1.end());
    printAll<vector<int>>(v1);

    // 反转
    cout<<"reverse: ";
    reverse(v1.begin(), v1.end());
    printAll<vector<int>>(v1);

    // 降序
    cout<<"drop sort: ";
    sort(v1.begin(), v1.end(), greater<int>());
    for_each(v1.begin(), v1.end(), print);
    cout<<endl;


}

// merge 合并两个容器到第三个容器中，注意 两个容器必须是有序的
void test02()
{
    vector<int>v1;
    vector<int>v2;

    for(int i=0; i<6; i++)
    {
        v1.push_back(i);
        v2.push_back(i);
    }

    vector<int>v3;
    // 目标容器必须要先开辟空间
    v3.resize(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    printAll<vector<int>>(v3);


}


int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    test01();

    test02();

    return 0;
}



