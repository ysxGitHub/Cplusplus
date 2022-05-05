/*
在某些特定情况下，某些函数只能在多线程环境下调用一次，比如：要初始化某个对象，
    而这个对象只能被初始化一次，就可以使用 std::call_once() 来保证函数在多线程环境下
    只能被调用一次。使用 call_once() 的时候，需要一个 once_flag 作为 call_once() 的传入参数
*/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

once_flag g_flag;
void do_once(int a, string b)
{
    cout << "name: " << b << ", age: " << a << endl;
}

void do_something(int age, string name)
{
    static int num = 1;
    call_once(g_flag, do_once, 19, "luffy");
    cout << "do_something() function num = " << num++ << endl;
}

int main()
{
    thread t1(do_something, 20, "ace");
    thread t2(do_something, 20, "sabo");
    thread t3(do_something, 19, "luffy");
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
