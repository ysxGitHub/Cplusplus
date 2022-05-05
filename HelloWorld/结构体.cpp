#include<iostream>

using namespace std;

// �ṹ�壺�Զ�����������
struct Student
{
    string name;
    int classes;
    float score;
}s3;

struct Teacher
{
    string name;
    int classes;
    struct Student stu;
};


void printf_student(struct Student stu)
{
    cout<<stu.name<<" "<<stu.classes<<" "<<stu.score<<endl;
    return;
}

// �������е��βθ�Ϊָ�룬���Լ����ڴ�ռ䣬���Ҳ��Ḵ���µĸ�������ָ���׷��������������const���Է�ֹ�������
void printf_teacher(const struct Teacher *p)
{
    // p->name = "lisi"  //���ܽ����޸�
    cout<<p->name<<" "<<p->classes<<" "<<p->stu.name<<endl;
    return;
}

int main(int argc, char const *argv[])
{
    // �����ṹ�����, struct�ؼ��ֿ���ʡ��
    struct Student s1;
    s1.name = "ZhangSan";
    s1.classes = 1;
    s1.score = 78.8;
    cout<<s1.name<<" "<<s1.classes<<" "<<s1.score<<endl;

    // �����ṹ�����
    struct Student s2 = {"LiSi", 2, 80.0};
    cout<<s2.name<<" "<<s2.classes<<" "<<s2.score<<endl;

    // �����ṹ�����
    s3.name = "WangWu";
    s3.classes = 3;
    s3.score = 79.0;
    cout<<s3.name<<" "<<s3.classes<<" "<<s3.score<<endl;

    // �����ṹ������
    struct Student arr[3]={
        {"a", 1, 78.0},
        {"b", 1, 88.0},
        {"c", 1, 89.0}};

    cout<<arr[1].name<<" "<<arr[1].classes<<" "<<arr[1].score<<endl;

    // �ṹ��ָ��
    struct Student* p = &s1;
    cout<<p->name<<" "<<p->classes<<" "<<p->score<<endl;

    // �ṹ��Ƕ�׽ṹ��
    struct Teacher t1;
    t1.classes = 1;
    t1.name = "leilie";
    t1.stu = s1;

    cout<<t1.name<<" "<<t1.classes<<" "<<t1.stu.classes<<" "<<t1.stu.name<<" "<<t1.stu.score<<endl;

    // �ṹ������������
    printf_student(s2);
    printf_teacher(&t1);

    // �ṹ����const��ʹ�ó���



    return 0;
}
