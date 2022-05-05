/*
实现RandomizedSet 类：
    RandomizedSet() 初始化 RandomizedSet 对象
    bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
    bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
    int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。
        每个元素应该有 相同的概率 被返回。

你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

思路：
    如何结合哈希表和数组，使得数组的删除操作时间复杂度也变成 O(1)
*/
#include<vector>
#include<unordered_map>
#include<iostream>
#include<ctime>
using namespace std;


class RandomizedSet {
private:
    unordered_map<int, int>hash;
    vector<int>v;
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        if(hash.count(val)==0){
            v.emplace_back(val);
            hash[val] = v.size();
            return true;

        }else{
            return false;
        }
    }

    bool remove(int val) {
        if(hash.count(val)==0){
            return false;
        }else{
            int idx = hash[val];
            int last = v.back();
            v[idx] = last;
            hash[last] = idx;
            v.pop_back();
            hash.erase(val);
            return true;
        }
    }

    int getRandom() {
        return v[rand()%v.size()];
    }
};

int main(int argc, char const *argv[])
{
    RandomizedSet rs;
    rs.insert(10);
    rs.insert(9);
    cout<<rs.getRandom();
    return 0;
}
