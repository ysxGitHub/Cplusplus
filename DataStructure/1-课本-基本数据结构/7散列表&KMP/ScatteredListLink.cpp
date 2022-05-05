#include<iostream>
#include<cstdlib>
#include<cmath>
#define MAXTABLESIZE 100000

using namespace std;

// 节点
template<class K, class V>
class LNode{
public:
    LNode(){}   
    LNode(K k, V v):Key(k), Value(v){} 
    K Key;
    V Value;
    LNode<K, V>* Parent;
    LNode<K, V>* Next;
};


template<class K, class V>
class TBNode{

public:
    TBNode(int TSize){
        // 寻找接近TSize的素数
        this->TableSize = NextPrime(TSize);
        this->Heads = new LNode<K, V>[this->TableSize];
        for(int i=0; i<this->TableSize; i++){ // 表头不装元素
            this->Heads[i].Next = NULL;
        }

    }
    TBNode(){
        this->Heads = NULL;
    }


    ~TBNode(){
        if(this->Heads!=NULL){
            LNode<K, V>* P, *tmp;
            for(int i=0; i<this->TableSize; i++){
                P = this->Heads[i].Next;
                while (P){
                    tmp = P->Next;
                    delete P;
                    P = tmp;
                }
            }
            delete[] this->Heads;
        }
    }

    LNode<K, V>* Find(K Key){
        LNode<K, V>* p;
        int pos;
        pos = this->Hash(Key, this->TableSize);
        p = this->Heads[pos].Next;
        while (p && p->Key!=Key){
            p = p->Next;
        }
        return p;
    }

    bool Insert(K Key, V Value){
        LNode<K, V>* p, *NewCell;
        int pos;

        p = this->Find(Key);
        if(!p){ // 未找到key
            NewCell = new LNode<K, V>(Key, Value);
            pos = this->Hash(Key, this->TableSize);

            NewCell->Next = this->Heads[pos].Next;

            if(this->Heads[pos].Next!=NULL){
                NewCell->Next->Parent = NewCell;        
            }
            
            this->Heads[pos].Next = NewCell;
            NewCell->Parent = &this->Heads[pos];

            return true;
        }
        else{
            return false;
        }
    }

    bool Delete(K Key){
        LNode<K, V>* p;

        p = this->Find(Key); 
        if(!p){ // 未找到key
            return false;
        }       
        else{
            if(p->Next!=NULL){
                p->Parent->Next = p->Next;
                p->Next->Parent = p->Parent;
            }else{
                p->Parent->Next = NULL;
            }
            delete p;
            return true;
        }

    }

    V operator[](K Key){
        LNode<K, V>*  Pos = this->Find(Key);
        if (Pos!=NULL){
            return Pos->Value;
        }
        else{
            cout<<"ERROR KEY! ";
            return (V)NULL;
        }
    }


private:

    LNode<K, V> * Heads; // 指向头节点的数组
    int TableSize;   // 哈希表大小 

    // 查找TableSize的下一个素数 
    int NextPrime(int N){
        int p = (N % 2) ? N + 2 : N + 1;  // 从大于 N 的下个奇数开始
        int i;
            
        while(p <= MAXTABLESIZE){
            for(i = (int)sqrt(p);i>2;i--)
                if(!(p%i))  // p 不是素数 
                    break;
            if(i==2) 
                break; 
            p += 2;  // 继续试探下个奇数 
        }
        return p;
    }

    // 哈希函数
    unsigned int Hash(K Key, int TableSize){
        unsigned int h = 0;
        while (*Key != '\0'){
            h = (h<<5) + *Key++;
        }
        return h%TableSize;   
    }


};


int main(int argc, char const *argv[])
{
    TBNode<char const *,int> ht(10);
    ht.Insert("a", 1);
    ht.Insert("b", 2);
    ht.Insert("c", 3);
    ht.Insert("d", 4);
    ht.Insert("e", 5);

    cout<<ht["e"]<<endl;

    ht.Delete("e");
    
    cout<<ht["e"]<<endl;
    return 0;
}
