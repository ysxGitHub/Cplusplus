#ifndef __MYSTRING__
#define __MYSTRING__

#include<iostream>
#include<cstring>


class String
{
public:
    // 
    String(const char*);
    // 拷贝构造
    String(const String&);
    // 赋值
    String& operator=(const String&);
    // 析构
    ~String();

    char* get_c_str() const
    {
        return m_data;
    }
private:
    char* m_data;
};

#endif