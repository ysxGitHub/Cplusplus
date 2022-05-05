/*
设计并实现一个 TwoSum 的类，使该类需要支持 add 和 find 的操作。
    add 操作 - 对内部数据结构增加一个数。
    find 操作 - 寻找内部数据结构中是否存在一对整数，使得两数之和与给定的数相等。
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class TwoSum{
    unordered_map<int, int>hash;
public:

    void add(int number) {
        hash[number]++;
    }

    bool find(int value) {
        for(int i=0; i<=value/2; i++){
            if(i==value-i){
                if(hash.count(i)!=0&&hash[i]==2){
                    return true;
                }
                continue;
            }
            if(hash.count(i)!=0&&hash.count(value-i)!=0){
                return true;
            }
        }
        return false;
    }

};

int main(int argc, char const *argv[])
{
    TwoSum ts;
    ts.add(1);
    ts.add(3);
    ts.add(5);
    cout<<ts.find(4)<<endl;
    cout<<ts.find(5)<<endl;
    ts.add(1);
    cout<<ts.find(2)<<endl;
    return 0;
}
