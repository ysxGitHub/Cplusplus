#include<iostream>

using namespace std;

// 结构体：自定义数据类型
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

// 将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本。但指针易发生误操作，加上const可以防止误操作。
void printf_teacher(const struct Teacher *p)
{
    // p->name = "lisi"  //不能进行修改
    cout<<p->name<<" "<<p->classes<<" "<<p->stu.name<<endl;
    return;
}

int main(int argc, char const *argv[])
{
    // 创建结构体变量, struct关键字可以省略
    struct Student s1;
    s1.name = "ZhangSan";
    s1.classes = 1;
    s1.score = 78.8;
    cout<<s1.name<<" "<<s1.classes<<" "<<s1.score<<endl;

    // 创建结构体变量
    struct Student s2 = {"LiSi", 2, 80.0};
    cout<<s2.name<<" "<<s2.classes<<" "<<s2.score<<endl;

    // 创建结构体变量
    s3.name = "WangWu";
    s3.classes = 3;
    s3.score = 79.0;
    cout<<s3.name<<" "<<s3.classes<<" "<<s3.score<<endl;

    // 创建结构体数组
    struct Student arr[3]={
        {"a", 1, 78.0},
        {"b", 1, 88.0},
        {"c", 1, 89.0}};

    cout<<arr[1].name<<" "<<arr[1].classes<<" "<<arr[1].score<<endl;

    // 结构体指针
    struct Student* p = &s1;
    cout<<p->name<<" "<<p->classes<<" "<<p->score<<endl;

    // 结构体嵌套结构体
    struct Teacher t1;
    t1.classes = 1;
    t1.name = "leilie";
    t1.stu = s1;

    cout<<t1.name<<" "<<t1.classes<<" "<<t1.stu.classes<<" "<<t1.stu.name<<" "<<t1.stu.score<<endl;

    // 结构体做函数参数
    printf_student(s2);
    printf_teacher(&t1);

    // 结构体中const的使用场景



    return 0;
}
