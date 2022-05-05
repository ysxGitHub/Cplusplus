/*
在 C++11 中不仅添加了线程类，还添加了一个关于线程的命名空间 std::this_thread，
    在这个命名空间中提供了四个公共的成员函数，通过这些成员函数就可以对当前线程进行相关的操作了。
*/

// 1. get_id()
// 调用命名空间 std::this_thread 中的 get_id() 方法可以得到当前线程的线程 ID

// 2. sleep_for()
/*
同样地线程被创建后也有这五种状态：创建态，就绪态，运行态，阻塞态(挂起态)，退出态(终止态) 。

线程和进程的执行有很多相似之处，在计算机中启动的多个线程都需要占用 CPU 资源，
    但是 CPU 的个数是有限的并且每个 CPU 在同一时间点不能同时处理多个任务。
    为了能够实现并发处理，多个线程都是分时复用CPU时间片，快速的交替处理各个线程中的任务。
    因此多个线程之间需要争抢CPU时间片，抢到了就执行，抢不到则无法执行
    （因为默认所有的线程优先级都相同，内核也会从中调度，不会出现某个线程永远抢不到 CPU 时间片的情况）。

命名空间 this_thread 中提供了一个休眠函数 sleep_for()，
    调用这个函数的线程会马上从运行态变成阻塞态并在这种状态下休眠一定的时长，
    因为阻塞态的线程已经让出了 CPU 资源，代码也不会被执行，所以线程休眠过程中对 CPU
    来说没有任何负担。这个函数是函数原型如下，参数需要指定一个休眠时长，是一个时间段：
*/

// 3. sleep_until()
/*
    sleep_until()：指定线程阻塞到某一个指定的时间点 time_point类型，之后解除阻塞
    sleep_for()：指定线程阻塞一定的时间长度 duration 类型，之后解除阻塞
*/

// 4. yeild()
/*
命名空间 this_thread 中提供了一个非常绅士的函数 yield()，在线程中调用这个函数之后，
    处于运行态的线程会主动让出自己已经抢到的 CPU 时间片，最终变为就绪态，
    这样其它的线程就有更大的概率能够抢到 CPU 时间片了。使用这个函数的时候需要注意一点，
    线程调用了 yield () 之后会主动放弃 CPU 资源，但是这个变为就绪态的线程会马上参与到下一轮 CPU
    的抢夺战中，不排除它能继续抢到 CPU 时间片的情况，这是概率问题。
*/


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
