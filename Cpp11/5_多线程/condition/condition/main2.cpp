#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <functional>
#include <condition_variable>
using namespace std;

class SyncQueue {
public:
    SyncQueue(int size) :m_maxSize(size) {}

    void put(const int& x) {
        unique_lock<mutex> locker(m_mutex);
        // 判断任务队列是不是满了
        
        //while (m_queue.size() == m_maxSize) {
        //    cout << "任务队列已满，请耐心等待....." << endl;
        //    m_notFull.wait(locker); // 阻塞线程
        //}
    
        // or
        // 根据条件阻塞线程
        m_notFull.wait(locker, [this]() {
            return m_queue.size() != m_maxSize;
            });
        // 
        m_queue.push_back(x);
        cout << x << " 被生产" << endl;
        // 通知消费者去消费
        m_notEmpty.notify_one();
    }
    int take() {
        unique_lock<mutex> locker(m_mutex);

        //while (m_queue.size()) {
        //    cout << "任务队列已空， 请耐心等待......" << endl;
        //    m_notEmpty.wait(locker);
        //}
        
        // or
        // 不为空是继续往下进行
        m_notEmpty.wait(locker, [this]() {
            return !m_queue.empty();
            });

        // 
        int x = m_queue.front();
        m_queue.pop_front();
        //
        m_notFull.notify_one();
        cout << x << " 被消费" << endl;
        return x;
    }
    bool empty() {
        lock_guard<mutex> locker(m_mutex);
        return m_queue.empty();
    }
    bool full() {
        m_mutex.lock();
        return m_queue.size() == m_maxSize;
	       m_mutex.unlock();
    }
    int size() {
        lock_guard<mutex> locker(m_mutex);
        return m_queue.size();
    }

private:
    list<int> m_queue;
    mutex m_mutex;
    condition_variable m_notEmpty; // 不为空的条件变量
    condition_variable m_notFull; // 没有满的条件变量
    int m_maxSize;
};


int main1()
{
    SyncQueue taskQ(50);
    auto produce = bind(&SyncQueue::put, &taskQ, placeholders::_1);
    auto consume = bind(&SyncQueue::take, &taskQ);
    thread t1[3];
    thread t2[3];
    for (int i = 0; i < 3; i++) {
        t1[i] = thread(produce, i + 1);
        t2[i] = thread(consume);
    }
    for (int i = 0; i < 3; i++) {
        t1[i].join();
        t2[i].join();
    }
    return 0;
}