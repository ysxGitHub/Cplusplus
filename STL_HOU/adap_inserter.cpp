#include<iostream>
#include<vector>
#include<list>
using namespace std;


int main(int argc, char const *argv[])
{
    
    int myints[] = {10,20,30,40,50,60,70};
    vector<int> myvec(7);
    copy(myints, myints+7, myvec.begin());

    for(auto &elem: myvec){
        cout<<elem<<" ";
    }
    cout<<endl;

    list<int>foo, bar;
    for(int i=1; i<=5; i++){
        foo.push_back(i);
        bar.push_back(i*10);
    }
    list<int>::iterator it = foo.begin();
    advance(it, 3);
    // inserter中进行了“=”操作符重载, 所以将copy中的*__result = *__first变成了插入操作
    copy(bar.begin(), bar.end(), inserter(foo, it));
    for(auto &elem:foo){
        cout<<elem<<" ";
    }


    return 0;
}

