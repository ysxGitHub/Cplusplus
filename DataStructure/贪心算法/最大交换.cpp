/*
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
*/
#include<iostream>

using namespace std;

int max_char(int start, string s){
    int i=start;
    char maxc = '0';
    for(int j=start; j<s.size(); j++){
        if(s[j] >= maxc){
            maxc = s[j];
            i = j;
        }
    }
    return i;
}

int maximumSwap(int num) {
    if(num<11){return num;}
    string s = to_string(num);
    for(int i=0; i<s.size(); i++){
        int maxi = max_char(i+1, s);
        if(s[maxi]>s[i]){
            swap(s[maxi], s[i]);
            break;
        }
    }
    return stoi(s);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
