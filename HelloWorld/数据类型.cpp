#include <iostream>
using namespace std;

int main(void)
{
    /*

    ����sizeof�ؼ��ֿ���ͳ������������ռ�ڴ��С

    �������ʹ��ڵ����壺����������ķ����ڴ�
    ���ͣ�
        short 2���ֽ�(-32768~32767)
        int 4���ֽ�()
        long 4���ֽڣ�linux 4���ֽڻ�8���ֽ�
        long long 8���ֽ�
    �����ͣ�
        ������ float 4���ֽ�
        ˫���� double 8���ֽ�
        cppĬ����ʾ6λ��Ч����
    �ַ��ͣ�
        char 1���ֽ�
        ps:�����ַ��ͱ���ֻ���õ����ţ����ҵ�������ֻ����һ���ַ�
            ACSLL: A->65;a->97
    �ַ������ͣ�
            string ch = "qwqewr";  #include<string>
    bool���ͣ�
        bool 1���ֽ�

    */
    cout<<"short��ռ�ֽ�:"<<sizeof(short)<<endl;
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