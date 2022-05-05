#include<unordered_map>

using namespace std;

int maxNumberOfBalloons(string text) {
    int len = text.length();
    if(len<7){return 0;}
    
    unordered_map<char, int>Hash;
    for(int i=0; i<len; i++){
        Hash[text[i]]+=1;
    }
    int ans=100000;
    ans = min(ans,Hash['b']);
    ans = min(ans,Hash['a']);
    ans = min(ans,Hash['n']);
    ans = min(ans,Hash['l']/2);
    ans = min(ans,Hash['o']/2);
    return ans;
}