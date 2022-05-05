#include<iostream>
using namespace std;



int main(int argc, char const *argv[])
{
    // 第一种创建pair的方式
    pair<string, int> p1("tom", 20);
    cout<<"name: "<<p1.first<<"\t age: "<<p1.second<<endl;

    // 第二种创建pair的方式
    pair<string, int> p2 = make_pair("jerry",20);
    cout<<"name: "<<p2.first<<"\t age: "<<p2.second<<endl;

    return 0;
}

