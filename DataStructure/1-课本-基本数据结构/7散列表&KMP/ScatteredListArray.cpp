/**
** 散列查找的冲突处理方法
** 开放地址法：换个位置
** 链地址法：同一位置的冲突对象组织在一起
** 
**/
#include<iostream>
#include<stdlib.h>
#include<cmath>
#define MAXTABLESIZE 100000   // 定义允许开辟的最大散列表长度
using namespace std; 


typedef enum{   // 分别对应：有合法元素、空、有已删除元素 
	Legitimate,Empty,Deleted
} EntryType;  // 定义单元状态类型 


template<class K, class V>
class Cell{
public:
	K Key;  // 键
    V Value; // 值
	EntryType Info;  // 单元状态	
};

template<class K, class V>
class HashTbl{

public:
    HashTbl(int TSize){
        this->TableSize = NextPrime(TSize);
        this->Cells = new Cell<K, V>[this->TableSize];
        if(this->Cells==NULL){
            cout<<"Memory Error!"<<endl;
        }
        for(int i=0; i<this->TableSize; i++){
            this->Cells[i].Info = Empty;
        }
    }
    HashTbl(){
        this->TableSize = 0;
        this->Cells = NULL;
    }
    ~HashTbl(){
        if(this->Cells != NULL){
            delete[] this->Cells;
            this->Cells = NULL;
        }
    }
    int Find(K Key){
        int CurrentPos, NewPos;
        int CNum=0; //记录冲突次数
        NewPos = CurrentPos = this->Hash(Key, this->TableSize);
        // 平方探测 
        while (this->Cells[NewPos].Info!=Empty && 
        this->Cells[NewPos].Key!=Key){ // 字符串类型的key要使用strcmp函数比较
            // 位置不为空且不等于该键
            /*
            *      d  1^2  -1^2  2^2  -2^2   3^2  -3^2
            *   CNum   1    2     3     4     5     6
            */ 
            if(++CNum%2){
                NewPos = CurrentPos + (CNum+1)/2 * (CNum+1)/2;
                while (NewPos>=this->TableSize){
                    NewPos -= this->TableSize;
                }  
            }else{
                NewPos = CurrentPos - CNum/2 * CNum/2;
                while (NewPos<0){
                    NewPos += this->TableSize;
                }
                
            }
        }
    return NewPos;
    }

    void Insert(K Key, V Value){
        int Pos = this->Find(Key);
        if(this->Cells[Pos].Info!=Legitimate){
            this->Cells[Pos].Info = Legitimate;
            this->Cells[Pos].Key = Key;
            this->Cells[Pos].Value = Value;
        }
    }
    void Delete(K Key){
        int Pos = this->Find(Key);
        if(this->Cells[Pos].Info!=Legitimate){
            cout<<"Delete Failure!"<<endl;
        }else{
            this->Cells[Pos].Info=Empty;
        }
    }
    V operator[](K Key){
        int Pos = this->Find(Key);
        if (this->Cells[Pos].Info==Legitimate){
            return Cells[Pos].Value;
        }
        else{
            cout<<"Error Key! ";
            return (V)NULL;
        }
    }

private:
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

    unsigned int Hash(K Key, int TableSize){
        unsigned int h = 0;
        while (*Key != '\0'){
            h = (h<<5) + *Key++;
        }
        return h%TableSize;   
    }

    Cell<K, V> * Cells; // 哈希元素
    int TableSize;   // 哈希表大小 

};


int main(int argc, char const *argv[]){

    // char a[] = "a";
    // cout<<Hash(a, 10)<<endl;
    HashTbl<char const *,int> ht(10);
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

