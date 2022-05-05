/*
请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。

实现 AllOne 类：

AllOne() 初始化数据结构的对象。
inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，
    那么插入计数为 1 的 key 。
dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，
    那么需要将这个 key 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
*/
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<iostream>
#include<map>
using namespace std;


class AllOne {
private:
    list<pair<unordered_set<string>, int>> ls;
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> nodes;
public:
    AllOne() {

    }

    void inc(string key) {
        // key 存在时
        if(nodes.count(key)){
            auto cur = nodes[key], nxt = next(cur);
            // key 的下一个 为空 或 key 的下一个 出现的次数大于 key 出现次数的 + 1,
            if(nxt == ls.end() || nxt->second > cur->second + 1){
                unordered_set<string> s({key});
                // 直接在 key 后面新建一个节点
                nodes[key] = ls.insert(nxt, make_pair(s, cur->second + 1));
            }else{
                // 否则 直接将 key 存入下一个节点中
                nodes[key] = nxt;
                nxt->first.insert(key);
            }
            // 删除 key 的原来位置
            cur->first.erase(key);
            if(cur->first.empty()){
                ls.erase(cur);
            }
        }else{
            // 链表为空 或 链表的开始次数大于 1 时
            if(ls.empty() || ls.begin()->second > 1){
                unordered_set<string> s({key});
                // 直接插入头部
                ls.emplace_front(s, 1);
            }else{
                // 否则 插入对应的位置
                ls.begin()->first.emplace(key);
            }
            nodes[key] = ls.begin();
        }

    }

    void dec(string key) {
        auto cur = nodes[key];
        // 当前 key 为一
        if(cur->second == 1){
            // 直接删除该 key
            nodes.erase(key);
        }else{
            auto pre = prev(cur);
            // 如果当前 key 为头节点 或 key 的 前一个 出现的频率小于 key出现次数 - 1;
            if(cur == ls.begin() || pre->second < cur->second - 1){
                unordered_set<string> s({key});
                // 直接在 key 的前面插入新的节点
                nodes[key] = ls.insert(cur, make_pair(s, cur->second - 1));
            }else{
                // 否则, 插入现有的位置
                nodes[key] = pre;
                pre->first.insert(key);
            }
        }
        // 删除 key 的原来位置
        cur->first.erase(key);
        if(cur->first.empty()){
            ls.erase(cur);
        }
    }

    string getMaxKey() {
        return ls.empty() ? "" : *ls.rbegin()->first.begin();
    }

    string getMinKey() {
        return ls.empty() ? "" : *ls.begin()->first.begin();
    }
};



int main(int argc, char const *argv[])
{
    return 0;
}



struct Node{
    string s;
    int freq;
    Node*pre, *next;
    Node(string key) : s(key), freq(0), pre(nullptr), next(nullptr){}
};

class AllOne {
private:
    map<string, Node*>str2Node;
    vector<pair<Node*, Node*>> freq2Node; // pair<head, tail>
    Node*head, *tail;

private:
    void insert(Node* cur, Node* tar){
        cur->next = tar->next;
        cur->pre = tar;
        tar->next->pre = cur;
        tar->next = cur;
        auto&[a, b] = freq2Node[cur->freq];
        if(!a&&!b){ // 如果头尾都为空，
            a = b = cur;
        }else{ // 否则 放入头部
            a = cur;
        }
    }
    void remove(Node* cur){
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        auto&[a, b] = freq2Node[cur->freq];
        if(a==cur&&b==cur){ // 该节点为头尾
            a = b = nullptr;
        }else if(a==cur){ // 该节点为头
            a = cur->next;
        }else if(b==cur){ // 该节点为尾
            b = cur->pre;
        }
    }

public:
    AllOne() {
        freq2Node.resize(50002);
        head = freq2Node[0].second = new Node("");
        tail = freq2Node.back().first = new Node("");
        head->next = tail;
        tail->pre = head;
    }

    void inc(string key) {
        Node*cur = str2Node.count(key) ? str2Node[key] : new Node(key);
        if(cur->freq){
            remove(cur);
            cur->freq++;
            if(freq2Node[cur->freq-1].second){ //上一个频率 的尾 不为空
                // 位于该频率的节点不止一个
                insert(cur, freq2Node[cur->freq-1].second);
            }else{ // 否则放原位置
                insert(cur, cur->pre);
            }

        }else{ // 频率为零直接插入起始位置
            cur->freq++;
            insert(cur, head);
            str2Node[key] = cur;
        }
    }

    void dec(string key) {
        Node* cur = str2Node[key];
        remove(cur);
        if(cur->freq==1){
            str2Node.erase(key); // 移除key
            delete cur;
        }else{
            cur->freq--;  // 频率--
            if(freq2Node[cur->freq].first){ // 该频率的节点不为空，插入该频率的头部
                insert(cur, freq2Node[cur->freq].first->pre);
            }else{ // 否则放原位置
                insert(cur, cur->pre);
            }
        }
    }

    string getMaxKey() {
        return tail->pre->s;
    }

    string getMinKey() {
        return head->next->s;
    }
};


