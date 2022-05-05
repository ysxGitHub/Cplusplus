//Example：可以用于分割被空格、制表符等符号分割的字符串

#include<iostream>
#include<sstream>        //istringstream 必须包含这个头文件
#include<string>
#include<vector>
using namespace std;

int main(){
    string str="i am a boy";
    stringstream is(str);
    string s;
    while(is>>s)  {
        cout<<s<<endl;
    }

    // cout<<'.'-'a'<<endl; -51
}


void _split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    _split(s, delim, elems);
    return elems;
}



