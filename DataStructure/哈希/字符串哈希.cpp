/*
字符串哈希：
    即将一个字符串转化成一个整数，并保证字符串不同,得到的哈希值不同，
    这样就可以用来判断一个该字串是否重复出现过。
*/

#include<iostream>
#include<vector>
using namespace std;

typedef unsigned long long ull;

const int X = 13331;

vector<ull> h, x;

void BKDR_hash(string s){
    h[0] = s[0];
    x[0] = 1;
    for(int i=1; i<s.size(); i++){
        h[i] = h[i-1]*X + s[i];
        x[i] = x[i-1]*X;
    }
}

ull get_hash(int left, int right){
    return left ? h[right] - h[left-1]*x[right-left+1] : h[right];
}


int main(int argc, char const *argv[])
{
    string s1 = "abcdef";
    string s2 = "cd";
    ull hashcode2=0;
    for(int i=0; i<s2.size(); i++){
        hashcode2 = hashcode2*X + s2[i];
    }
    cout<<s2<<": "<<hashcode2<<endl;

    h.resize(s1.size());
    x.resize(s1.size());
    BKDR_hash(s1);
    for(int i=0; i<s1.size(); i++){
        cout<<get_hash(i, min(s1.size()-1, i+s2.size()-1))<<", ";
    }
    return 0;
}
