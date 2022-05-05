#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;




int main(int argc, char const *argv[])
{
    int i=0;
    cout<<++(++(++i))<<endl;
    // 后++复用前++，
    // cout<<(i++)++<<endl; //error

    vector<int> myvec;
    for(i=0; i<10; i++){
        myvec.push_back(i*5);
    }
    ostream_iterator<int> out_it(cout, ",");
    copy(myvec.begin(), myvec.end(), out_it);


    double value1,value2;
    cout<<endl;
    cout<<"please, insert two valies: ";
    istream_iterator<double>eos;
    // 已经开始读第一个数据了，
    istream_iterator<double>iit(cin);
    if(iit!=eos){
        value1=*iit;
    }
    ++iit;
    if(iit!=eos){
        value2=*iit;
    }    
    cout<<value1<<"*"<<value2<<"="<<(value1*value2)<<endl;
    
    vector<double>myvec1(3);
    copy(iit, eos, inserter(myvec1, myvec1.begin()));
    for(auto& elem:myvec1){
        cout<<elem<<" ";
    }

    return 0;

}
