#include <iostream>
using namespace std;

int main(void)
{
    /*

    利用sizeof关键字可以统计数据类型所占内存大小

    数据类型存在的意义：给变量合理的分配内存
    整型：
        short 2个字节(-32768~32767)
        int 4个字节()
        long 4个字节，linux 4个字节或8个字节
        long long 8个字节
    浮点型：
        单精度 float 4个字节
        双精度 double 8个字节
        cpp默认显示6位有效数字
    字符型：
        char 1个字节
        ps:创建字符型变量只能用单引号，而且单引号中只能有一个字符
            ACSLL: A->65;a->97
    字符串类型：
            string ch = "qwqewr";  #include<string>
    bool类型：
        bool 1个字节

    */
    cout<<"short所占字节:"<<sizeof(short)<<endl;
    double f1 = 3.1415926535;
    float f2 = 1e-8;
    cout<<f1<<" "<<f2<<endl;
    char a = 'a';
    cout<<a<<" "<<(int)a<<endl;
    char st1[] = "qwrertert";
    cout<<st1<<endl;
    bool flag = true;
    cout<<flag<<endl;


    return 0;

}