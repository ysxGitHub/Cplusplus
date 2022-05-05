#include <iostream>
#include <cstring>
using namespace std;
using namespace __gnu_cxx;

#include <hashtable.h>
#include <ext/functional>
class eqstr{
public:
    bool operator()(const char*s1, const char*s2)
    {
        return strcmp(s1, s2)==0;
    }

};

namespace __gnu_cxx {
template<>
struct hash<string>
{
    size_t operator()(string s) const{
        return __stl_hash_string(s.c_str());
    }
};};

int main()
{
    hashtable<const char*, const char*, 
    __gnu_cxx::hash<const char*>, 
    identity<const char*>, eqstr> ht(53, __gnu_cxx::hash<const char*>(), eqstr());
    ht.insert_unique("kiwi");
    ht.insert_unique("plum");
    ht.insert_unique("apple");
    cout<<"is empty: "<<ht.empty()<<endl;
    cout<<"size: "<<ht.size()<<endl;
    cout<<"bucket count: "<<ht.bucket_count()<<endl;
    cout<<"max bucket count: "<<ht.max_bucket_count()<<endl;

    hashtable<pair<const string, int>,
    string,
    __gnu_cxx::hash<string>,
    select1st<pair<const string, int>>,
    equal_to<string>> siht(100, __gnu_cxx::hash<string>(), equal_to<string>()); 

    cout<<"size: "<<siht.size()<<endl;
    cout<<"bucket count: "<<siht.bucket_count()<<endl;
    siht.insert_unique(pair<const string, int>("jjhou", 95));
    siht.insert_unique(make_pair(string("sabrina"), 80));
    siht.insert_unique(make_pair(string("mjchan"), 85));

    cout<<"size: "<<siht.size()<<endl;
    cout<<"bucket count: "<<siht.bucket_count()<<endl;

    cout<<siht.find(string("jjhou"))->second<<endl;

    return 0;
}

