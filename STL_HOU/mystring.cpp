#include"mystring.h"
using namespace std;


String::String(const char* cstr=0)
{
    if(cstr)
    {
        // 这里的+1是为了放入结束符
        this->m_data = new char[strlen(cstr)+1];
        strcpy(this->m_data, cstr);
    }
    else
    {
        this->m_data = new char[1];
        *this->m_data = '\0';
    }
    // cout<<"game start!"<<endl;

}

String::String(const String& str)
{
    /*
    new: 先开辟空间，再转类型，最后调用构造函数
    */ 
    this->m_data = new char[strlen(str.m_data)+1]; 
    strcpy(this->m_data, str.m_data);
}

String& String::operator=(const String& str)
{
    // 自我赋值
    if (this==&str)
    {
        return *this;
    }

    // 清空要赋值的空间, 注意：第一步自我检查和第二部清空不能互换，如果先清除后自我赋值就找不到了
    delete[] this->m_data;

    this->m_data = new char[strlen(str.m_data)+1];
    strcpy(this->m_data, str.m_data);
    return *this;
}

String::~String()
{
    // 先调用析构函数，再释放空间
    delete[] this->m_data;
    cout<<"game over!"<<endl;
}

ostream& operator<<(ostream& os, const String& str)
{
    return os<<str.get_c_str();
}

int main(int argc, char const *argv[])
{
    String s1("abc"); 
    cout<<s1<<endl;  
    String s2(s1);
    cout<<s2<<endl;
    String s3;
    s3 = s2;
    cout<<s3<<endl;

    system("pause");
    return 0;
}

