#include <iostream>
using namespace std;

// ����ռ 1���ֽ�
class A {};

// 32Ϊ������ ���麯������ռ 4���ֽ�
class B {
    virtual void test();
    virtual void test1();
};

// 32Ϊ������ �̳д��麯������ռ 4���ֽ�
class C :public B {

};

// 4 ���ֽ�
class D :public B {
    virtual void test2();
};

// �ڴ���� 12���ֽ�, �ǽ��������ڴ����
// �����ڴ���룬��Ҫ��Ϊ����߳�������ܣ����ݽṹ���ر���ջ��Ӧ����������Ȼ�߽��϶��룬���������cpu���ڴ�����ٶȴ��������
class E {
public:

    virtual void test();
    virtual void test1();
private:
    // bool bChild; // ˳���й� ���� 16 �ֽ�
    int age;
    bool sex;
    bool bChild;
};

int main1(int argc, char const* argv[])
{
     cout<<sizeof(A)<<endl;
     cout<<sizeof(B)<<endl;
     cout<<sizeof(C)<<endl;
     cout<<sizeof(D)<<endl;
     cout<<sizeof(E)<<endl;
     return 0;
}