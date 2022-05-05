#include <iostream>
#include <thread>
#include <atomic>
#include <functional>
#include <chrono>

using namespace std;

struct Counter {
    void increment() {
        for (int i = 0; i < 10; i++) {
            m_value++;
            cout << "increment number: " << m_value
                << ", theadID: " << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
    void decrement() {
        for (int i = 0; i < 10; i++) {
            m_value--;
            cout << "decrement number: " << m_value
                << ", theadID: " << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
    atomic_int m_value = {0};
};

int main()
{
    Counter c;
    auto increment = bind(&Counter::increment, &c);
    auto decrement = bind(&Counter::decrement, &c);
    thread t1(increment);
    thread t2(decrement);
    t1.join();
    t2.join();

    this_thread::sleep_for(chrono::seconds(5));
    return 0;
}