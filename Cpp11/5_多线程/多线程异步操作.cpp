/*
多线程程序中的任务大都是异步的，主线程和子线程分别执行不同的任务

如果想要在主线中得到某个子线程任务函数返回的结果可以使用 C++11 提供的 std:future 类，
    这个类需要和其他类或函数搭配使用


常量	                    解释
future_status::deferred	子线程中的任务函仍未启动
future_status::ready	子线程中的任务已经执行完毕，结果已就绪
future_status::timeout	子线程中的任务正在执行中，指定等待时长已用完

std::promise
std::promise 是一个协助线程赋值的类，它能够将数据和 future 对象绑定起来，
    为获取线程函数中的某个值提供便利。


通过 promise 传递数据的过程一共分为 5 步：

    在主线程中创建 std::promise 对象
    将这个 std::promise 对象通过引用的方式传递给子线程的任务函数
    在子线程任务函数中给 std::promise 对象赋值
    在主线程中通过 std::promise 对象取出绑定的 future 实例对象
    通过得到的 future 对象取出子线程任务函数中返回的值。
*/

#include <iostream>
#include <thread>
#include <future>
using namespace std;



int main()
{
    // 子线程任务函数执行期间，让状态就绪
    promise<int> pr;
    thread t1([](promise<int> &p) {
        p.set_value(100);
        this_thread::sleep_for(chrono::seconds(3));
        cout << "睡醒了...." << endl;
    }, ref(pr));

    future<int> f = pr.get_future();
    int value = f.get();
    cout << "value: " << value << endl;

    t1.join();

    /*
    示例程序的中子线程的任务函数指定的是一个匿名函数，在这个匿名的任务函数执行期间通过
        p.set_value(100); 传出了数据并且激活了状态，数据就绪后，外部主线程中的
        int value = f.get(); 解除阻塞，并将得到的数据打印出来，3 秒钟之后子线程休眠结束，
        匿名的任务函数执行完毕。
    */


    // 子线程任务函数执行结束，让状态就绪
    promise<int> pr2;
    thread t2([](promise<int> &p) {
        p.set_value_at_thread_exit(100);
        this_thread::sleep_for(chrono::seconds(3));
        cout << "睡醒了...." << endl;
    }, ref(pr2));

    future<int> f2 = pr2.get_future();
    int value2 = f2.get();
    cout << "value2: " << value2 << endl;

    t2.join();
    /*
    在示例程序中，子线程的这个匿名的任务函数中通过 p.set_value_at_thread_exit(100);
        在执行完毕并退出之后才会传出数据并激活状态，数据就绪后，外部主线程中的
        int value = f.get(); 解除阻塞，并将得到的数据打印出来，因此子线程在休眠
        3 秒钟之后主线程中才能得到传出的数据。
    */
    return 0;
}
/*
在外部主线程中创建的 promise 对象必须要通过引用的方式传递到子线程的任务函数中，
    在实例化子线程对象的时候，如果任务函数的参数是引用类型，
    那么实参一定要放到 std::ref () 函数中，表示要传递这个实参的引用到任务函数中。
*/




/*
3 std::packaged_task
std::packaged_task 类包装了一个可调用对象包装器类对象
    （可调用对象包装器包装的是可调用对象，可调用对象都可以作为函数来使用）

这个类可以将内部包装的函数和 future 类绑定到一起，以便进行后续的异步调用，
    它和 std::promise 有点类似，std::promise 内部保存一个共享状态的值，
    而 std::packaged_task 保存的是一个函数。

packaged_task 其实就是对子线程要执行的任务函数进行了包装，和可调用对象包装器的使用方法相同，
    包装完毕之后直接将包装得到的任务对象传递给线程对象就可以了。
*/
int main()
{
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
/*
在上面的示例代码中，通过 packaged_task 类包装了一个匿名函数作为子线程的任务函数，
    最终的得到的这个任务对象需要通过引用的方式传递到子线程内部，
    这样才能在主线程的最后通过任务对象得到 future 对象，
    再通过这个 future 对象取出子线程通过返回值传递出的数据。
*/


/*
std::async 函数比前面提到的 std::promise 和 packaged_task 更高级一些，
    因为通过这函数可以直接启动一个子线程并在这个子线程中执行对应的任务函数，
    异步任务执行完成返回的结果也是存储到一个 future 对象中，当需要获取异步任务的结果时，
    只需要调用 future 类的get() 方法即可，如果不关注异步任务的结果，只是简单地等待任务完成的话，
    可以调用 future 类的wait()或者wait_for() 方法。


策略	                   说明
std::launch::async	    调用 async 函数时创建新的线程执行任务函数
std::launch::deferred	调用 async 函数时不执行任务函数，直到调用了 future 的 get()
                        或者 wait() 时才执行任务（这种方式不会创建新的线程）

*/

//
int main() {
    // 调用 async () 函数直接创建线程执行任务

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
        if (status == future_status::deferred)
        {
            cout << "线程还没有执行..." << endl;
            f.wait();
        }
        else if (status == future_status::ready)
        {
            cout << "子线程返回值: " << f.get() << endl;
        }
        else if (status == future_status::timeout)
        {
            cout << "任务还未执行完毕, 继续等待..." << endl;
        }
    } while (status != future_status::ready);

    /*
    调用 async() 函数时不指定策略就是直接创建线程并执行任务，示例代码的主线程中做了如下操作
        status = f.wait_for(chrono::seconds(1)); 其实直接调用 f.get() 就能得到子线程的返回值。
        这里为了给大家演示 wait_for() 的使用，所以写的复杂了些。
    */



    // 调用 async () 函数不创建线程执行任务

    cout << "主线程ID: " << this_thread::get_id() << endl;
    // 调用函数直接创建线程执行任务
    future<int> f = async(launch::deferred, [](int x) {
        cout << "子线程ID: " << this_thread::get_id() << endl;
        return x += 100;
    }, 100);

    this_thread::sleep_for(chrono::seconds(5));
    cout << f.get();

    /*
        由于指定了 launch::deferred 策略，因此调用 async() 函数并不会创建新的线程执行任务，
            当使用 future 类对象调用了 get() 或者 wait() 方法后才开始执行任务
            （此处一定要注意调用 wait_for () 函数是不行的）。

        通过测试程序输出的结果可以看到，两次输出的线程 ID 是相同的，任务函数是在主线程中被延迟
            （主线程休眠了 5 秒）调用了。
    */

    return 0;
}



/*
最终总结：
    使用 async () 函数，是多线程操作中最简单的一种方式，不需要自己创建线程对象，
        并且可以得到子线程函数的返回值。

    使用 std::promise 类，在子线程中可以传出返回值也可以传出其他数据，
        并且可选择在什么时机将数据从子线程中传递出来，使用起来更灵活。

    使用 std::packaged_task 类，可以将子线程的任务函数进行包装，并且可以得到子线程的返回值。
*/