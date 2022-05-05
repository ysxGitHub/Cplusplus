#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_set>
#include<functional>

using namespace std;


template <typename T>
inline void hash_combine(size_t& seed, const T& val){
    seed ^= hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
};

template <typename T>
inline void hash_val(size_t& seed, const T& val){
    hash_combine(seed, val);
};

template <typename T, typename... Types>
inline void hash_val(size_t& seed, const T& val, const Types&... args){
    hash_combine(seed, val);
    hash_val(seed, args...);
};

template <typename... Types>
inline size_t hash_val(const Types&... args){
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
};


class Customer{
public:
    char * fname;
    char * lname;
    int num;
    Customer(const char * f, const char * l, const int n){
        fname = new char [strlen(f)];
        strcpy(fname, f);
        lname = new char [strlen(l)];
        strcpy(lname, l);
        num = n;
    }
    ~Customer(){
        delete[] fname;
        delete[] lname;
    }
    bool operator ==(const Customer& c) const {
        if((num==c.num)&&strcmp(fname, c.fname)&&strcmp(lname, c.lname)){
            return true;
        }
        else{
            return false;
        }
    }
};


class CustomerHash{
public:
    size_t operator()(const Customer& c) const{
        return hash_val(c.fname, c.lname, c.num);
    }

};


int main(int argc, char const *argv[])
{
    unordered_set<Customer, CustomerHash> myset;
    Customer aaa("AAA", "123", 1);
    Customer bbb("BBB", "123", 2);
    Customer ccc("CCC", "123", 3);
    Customer ddd("DDD", "123", 4);
    Customer eee("EEE", "123", 5);
    Customer fff("FFF", "123", 6);
    Customer ggg("GGG", "123", 7);
    myset.insert(aaa);
    myset.insert(bbb);
    myset.insert(ccc);
    myset.insert(ddd);
    myset.insert(eee);
    myset.insert(fff);
    myset.insert(ggg);

    cout<<"myset current bucket_count: "<<myset.bucket_count()<<endl;

    CustomerHash hh;
    cout<<"bucket position of AAA = "<<hh(aaa)%11<<endl;
    cout<<"bucket position of BBB = "<<hh(bbb)%11<<endl;
    cout<<"bucket position of CCC = "<<hh(ccc)%11<<endl;
    cout<<"bucket position of DDD = "<<hh(ddd)%11<<endl;
    cout<<"bucket position of EEE = "<<hh(eee)%11<<endl;
    cout<<"bucket position of FFF = "<<hh(fff)%11<<endl;
    cout<<"bucket position of GGG = "<<hh(ggg)%11<<endl;
    for(int i=0; i<myset.bucket_count(); i++){
        cout<<"bucket #"<<i<<" has "<<myset.bucket_size(i)<<" elements."<<endl;
    }

    return 0;
}

