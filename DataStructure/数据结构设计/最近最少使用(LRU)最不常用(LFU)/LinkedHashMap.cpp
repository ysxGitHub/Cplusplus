/*
STL六大组件
    1.容器
    2.算法
    3.迭代器：扮演算法与容器之间的胶合剂
    4.仿函数：作为算法的某种策略
    5.适配器：一种用来修饰容器或仿函数或迭代器接口的东西
    6.配置器：负责空间的配置与管理
*/
/*
LinkedHashMap: 双向链表+哈希表
    双向链表中存放实际的key/value对
    哈希表中存放key到双向链表中的相应位置迭代器的映射
这么设计的目的是，在插入和遍历时，可以利用利用双向链表的灵活性，进行随机地插入元素，
    同时因其迭代器永不失效，所以可以作为哈希表中的value；
    查找时可以利用哈希表的特性，基于关键字key做平均常数时间复杂度的快速查找。
*/
#include<iostream>
#include<list>
#include<unordered_map>
#include<assert.h>
#include<cstring>
// using namespace std;



template<class KeyType, class MappedType,
         class Hash = std::hash<KeyType>,
         class Pred = std::equal_to<KeyType>>
class LinkedHashMap{
public:
    // 保存的entry的类型
    typedef std::pair<const KeyType, MappedType> EntryType;
    // list中的非const迭代器
    typedef typename std::list<EntryType>::iterator iterator;
    // list中的const迭代器
    typedef typename std::list<EntryType>::const_iterator const_iterator;

    /*
    * @brief 在map中插入一个新的entry
    * @param [in] new——entry : 待添加的entry
    */
    std::pair<iterator, bool> insert(const EntryType& new_entry){
        _map_itr pIt = _map_key2entry.find(new_entry.first);
        if(pIt == _map_key2entry.end()) {
            _values.push_back(new_entry);
            _map_key2entry.insert(std::pair<KeyType, iterator>(new_entry.first, --_values.end()));
            _size++;
        }else{
            _values.erase(pIt->second);
            _values.push_back(new_entry);
            pIt->second = --_values.end();
        }
        return std::pair<iterator, bool>(--_values.end(), true);
    }

    /*
    * @brief 在map中指定位置插入一个新的entry
    * @param [in] new——entry : 待添加的entry
    * @note since c++11
    */
    iterator insert(const_iterator it, const EntryType& new_entry){
        _map_itr pIt = _map_key2entry.find(new_entry.first);
        if(pIt != _map_key2entry.end()){
            _values.erase(pIt->second);
            --_size;
        }
        iterator _it = _values.insert(it, new_entry);
        _map_key2entry.insert(std::pair<KeyType, iterator>(new_entry.first, _it));
        ++_size;
        return _it;
    }

    /*
    * @brief 获取首元素的迭代器
    * @param [in] null
    * @note
    */
    inline iterator begin(){
        return _values.begin();
    }

    /*
    * @brief 获取首元素的const迭代器
    * @param [in] null
    * @note
    */
    inline const_iterator begin() const {
        return _values.begin();
    }

    /*
    * @brief 获取尾元素的迭代器
    * @param [in] null
    * @note
    */
    inline iterator end(){
        return _values.end();
    }

    /*
    * @brief 获取尾元素的const迭代器
    * @param [in] null
    * @note
    */
    inline const_iterator end() const {
        return _values.end();
    }

    /*
    * @brief 返回entries的数量
    * @param [in] null
    * @note
    */
    inline size_t size() const {
        return _size;
    }

    /*
    * @brief 在map中查找元素，如果存在返回其迭代器，否则返回end()
    * @param [in] key : 指定的键值
    * @note
    */
    iterator find(const KeyType& key){
        if(_size > 0){
            _map_itr it = _map_key2entry.find(key);
            if(it == _map_key2entry.end()){
                return _values.end();
            }
            iterator find_it = it->second;
            return find_it;
        }
        return _values.end();
    }

    /*
    * @brief find() const 版本
    * @param [in] key : 指定的键值
    * @note
    */
    const_iterator find(const KeyType& key) const {
        if(_size > 0){
            _map_citr it = _map_key2entry.find(key);
            if(it == _map_key2entry.end()){
                return _values.end();
            }
            const_iterator find_it = it->second;
            return find_it;
        }
        return _values.end();
    }

    /*
    * @brief 移除位于pos处的entry
    * @param [in] pos : 指定位置的迭代器
    * @note
    */
    void erase(iterator pos){
        assert(pos != _values.end());
        assert(_size != 0);

        EntryType v = *pos;
        _values.erase(pos);
        _map_key2entry.erase(v.first);
        --_size;
    }
    /*
    * @brief 移除指定键值的entry
    * @param [in] key : 指定的键值
    * @note
    */
    void erase(const KeyType& key){
        iterator it = find(key);
        if(it != _values.end()){
            erase(it);
        }
    }

    /*
    * @brief 清空所有的entry
    * @param [in] null
    * @note
    */
    void clear(){
        _values.clear();
        _map_key2entry.clear();
        _size = 0;
    }

    /*
    * @brief 获取该map是否为空
    * @param [in] null
    * @note
    */
    inline bool empty() const{
        return _values.empty();
    }


private:
    typedef std::unordered_map<KeyType, iterator, Hash, Pred> HashMap;
    typedef typename HashMap::iterator _map_itr;
    typedef typename HashMap::const_iterator _map_citr;
    // entry的数量
    size_t _size;
    // 实际存放entry的双向链表
    std::list<EntryType> _values;
    // 保存key到entry的hashmap
    HashMap _map_key2entry;
};

/*
3.4 使用注意事项
std::hash 和 std::equal_to 针对大多数类型都是可以正常工作的，
    其中 std::hash 针对所有C++标准类型都有其响应的特化版本，但是没有对 C 字符串的特化。
     std::hash<const char*> 产生指针值（内存地址）的哈希，它不检验任何字符数组的内容。
     所以在使用字符指针这种比较特征的类型时，如果想要其按照字符指针所指向的字符串的内容来进行哈希
     和比较的话，需要定义自己的哈希functor Hash 和比较functor Pred :
*/
struct MyHash{
    std::size_t operator()(const char* s) const{
        std::hash<std::string> str_hasher;
        std::size_t h1 = str_hasher(s);
        return h1;
    }
};

struct StrEqual{
    bool operator()(const char *val1, const char *val2) const {
        return strcmp(val1, val2) == 0;
    }

};


int main(int argc, char const *argv[])
{

    return 0;
}
