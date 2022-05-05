/*

给你一个嵌套的整数列表 nestedList 。每个元素要么是一个整数，要么是一个列表；
    该列表的元素也可能是整数或者是其他列表。请你实现一个迭代器将其扁平化，
    使之能够遍历这个列表中的所有整数。

实现扁平迭代器类 NestedIterator ：

NestedIterator(List<NestedInteger> nestedList) 用嵌套列表 nestedList 初始化迭代器。
int next() 返回嵌套列表的下一个整数。
boolean hasNext() 如果仍然存在待迭代的整数，返回 true ；否则，返回 false 。

你的代码将会用下述伪代码检测：
    initialize iterator with nestedList
    res = []
    while iterator.hasNext()
        append iterator.next() to the end of res
    return res

    **********************************************************
    NestedInteger nestedList , NestedInteger存在三个可以调用的函数
    bool NestedInteger::isInteger() const; 判断是否为整数
    int NestedInteger::getInteger() const; 得到整数
    const vector<NestedInteger> & NestedInteger::getList() const; 得到嵌套数组

*/
#include<vector>
#include<iostream>
#include<stack>
using namespace std;

class NestedInteger {
private:
    int val;
    vector<NestedInteger> list;

public: 
    NestedInteger(Integer val) {
        this->val = val;
        this->list = {};
    }

    NestedInteger(vector<NestedInteger> list) {
        this->list = list;
        this->val = INT32_MIN;
    }

    // 如果其中存的是一个整数，则返回 true，否则返回 false
    boolean isInteger() {
        return this->val != INT32_MIN;
    }

    // 如果其中存的是一个整数，则返回这个整数，否则返回 null
    int getInteger() {
        return this->val;
    }

    // 如果其中存的是一个列表，则返回这个列表，否则返回 null
    vector<NestedInteger> getList() {
        return this->list;
    }
};

class NestedIterator {
private:
    int n = 0;
    int index = 0; 
    vector<int>nums;
    void dfs(vector<NestedInteger> &nestedList){
        for(int i=0; i<nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                nums.push_back(nestedList[i].getInteger());
                n++;
            }else{
                dfs(nestedList[i].getList());
            }
        }
    }


public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    int next() {
        int tmp = nums[index++];
        return tmp;
    }
    
    bool hasNext() {
        if(index<n){
            return true;
        }else{
            return false;
        }
    }
};

//利用堆栈进行存储
class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
    }
    
    int next() {
        // 
        return stk.top().first++->getInteger();
    }
    
    bool hasNext() {
        while(!stk.empty()){
            auto& tmp = stk.top();
            if(tmp.first==tmp.second){ //达到栈尾，空栈【】
                stk.pop(); //弹出
                continue;  //进入下次循环
            }
            if(tmp.first->isInteger()){
                return true;
            }
            auto& tmplist = tmp.first++->getList(); 
            stk.emplace(tmplist.begin(), tmplist.end());
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    // stack<int>stk;
    return 0;
}
