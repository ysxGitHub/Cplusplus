#include<cstring>
#include<iostream>
using namespace std;
typedef char* Position;

template<class T>
void Match(T pattern, int match[]){

	int i,j;
	int m = strlen(pattern);
	match[0] = -1;

	for(j=1;j<m;j++){
		i = match[j-1];
        while((i>=0) && (pattern[i+1] != pattern[j])){
            i = match[i];
        }
		if(pattern[i+1] == pattern[j]){
			match[j] = i+1;
        }
		else{
            match[j] = -1;
        } 
    }
}

template<class T>
int KMP(T str, T pattern){
    int n = strlen(str);
    int m = strlen(pattern);

    int s, p , *match;
    if(n<m){
        return -1;
    }

    match = new int[m];

    Match(pattern, match);
    
    s=p=0;

    while (s<n && p<m){
        if(str[s] == pattern[p]){
            s++;
            p++;
        }
        else if (p>0){ // 不相等时 回溯p的位置
            p = match[p-1]+1;
        }else{ // 第一个字符都不匹配
            s++;
        }
    }
    

    delete[] match;

    return (p==m) ? (s-m): -1;
}

int main(int argc, char const *argv[])
{
    // // 方法1：strstr()函数
    // char str1[] = "This is a simple example!";
    // char pattern[] = "simple";
    // Position p = strstr(str1, pattern);
    // cout<<p<<endl;

    // 方法2：
    char str1[] = "mississippi";
    char str2[] = "issip"; 
    int pos = KMP(str1, str2);
    cout<<pos<<endl;
    cout<<str1+pos<<endl;
    return 0;
}
