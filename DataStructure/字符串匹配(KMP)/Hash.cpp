/*
unsigned long long hash_code; 
mod = 2^64; p=131, 1331, 13331, 
当hash code的类型为unsigned long long时溢出会自己取模
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const long long mod = 101, p=131;


long long getHash(long long l, long long r, vector<long long> hash_code){
    return l == 0 ? hash_code[r] : ((hash_code[r] - hash_code[l -1] * (long long)pow(p, (r - l + 1))) % mod + mod) % mod;
}

vector<long long> getAllHash(string s){
    vector<long long> hash_code;
    hash_code.emplace_back(s[0]-'a'+1);
    for (int i = 1; i < s.length(); i++){
        // long long tmp = (hash_code[i -1]*p + s[i])% mod;
        // cout<<tmp<<"  ";
        hash_code.emplace_back((hash_code[i -1]*p + s[i]-'a'+1)% mod);
    }
    // cout<<endl;
    return hash_code;
}   

long long getOneHash(string substr1){
    long long hashcode=0;
    hashcode = substr1[0]-'a'+1;
    for (int i =1; i< substr1.length(); i++){
        hashcode = (hashcode*p + substr1[i]-'a'+1)% mod;
    }
    return hashcode;
}

int main(void){
    string s = "abcbadb";
    string c = "bc";
    cout<<getOneHash(c)<<endl;
    vector<long long> hash_code = getAllHash(s);
    for(int i=0; i<s.length(); i++){    
        cout<<getHash(i, min(s.length()-1, c.length()+i-1), hash_code)<<"  ";
    }
    return 0;
}