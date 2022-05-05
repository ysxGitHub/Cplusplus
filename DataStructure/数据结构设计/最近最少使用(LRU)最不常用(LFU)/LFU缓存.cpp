/*
请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

实现 LFUCache 类：

LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 -1 。
void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。
    当缓存达到其容量 capacity 时，则应该在插入新项之前，移除最不经常使用的项。
    在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近最久未使用 的键。
为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。

当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get
    或 put 操作，使用计数器的值将会递增。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

#include<unordered_map>
#include<iostream>
#include<list>
// #include<unordered_set>
using namespace std;


class LFUCache1 {
private:
    // key to value
    unordered_map<int, int>keyVal;
    // key to freq
    unordered_map<int, int>keyFre;
    // freq to keys
    unordered_map<int, list<int>>freKeys;
    int capacity;
    int minFreq;
    int size;

public:

    void delMinFre() {
        // freq 最小的 key 列表
        // 其中最先被插入的那个 key 就是该被淘汰的 key
        int deletedKey = freKeys[minFreq].front();
        /* 更新 FK 表 */
        freKeys[minFreq].erase(freKeys[minFreq].begin());
        if(freKeys[minFreq].size()==0){
            freKeys.erase(minFreq);
        }
        /* 更新 KV 表 */
        keyVal.erase(deletedKey);
        /* 更新 KF 表 */
        keyFre.erase(deletedKey);
    }

    void increaseFreq(int key) {
        int freq = keyFre[key];
        /* 更新 KF 表 */
        keyFre[key] += 1;
        /* 更新 FK 表 */
        // 将 key 从 freq 对应的列表中删除
        freKeys[freq].remove(key);
        // 将 key 加入 freq + 1 对应的列表中
        if(freKeys.find(freq+1)!=freKeys.end()){
            freKeys[freq+1].emplace_back(key);
        }else{
            list<int> ls;
            ls.emplace_back(key);
            freKeys[freq+1] = ls;
        }
        // 如果 freq 对应的列表空了，移除这个 freq
        if (freKeys[freq].size()==0) {
            freKeys.erase(freq);
            // 如果这个 freq 恰好是 minFreq，更新 minFreq
            if (freq == minFreq) {
                minFreq++;
            }
        }
    }

    LFUCache1(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        size = 0;
    }

    int get(int key) {
        if(keyVal.find(key)==keyVal.end()){
            return -1;
        }
        // 增加key的频率
        increaseFreq(key);
        return keyVal[key];
    }

    void put(int key, int value) {
        if(capacity<=0){
            return;
        }
        if(keyVal.find(key)!=keyVal.end()){
            keyVal[key] = value;
            increaseFreq(key);
            return;
        }
        if(capacity==size){
            delMinFre();
        }
        keyVal[key] = value;
        keyFre[key] = 1;

        if(freKeys.find(1)!=freKeys.end()){
            freKeys[1].emplace_back(key);
        }else{
            list<int>tmpls;
            tmpls.emplace_back(key);
            freKeys[1] = tmpls;
        }

        if(capacity!=size){
            size++;
        }
        minFreq = 1;

    }
};


//****************************************************************************//

class Node{
public:
    int key, value, freq;
    Node* next, * pre;
    Node();
    Node(int k, int v):key(k),value(v),freq(1),pre(nullptr),next(nullptr){};
};

class NodeList{

public:
    Node* tail,* head;
    NodeList(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
};


class LFUCache{
private:
    int size;
    int capacity;
    int minFreq;
    unordered_map<int, Node*>key2Node;
    unordered_map<int, NodeList>freq2List;

    void deleteNode(Node* node){
        // key2Node.erase(node->key); // 这里不能删除，真正删除在deleteHead
        node->pre->next = node->next;
        node->next->pre = node->pre;
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if(freq2List[minFreq].head->next==freq2List[minFreq].tail){
            freq2List.erase(minFreq);
            if(minFreq==node->freq){
                minFreq+=1;
            }
        }
    }

    void insertTail(Node* node){
        int freq = node->freq;
        node->next = freq2List[freq].tail;
        node->pre = freq2List[freq].tail->pre;
        freq2List[freq].tail->pre->next = node;
        freq2List[freq].tail->pre = node;
    }

    void deleteMinFreq(int minFreq){
        Node* node = freq2List[minFreq].head->next;
        node->pre->next = node->next;
        node->next->pre = node->pre;
        key2Node.erase(node->key);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        size = 0;
    }
    int get(int key) {
        if(key2Node.count(key)==0){
            return -1;
        }
        Node* node = key2Node[key];
        deleteNode(node);
        node->freq+=1;
        insertTail(node);
        return node->value;
    }
    void put(int key, int value) {
        if(capacity==0){
            return ;
        }
        if(key2Node.count(key)!=0){
            Node* node = key2Node[key];
            deleteNode(node);
            node->freq +=1;
            node->value = value;
            insertTail(node);
        }else{
            if(capacity==size){
                deleteMinFreq(minFreq);
                size--;
            }
            Node* node = new Node(key, value);
            key2Node[key] = node;
            insertTail(node);
            minFreq = 1;
            size++;
        }

    }
};




int main(int argc, char const *argv[])
{
    /*
    ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get",
        "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]

    ["LFUCache","put","put","put","put","get"]
    [[2],[3,1],[2,1],[2,2],[4,4],[2]]
    */

    LFUCache lfu(2);
    lfu.put(1,1);
    lfu.put(2,2);
    cout<<lfu.get(1)<<endl;
    // cout<<lfu.get(1)<<endl;
    // cout<<lfu.get(1)<<endl;
    // cout<<lfu.get(2)<<endl;
    // cout<<lfu.get(2)<<endl;
    lfu.put(3,3);
    cout<<lfu.get(2)<<endl;
    cout<<lfu.get(3)<<endl;
    lfu.put(4,4);
    cout<<lfu.get(1)<<endl;
    cout<<lfu.get(3)<<endl;
    cout<<lfu.get(4)<<endl;
    // lfu.put(3,1);
    // lfu.put(2,1);
    // lfu.put(2,2);
    // lfu.put(4,4);
    // cout<<lfu.get(2)<<endl;

    return 0;
}
