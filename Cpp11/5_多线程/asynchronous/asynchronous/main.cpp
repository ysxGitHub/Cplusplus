#include <thread>
#include <future>
#include <iostream>
using namespace std;

int main1()
{
    // 子线程任务函数执行期间，让状态就绪
    promise<int> pr;
    thread t1([](promise<int>& p) {
        p.set_value(10);
        this_thread::sleep_for(chrono::seconds(3));
        cout << "睡醒了......" << endl;
        }, ref(pr));
    future<int> f = pr.get_future();
    int value = f.get();
    cout << "value: " << value << endl;
    t1.join();

    // 子线程任务函数执行结束，让状态就绪
    promise<int> pr2;
    thread t2([](promise<int>& p) {
        p.set_value_at_thread_exit(100);
        this_thread::sleep_for(chrono::seconds(3));
        cout << "睡醒了...." << endl;
        }, ref(pr2));

    future<int> f2 = pr2.get_future();
    int value2 = f2.get();
    cout << "value2: " << value2 << endl;

    t2.join();

    this_thread::sleep_for(chrono::seconds(2));
    return 0;
}

int main2() {
    packaged_task<int(int)> task([](int x) {
        return x += 100;
        });

    thread t1(ref(task), 100);

    future<int> f = task.get_future();
    int value = f.get();
    cout << "value: " << value << endl;
    t1.join();

    return 0;
}

int main() {
    cout << "主线程ID: " << this_thread::get_id() << endl;
    // 调用函数直接创建线程执行任务
    future<int> f = async([](int x) {
        cout << "子线程ID: " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::seconds(5));
        return x += 100;
        }, 100);
    future_status status;
    do {
        status = f.wait_for(chrono::seconds(1));
        if (status == future_status::deferred) {
            cout << "线程还没执行......" << endl;
        }
        else if (status == future_status::ready) {
            cout << "子线程返回值......" << f.get() << endl;
        }
        else if (status == future_status::timeout) {
            cout << "任务还没执行完毕，继续等待......" << endl;
        }

    } while (status != future_status::ready);
    
    // 调用函数直接创建线程执行任务
    cout << "主线程ID: " << this_thread::get_id() << endl;
    future<int> f2 = async(launch::deferred, [](int x) {
            cout << "子线程ID: " << this_thread::get_id() << endl;
            return x += 100;
        }, 100);
    cout << "主线程开始休眠3秒...: " << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << f2.get();

    this_thread::sleep_for(chrono::seconds(5));
    return 0;
}