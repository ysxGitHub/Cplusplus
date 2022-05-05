#include<vector>
#include<iostream>
using namespace std;

// using std::cout;
// using std::endl;

// 解决碰撞的方法：a、基于拉链法的散列表; b、基于线性探测法的散列表

template<class K, class V>
class Node{
public:
    Node(){
        key = (K)0;
        value = (V)0;
        next = NULL; 
    }
    /* data */
    K key;
    V value;
    Node<K, V>* next;
};


template<class K, class V>
class Sequential{
private:
    int Max = 10;
    Node<K, V>* begin;
    int length;
public:
    Sequential(){
        length = 0;
        begin = NULL; 
    }
    ~Sequential(){

    }
    V sfind(K key){
        if(begin==NULL){
            return -1;
        }
        Node<K, V>* currentNode = begin;
        while (currentNode){
            if(currentNode->key==key){
                break;
            }
            else{
                currentNode = currentNode->next;
            }
        }
        return currentNode->value;
    }
    bool isempty(){
        return length==0 ? true : false;
    }
    bool isfull(){
        return length==Max ? true : false;
    }
    bool sinsert(Node<K, V>* no){
        if(begin==NULL){
            begin = no;
            length++;
            return true;
        }
        else{
            if(no->key<begin->key){
                no->next = begin;
                begin = no;
                length++;
            }
            else{
                Node<K, V>* currentNode = begin->next;
                Node<K, V>* former = begin;
                while (currentNode)
                {
                    if(no->key>currentNode->key){
                        former = currentNode;
                        currentNode = currentNode->next;
                    }
                    else if(no->key<currentNode->key){
                        break;
                    }
                    else{
                        currentNode->value = no->value;
                    }
                }
                no->next = currentNode;
                former->next = no;
                length++;
            }
            return true;
        }
    }
    bool sdelete(K key){
        if(begin==NULL){
            return false;
        }
        Node<K, V>* currentNode = begin;
        Node<K, V>* formerNode = NULL;
        if(currentNode->key==key){
            begin=currentNode->next;
            return true;
        }
        else{
            formerNode = currentNode;
            currentNode = currentNode->next;
        }
        while (currentNode){
            if(currentNode->key==key){
                formerNode->next = currentNode->next;
                break;
            }
            else{
                formerNode = currentNode;
                currentNode = currentNode->next;
            }
            if(!currentNode){
                break;
            }
        }
        if(currentNode){
            return false;
        }
        else{
            return true;
        }
        
    }
    void SeqShow() const{
        Node<K, V>*currentNode = begin;
        while (currentNode)
        {
            cout<<"("<<currentNode->key<<": "<<currentNode->value<<")";
            currentNode=currentNode->next;
        }
        
    }


};

template<class K>
int hash_func(K key, int M){return int(key)%M;}

template<class K, class V>
class Scatterlist{
private:
    int M;
    Sequential<K, V>capacity[100];

public:
    Scatterlist(){
        M = 0;
    }
    ~Scatterlist(){

    }
    void setM(int m){
        M = m;
    }
    bool slinsert(Node<K, V>* no){
        int hash = hash_func<K>(no->key, M);
        return capacity[hash].sinsert(no);
    }
    bool sldelete(K key){
        int hash = hash_func(key,M);
        return capacity[hash].sdelete(key);
    }
    V slfind(K key){
        int hash = hash_func<K>(key, M);
        return capacity[hash].sfind(key);
    }
    V operator[](K key){
        return slfind(key);
    }
    void scShow() const{
        for(int i=0;i<M;i++){
            cout<<"seq"<<i+1<<": ";
            capacity[i].SeqShow();
            cout<<endl;
        }
    }

};


const int NUM = 5;
int main()
{
    Node<char, int>no[NUM];
    Scatterlist<char, int>sc;
    sc.setM(3);
    for (int i = 0; i < NUM; i++)
    {
        cout << "insert a key: ";
        cin >> no[i].key;
        cout << "insert a value:";
        cin >> no[i].value;
        sc.slinsert(&no[i]);
    }
    cout << "\'s\' value: ";
    cout << sc['s'] << endl;
    cout << "The scatter list: " << endl;
    sc.scShow();
    cout << endl;
    cout << "after deleting \'a\'" << endl;
    sc.sldelete('a');
    sc.scShow();
    cout << endl;
    system("pause");
    return 0;
}

