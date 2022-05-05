/*
C++11 提供了一个原子类型 std::atomic<T>，通过这个原子类型管理的内部变量就可以称之为原子变量，
    我们可以给原子类型指定 bool、char、int、long、指针等类型作为模板参数
    （不支持浮点类型和复合类型）。

原子指的是一系列不可被 CPU 上下文交换的机器指令，这些指令组合在一起就形成了原子操作。
    在多核 CPU 下，当某个 CPU 核心开始运行原子操作时，会先暂停其它 CPU 内核对内存的操作，
    以保证原子操作不会被其它 CPU 内核所干扰。

由于原子操作是通过指令提供的支持，因此它的性能相比锁和消息传递会好很多。相比较于锁而言，
    原子类型不需要开发者处理加锁和释放锁的问题，同时支持修改，读取等操作，还具备较高的并发性能，
    几乎所有的语言都支持原子类型。

可以看出原子类型是无锁类型，但是无锁不代表无需等待，因为原子类型内部使用了 CAS 循环，
    当大量的冲突发生时，该等待还是得等待！但是总归比锁要好。

C++11 内置了整形的原子变量，这样就可以更方便的使用原子变量了。在多线程操作中，
    使用原子变量之后就不需要再使用互斥量来保护该变量了，用起来更简洁。
    因为对原子变量进行的操作只能是一个原子操作（atomic operation），
    原子操作指的是不会被线程调度机制打断的操作，这种操作一旦开始，就一直运行到结束，
    中间不会有任何的上下文切换。多线程同时访问共享资源造成数据混乱的原因就是因为 CPU
    的上下文切换导致的，使用原子变量解决了这个问题，因此互斥锁的使用也就不再需要了。

CAS 全称是 Compare and swap, 它通过一条指令读取指定的内存地址，
    然后判断其中的值是否等于给定的前置值，如果相等，则将其修改为新的值
*/

/*
构造函数 atomic()
    使用 =delete 显示删除拷贝构造函数，不允许进行对象之间的拷贝

原子类型在类内部重载了 = 操作符，并且不允许在类的外部使用 = 进行对象的拷贝。

    desired：存储到原子变量中的值
    order：强制的内存顺序

内存顺序约束

typedef enum memory_order {
    memory_order_relaxed,   // relaxed
    memory_order_consume,   // consume
    memory_order_acquire,   // acquire
    memory_order_release,   // release
    memory_order_acq_rel,   // acquire/release
    memory_order_seq_cst    // sequentially consistent
} memory_order;

memory_order_relaxed， 这是最宽松的规则，它对编译器和 CPU 不做任何限制，可以乱序

memory_order_release 释放，设定内存屏障 (Memory barrier)，保证它之前的操作永远在它之前，
    但是它后面的操作可能被重排到它前面

memory_order_acquire 获取 , 设定内存屏障，保证在它之后的访问永远在它之后，
    但是它之前的操作却有可能被重排到它后面，往往和 Release 在不同线程中联合使用

memory_order_consume：改进版的 memory_order_acquire ，开销更小

memory_order_acq_rel，它是 Acquire 和 Release 的结合，同时拥有它们俩提供的保证。
    比如你要对一个 atomic 自增 1，同时希望该操作之前和之后的读取或写入操作不会被重新排序

memory_order_seq_cst 顺序一致性， memory_order_seq_cst 就像是 memory_order_acq_rel
    的加强版，它不管原子操作是属于读取还是写入的操作，只要某个线程有用到 memory_order_seq_cst
    的原子操作，线程中该 memory_order_seq_cst 操作前的数据操作绝对不会被重新排在该
    memory_order_seq_cst 操作之后，且该 memory_order_seq_cst 操作后的数据操作也
    绝对不会被重新排在 memory_order_seq_cst 操作前。

在 C++20 版本中添加了新的功能函数，可以通过原子类型来阻塞线程，
    和条件变量中的等待 / 通知函数是一样的。

公共成员函数	              说明
wait(C++20)	        阻塞线程直至被提醒且原子值更改
notify_one(C++20)	通知（唤醒）至少一个在原子对象上阻塞的线程
notify_all(C++20)	通知（唤醒）所有在原子对象上阻塞的线程
*/

#include <iostream>
#include <thread>
#include <atomic>
#include <functional>
using namespace std;

struct Counter {
    void increment() {
        for (int i = 0; i < 10; ++i){
            m_value++;
            cout << "increment number: " << m_value
                << ", theadID: " << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

    void decrement() {
        for (int i = 0; i < 10; ++i) {
            m_value--;
            cout << "decrement number: " << m_value
                << ", theadID: " << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
    // std::atomic_int m_value(0);     // 方法 1
    // std::atomic_int m_value{0};     // 方法 2
    std::atomic_int m_value= {0};   // 方法 3
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

    return 0;
}