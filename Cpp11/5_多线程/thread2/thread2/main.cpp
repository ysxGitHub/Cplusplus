#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void func() {
    for (int i = 0; i < 10; i++) {
        // 睡眠1s
        //this_thread::sleep_for(chrono::seconds(1));

        // 获取当前系统时间点
        auto now = chrono::system_clock::now();
        // 时间间隔为1s
        chrono::seconds sec(1);
        // 当前时间点之后睡眠 1s
        this_thread::sleep_until(now + sec);
        cout << "子线程1: " << this_thread::get_id() << ", i = " << i << endl;
    }
}

void func1() {
    for (int i = 0; i < 1000000; i++) {
        cout << "子线程2: " << this_thread::get_id() << ", i = " << i << endl;
        this_thread::yield();
    }
}

int main()
{
    cout << "主线程: " << this_thread::get_id() << endl;
    thread t(func);
    thread t1(func1);
    t.join();
    t1.join();
}