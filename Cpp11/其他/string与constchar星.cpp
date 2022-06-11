#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void test(){
    {
        // a)  string转const char*
        string s = "abc";
        const char* c_s = s.c_str();
    }

    {
        // b)  const char* 转string，直接赋值即可
        const char* c_s = "abc";
        string s(c_s);
    }

    {
        // c)  string 转char*
        string s = "abc";
        char* c;
        const int len = s.length();
        c = new char[len+1];
        strcpy(c, s.c_str());
    }

    // d)  char* 转string
    char* c = "abc";
    string s(c);

    {
        // e)  const char* 转char*
        const char* cpc = "abc";
        char* pc = new char[strlen(cpc)+1];
        strcpy(pc,cpc);
    }

    {
        // f)  char* 转const char*，直接赋值即可
        char* pc = "abc";
        const char* cpc = pc;
    }
}

template<typename T, int N>
void func(T (&a)[N])
{
    a[0] = 2;
}

int main()
{
    int a[] = { 1, 2, 3 };
    func(a);
    cout << a[0] << endl;
    return 0;
}