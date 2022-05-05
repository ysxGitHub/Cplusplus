#include <mutex>
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;

int g_num = 0; // 为 g_num_mutex 所保护
mutex g_num_mutex;

void slow_increment(int id) {
    for (int i = 0; i < 3; i++) {
        g_num_mutex.lock();
        ++g_num;
        cout << id << " => " << g_num << endl;
        g_num_mutex.unlock();

        this_thread::sleep_for(chrono::seconds(1));
    }
}

void slow_increment1(int id) {
    for (int i = 0; i < 3; ++i) {
        // 使用哨兵锁管理互斥锁
        lock_guard<mutex> lock(g_num_mutex);
        ++g_num;
        cout << id << " => " << g_num << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

struct Calculate {
    Calculate() : m_i(6) {}

    void mul(int x) {
        // lock_guard<mutex> locker(m_mutex); // 会造成死锁
        lock_guard<recursive_mutex> loker(m_rmutex);
        m_i *= x;
    }

    void div(int x) {
        // lock_guard<mutex> locker(m_mutex); // 会造成死锁
        m_rmutex.lock();
        m_i /= x;
        m_rmutex.unlock();
    }

    void both(int x, int y) {
        // 递归调用会造成死锁
        // lock_guard<mutex> locker(m_mutex);
        lock_guard<recursive_mutex>locker(m_rmutex);
        mul(x);
        div(y);
    }

    int m_i;
    mutex m_mutex;
    recursive_mutex m_rmutex;
};


timed_mutex g_mutex;

void work() {
    chrono::seconds timeout(1);
    while (true) {
        // 通过阻塞一定的时长来争取得到互斥锁所有权
        if (g_mutex.try_lock_for(timeout)) {
            cout << "当前线程ID: " << this_thread::get_id()
                << ", 得到互斥锁所有权..." << endl;
            // 模拟处理任务用了一定的时长
            this_thread::sleep_for(chrono::seconds(10));
            // 互斥锁解锁
            g_mutex.unlock();
            break;
        } else {
            cout << "当前线程ID: " << this_thread::get_id()
                << ", 没有得到互斥锁所有权..." << endl;
            // 模拟处理其他任务用了一定的时长
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
}

int main()
{
    thread t1(slow_increment1, 0);
    thread t2(slow_increment1, 1);
    t1.join();
    t2.join();

    Calculate cal;
    cal.both(6, 3);

    thread t3(work);
    thread t4(work);

    t3.join();
    t4.join();

    return 0;
}