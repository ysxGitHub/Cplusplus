/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
    如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，
    则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

#include<unordered_map>
#include<iostream>
using namespace std;

struct Node{
    int key, value;
    Node* next, *pre;
    Node(){};
    Node(int k, int v) : key(k), value(v), next(nullptr), pre(nullptr) {};
};

class List{
private:
    Node* head=nullptr, *tail = nullptr;
public:
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }

    void insert(Node* node){
        node->next = tail;
        node->pre = tail->pre;
        tail->pre->next = node;
        tail->pre = node;
    }

    void remove(Node* node){
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }

    int removeHead(){
        if(head->next==tail) return -1;
        int key = head->next->key;
        remove(head->next);
        return key;
    }

};



class LRUCache {
private:
    unordered_map<int, Node*> keyToNode;
    List cache;
    int capacity;
    int size;
public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }

    int get(int key) {
        if(keyToNode.count(key)==0){
            return -1;
        }
        Node* cur = keyToNode[key];
        cache.remove(cur);
        cache.insert(cur);
        return cur->value;
    }

    void put(int key, int value) {
        if(keyToNode.count(key)!=0){
            Node* cur = keyToNode[key];
            cache.remove(cur);
            cur->value = value;
            cache.insert(cur);
        }else{
            if(size==capacity){
                keyToNode.erase(cache.removeHead());
                size--;
            }
            Node* cur = new Node(key, value);
            cache.insert(cur);
            keyToNode[key] = cur;
            size++;
        }
    }
};


int main(int argc, char const *argv[])
{
    // ["LRUCache","get","put","get","put","put","get","get"]
    // [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
    LRUCache lru(2);
    cout<<lru.get(2)<<endl;
    lru.put(2,6);
    cout<<lru.get(1)<<endl;
    lru.put(1,5);
    lru.put(1,2);
    cout<<lru.get(1)<<endl;
    cout<<lru.get(2)<<endl;
    return 0;
}
