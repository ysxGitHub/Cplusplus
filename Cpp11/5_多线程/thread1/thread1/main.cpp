#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void func(int num, string str)
{
    for (int i = 0; i < 10; ++i)
    {
        cout << "子线程: i = " << i << "num: "
            << num << ", str: " << str << endl;
    }
}

void func1()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << "子线程: i = " << i << endl;
    }
}

int main()
{
    cout << "主线程的线程ID: " << this_thread::get_id() << endl;
    thread t;
    cout << "before starting, joinable: " << t.joinable() << endl;
    
    t = thread(func, 520, "i love you");
    cout << "after starting, joinable: " << t.joinable() << endl;

    thread t1(func1);
    cout << "线程t 的线程ID: " << t.get_id() << endl;
    cout << "线程t1的线程ID: " << t1.get_id() << endl;
    
    t.join(); // 阻塞主线程，等待所有子线程任务执行完毕再继续向下执行
    cout << "after joining, joinable: " << t.joinable() << endl;
    
    t1.detach();
    cout << "after detaching, joinable: " << t1.joinable() << endl;

    //this_thread::sleep_for(chrono::seconds(5)); // 让主线程休眠，等待子线程执行完毕
    
    // 建议使用 join()

    // 获取当前计算机的 CPU 核心数
    int num = thread::hardware_concurrency();
    cout << "CPU number: " << num << endl;
}
