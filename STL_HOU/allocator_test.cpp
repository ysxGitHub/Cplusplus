#include<iostream>
#include<list>
#include<ctime>
using namespace std;

#include<ext\array_allocator.h>
#include<ext\mt_allocator.h>
#include<ext\debug_allocator.h>
#include<ext\pool_allocator.h>
#include<ext\bitmap_allocator.h>
#include<ext\malloc_allocator.h>
#include<ext\new_allocator.h>


void test_list_with_special_allocator()
{
    cout<<"\ntest_list_with_special_allocator()........"<<endl;

    list<string, allocator<string>> c1;
    list<string, __gnu_cxx::malloc_allocator<string>> c2;
    list<string, __gnu_cxx::new_allocator<string>> c3;
    list<string, __gnu_cxx::__pool_alloc<string>> c4;
    list<string, __gnu_cxx::__mt_alloc<string>> c5;
    list<string, __gnu_cxx::bitmap_allocator<string>> c6;

    int choice;
    long value;
    cout<<"select: ";
    cin>>choice;
    if(choice!=0)
    {
        cout<<"how many elements: ";
        cin>>value;
    }
    char buf[10];
    clock_t timeStrat = clock();
    for(long i=0; i<value; i++)
    {
        try{
            snprintf(buf, 10, "%d", i);
            switch (choice)
            {
            case 1:
                c1.push_back(string(buf));
                break;
            case 2:
                c2.push_back(string(buf));
                break;
            case 3:
                c3.push_back(string(buf));
                break;
            case 4:
                c4.push_back(string(buf));
                break;
            case 5:
                c5.push_back(string(buf));
                break;
            case 6:
                c6.push_back(string(buf));
                break;
            default:
                break;
            }
        }
        catch(exception& p)
        {
            cout<<"i= "<<i<<p.what()<<endl;
            abort();
        }
    }
    cout<<"a lot of push_back(), milli-seconds: "<<(clock()-timeStrat)<<endl;

}

// 直接使用分配器, 不建议直接使用
void test_use_allocator()
{
    int* p;
    allocator<int> alloc1;
    p = alloc1.allocate(1);
    alloc1.deallocate(p, 1);

    __gnu_cxx::malloc_allocator<int> alloc2;
    p = alloc2.allocate(1);
    alloc2.deallocate(p, 1);

    // .......

}

int main(int argc, char const *argv[])
{
    test_list_with_special_allocator();
    return 0;
}


// 容器自带有sort()时用自身携带的，algorithm中sort()并不适用于所有的容器排序，
// 因为algorithm中sort()中指针是跳动的，如sp+5，这样就不适用于链表排序

