
/*
thread() noexcept; // ①

thread( thread&& other ) noexcept; // ②

template< class Function, class... Args >  // ③
explicit thread( Function&& f, Args&&... args );

thread( const thread& ) = delete; // ④

构造函数①：默认构造函，构造一个线程对象，在这个线程中不执行任何处理动作

构造函数②：移动构造函数，将 other 的线程所有权转移给新的 thread 对象。之后 other 不再表示执行线程。

构造函数③：创建线程对象，并在该线程中执行函数 f 中的业务逻辑，args 是要传递给函数 f 的参数

    任务函数 f 的可选类型有很多，具体如下：
        普通函数，类成员函数，匿名函数，仿函数（这些都是可调用对象类型）
        可以是可调用对象包装器类型，也可以是使用绑定器绑定之后得到的类型（仿函数）

构造函数④：使用 =delete 显示删除拷贝构造，不允许线程对象之间的拷贝
*/


/*
2公共成员函数
2.1 get_id()
应用程序启动之后默认只有一个线程，这个线程一般称之为主线程或父线程，
    通过线程类创建出的线程一般称之为子线程，每个被创建出的线程实例都对应一个线程 ID，
    这个 ID 是唯一的，可以通过这个 ID 来区分和识别各个已经存在的线程实例，
    这个获取线程 ID 的函数叫做 get_id()

当启动了一个线程（创建了一个 thread 对象）之后，在这个线程结束的时候（std::terminate ()），
    我们如何去回收线程所使用的资源呢？thread 库给我们两种选择：
        加入式（join()）
        分离式（detach()）
另外，我们必须要在线程对象销毁之前在二者之间作出选择，否则程序运行期间就会有 bug 产生。

2.2 join()
join() 字面意思是连接一个线程，意味着主动地等待线程的终止（线程阻塞）。
    在某个线程中通过子线程对象调用 join() 函数，调用这个函数的线程被阻塞，
    但是子线程对象中的任务函数会继续执行，当任务执行完毕之后 join() 会清理当前子线程中的相关资源
    然后返回，同时，调用该函数的线程解除阻塞继续向下执行。

2.3 detach()
detach() 函数的作用是进行线程分离，分离主线程和创建出的子线程。在线程分离之后，
    主线程退出也会一并销毁创建出的所有子线程，在主线程退出之前，它可以脱离主线程继续独立的运行，
    任务执行完毕之后，这个子线程会自动释放自己占用的系统资源。
    （其实就是孩子翅膀硬了，和家里断绝关系，自己外出闯荡了，如果家里被诛九族还是会受牵连）。

注意事项：线程分离函数 detach () 不会阻塞线程，子线程和主线程分离之后，
    在主线程中就不能再对这个子线程做任何控制了，
    比如：通过 join () 阻塞主线程等待子线程中的任务执行完毕，
    或者调用 get_id () 获取子线程的线程 ID。有利就有弊，鱼和熊掌不可兼得，建议使用 join ()。

2.5 joinable()
joinable() 函数用于判断主线程和子线程是否处理关联（连接）状态，一般情况下，
    二者之间的关系处于关联状态，该函数返回一个布尔类型：
        返回值为 true：主线程和子线程之间有关联（连接）关系
        返回值为 false：主线程和子线程之间没有关联（连接）关系

有以下结论:
    在创建的子线程对象的时候，如果没有指定任务函数，那么子线程不会启动，
        主线程和这个子线程也不会进行连接
    在创建的子线程对象的时候，如果指定了任务函数，子线程启动并执行任务，
        主线程和这个子线程自动连接成功
    子线程调用了detach()函数之后，父子线程分离，同时二者的连接断开，调用joinable()返回false
    在子线程调用了join()函数，子线程中的任务函数继续执行，直到任务处理完毕，
        这时join()会清理（回收）当前子线程的相关资源，所以这个子线程和主线程的连接也就断开了，
        因此，调用join()之后再调用joinable()会返回false。

2.6 operator=
    线程中的资源是不能被复制的，因此通过 = 操作符进行赋值操作最终并不会得到两个完全相同的对象。

    // move (1)
    thread& operator= (thread&& other) noexcept;
    // copy [deleted] (2)
    thread& operator= (const other&) = delete;

通过以上 = 操作符的重载声明可以得知：
    如果 other 是一个右值，会进行资源所有权的转移
    如果 other 不是右值，禁止拷贝，该函数被显示删除（=delete），不可用
*/

/*
3. 静态函数
thread 线程类还提供了一个静态方法，用于获取当前计算机的 CPU 核心数，
    根据这个结果在程序中创建出数量相等的线程，每个线程独自占有一个CPU核心，
    这些线程就不用分时复用CPU时间片，此时程序的并发效率是最高的。
*/


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






