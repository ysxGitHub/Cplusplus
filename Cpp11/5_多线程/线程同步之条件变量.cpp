/*
条件变量是 C++11 提供的另外一种用于等待的同步机制，它能阻塞一个或多个线程，
    直到收到另外一个线程发出的通知或者超时时，才会唤醒当前阻塞的线程。
    条件变量需要和互斥量配合起来使用，C++11 提供了两种条件变量：

    condition_variable：需要配合 std::unique_lock<std::mutex> 进行 wait 操作，
        也就是阻塞线程的操作。

    condition_variable_any：可以和任意带有 lock()、unlock() 语义的 mutex 搭配使用，
        也就是说有四种：

    std::mutex：独占的非递归互斥锁
    std::timed_mutex：带超时的独占非递归互斥锁
    std::recursive_mutex：不带超时功能的递归互斥锁
    std::recursive_timed_mutex：带超时的递归互斥锁

条件变量通常用于生产者和消费者模型，大致使用过程如下：

    拥有条件变量的线程获取互斥量

    循环检查某个条件，如果条件不满足 阻塞当前线程，否则线程继续向下执行
        产品的数量达到上限，生产者阻塞，否则生产者一直生产。。。
        产品的数量为零，消费者阻塞，否则消费者一直消费。。。

    条件满足之后，可以调用 notify_one() 或者 notify_all() 唤醒一个或者所有被阻塞的线程
        由消费者唤醒被阻塞的生产者，生产者解除阻塞继续生产。。。
        由生产者唤醒被阻塞的消费者，消费者解除阻塞继续消费。。。
*/

/*
condition_variable
    condition_variable 的成员函数主要分为两部分：线程等待（阻塞）函数 和线程通知（唤醒）函数

调用 wait() 函数的线程会被阻塞

如果线程被该函数阻塞，这个线程会释放占有的互斥锁的所有权，
    当阻塞解除之后这个线程会重新得到互斥锁的所有权，继续向下执行。

wait_for() 函数和 wait() 的功能是一样的，只不过多了一个阻塞时长，
    假设阻塞的线程没有被其他线程唤醒，当阻塞时长用完之后，线程就会自动解除阻塞，继续向下执行。

wait_until() 函数和 wait_for() 的功能是一样的，它是指定让线程阻塞到某一个时间点，
    假设阻塞的线程没有被其他线程唤醒，当到达指定的时间点之后，线程就会自动解除阻塞

notify_one()：唤醒一个被当前条件变量阻塞的线程
notify_all()：唤醒全部被当前条件变量阻塞的线程

独占的互斥锁对象不能直接传递给 wait() 函数，需要通过模板类 unique_lock 进行二次处理

条件变量 condition_variable 类的 wait() 还有一个重载的方法，可以接受一个条件，
    这个条件也可以是一个返回值为布尔类型的函数，条件变量会先检查判断这个条件是否满足，
    如果满足条件（布尔值为true），则当前线程重新获得互斥锁的所有权，结束阻塞，继续向下执行；
    如果不满足条件（布尔值为false），当前线程会释放互斥锁（解锁）同时被阻塞，等待被唤醒。
*/

/*
condition_variable_any

condition_variable_any 的成员函数也是分为两部分：线程等待（阻塞）函数 和线程通知（唤醒）函数，
    这些函数被定义于头文件 <condition_variable>


可以直接传递给 wait() 函数的互斥锁类型有四种，分别是：
    std::mutex、std::timed_mutex、std::recursive_mutex、std::recursive_timed_mutex

如果线程被该函数阻塞，这个线程会释放占有的互斥锁的所有权，
    当阻塞解除之后这个线程会重新得到互斥锁的所有权，继续向下执行。

wait_for() 函数和 wait() 的功能是一样的，只不过多了一个阻塞时长，
    假设阻塞的线程没有被其他线程唤醒，当阻塞时长用完之后，线程就会自动解除阻塞，继续向下执行。

wait_until() 函数和 wait_for() 的功能是一样的，它是指定让线程阻塞到某一个时间点，
    假设阻塞的线程没有被其他线程唤醒，当到达指定的时间点之后，线程就会自动解除阻塞，继续向下执行。

notify_one()：唤醒一个被当前条件变量阻塞的线程
notify_all()：唤醒全部被当前条件变量阻塞的线程
*/

/*
总结：以上介绍的两种互斥锁各自有各自的特点，condition_variable 配合 unique_lock 
    使用更灵活一些，可以在在任何时候自由地释放互斥锁，而 condition_variable_any 如果和
    lock_guard 一起使用必须要等到其生命周期结束才能将互斥锁释放。
    但是，condition_variable_any 可以和多种互斥锁配合使用，应用场景也更广，
    而 condition_variable 只能和独占的非递归互斥锁（mutex）配合使用，有一定的局限性。

注意区别:
// condition_variable

unique_lock<mutex> locker(m_mutex);
m_notEmpty.wait(locker, [this]() {
        return !m_queue.empty();
    });

// condition_variable_any

lock_guard<mutex> locker(m_mutex);
m_notFull.wait(m_mutex, [this]() {
    return m_queue.size() != m_maxSize;
    });
*/
