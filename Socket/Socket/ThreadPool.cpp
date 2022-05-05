#include "ThreadPool.h"
#include <iostream>
#include <string.h>
#include <string>
#include <unistd.h>

template<class T>
ThreadPool<T>::ThreadPool(int min, int max){
	do {
		// 实例化任务队列
		taskQ = new TaskQueue<T>;
		if (taskQ == nullptr) {
			std::cout << "new taskQ fail..." << std::endl;
			break;
		}

		threadIDs = new pthread_t[max];
		if (threadIDs == nullptr) {
			std::cout << "new threadIDs fail..." << std::endl;
			break;
		}
		// 初始化为 0
		memset(threadIDs, 0, sizeof(pthread_t) * max);

		minNum = min;
		maxNum = max;
		busyNum = 0;
		liveNum = min;
		exitNum = 0;
		shutdown = false;

		if (pthread_mutex_init(&mutexPool, NULL) != 0 ||
			pthread_cond_init(&notEmpty, NULL) != 0 ||
			pthread_mutex_init(&mutexBusy, NULL) != 0) {
			std::cout << "mutex or condition init fail..." << std::endl;
			break;
		}

		// 创建线程， 静态函数只能访问静态变量，所以要将实例化的对象 this 传入该函数
		pthread_create(&managerID, NULL, manager, this);
		for (int i = 0; i < min; i++) {
			pthread_create(&threadIDs[i], NULL, worker, this);
		}
		return;
	} while (0);

	// 初始化失败，释放资源
	if (threadIDs) delete[] threadIDs;
	if (taskQ) delete taskQ;
}

template<class T>
ThreadPool<T>::~ThreadPool(){
	// 关闭线程池
	shutdown = 1;
	// 阻塞回收管理者线程
	pthread_join(managerID, NULL);
	// 唤醒阻塞的工作（消费）者线程
	for (int i = 0; i < liveNum; ++i) {
		pthread_cond_signal(&notEmpty);
	}
	if (threadIDs) delete[] threadIDs;
	if (taskQ) delete taskQ;
	pthread_mutex_destroy(&mutexPool);
	pthread_mutex_destroy(&mutexBusy);
	pthread_cond_destroy(&notEmpty);
}

template<class T>
void ThreadPool<T>::addTask(Task<T> task){
	// pthread_mutex_lock(&mutexPool);

	if (shutdown) {
		// pthread_mutex_unlock(&mutexPool);
		return;
	}
	// 添加任务
	taskQ->addTask(task);
	pthread_cond_signal(&notEmpty);

	// pthread_mutex_unlock(&mutexPool);
}

template<class T>
int ThreadPool<T>::getBusyNum(){
	pthread_mutex_lock(&mutexPool);
	int busyNum = this->busyNum;
	pthread_mutex_unlock(&mutexPool);
	return busyNum;
}

template<class T>
int ThreadPool<T>::getAliveNum(){
	pthread_mutex_lock(&mutexPool);
	int liveNum = this->liveNum;
	pthread_mutex_unlock(&mutexPool);
	return liveNum;
}

template<class T>
void* ThreadPool<T>::worker(void* arg){
	ThreadPool* pool = static_cast<ThreadPool*>(arg);
	while (true) {
		pthread_mutex_lock(&pool->mutexPool);
		// 当前任务是否为空，是否关闭线程池
		while (pool->taskQ->taskNumber() == 0 && !pool->shutdown) {
			// 阻塞工作线程，当任务队列不为空 
			// 会唤醒一个或多个线程，只有一个线程会得到 pool->mutexPool
			// 其他的会在 while(1) 循环判断等待
			pthread_cond_wait(&pool->notEmpty, &pool->mutexPool);
			
			// 判断是不是要销毁线程
			if (pool->exitNum > 0) {
				// 不管工作线程有没有自杀，这里都要 pool->exitNum--
				pool->exitNum--;
				if (pool->liveNum > pool->minNum) {
					pool->liveNum--;
					pthread_mutex_unlock(&pool->mutexPool);
					pool->threadExit();
				}
			}
		}

		// 判断线程池是否被关闭
		if (pool->shutdown) {
			// 避免死锁
			pthread_mutex_unlock(&pool->mutexPool);
			pool->threadExit();
		}
		// 从任务队列中取一个任务
		Task<T> task = pool->taskQ->takeTask();
		// 解锁
		pthread_mutex_unlock(&pool->mutexPool);

		std::cout << "thread " << std::to_string(pthread_self()) << " start working..." << std::endl;
		
		pthread_mutex_lock(&pool->mutexBusy);
		pool->busyNum++;
		pthread_mutex_unlock(&pool->mutexBusy);
		
		// 执行任务
		task.function(task.arg);
		delete task.arg;
		task.arg = nullptr;

		std::cout << "thread " << std::to_string(pthread_self()) << " end working..." << std::endl;
		
		pthread_mutex_lock(&pool->mutexBusy);
		pool->busyNum--;
		pthread_mutex_unlock(&pool->mutexBusy);

	}
	return nullptr;
}

template<class T>
void* ThreadPool<T>::manager(void* arg){
	ThreadPool* pool = static_cast<ThreadPool*> (arg);
	while (!pool->shutdown) {
		// 每隔3s检查一次
		sleep(3);
		//取出线程池中的任务的数量和当前线程的数量
		pthread_mutex_lock(&pool->mutexPool);
		int queueSize = pool->taskQ->taskNumber();
		int liveNum = pool->liveNum;
		pthread_mutex_unlock(&pool->mutexPool);

		//取出忙的线程的数量, 经常被使用的额外加锁
		pthread_mutex_lock(&pool->mutexBusy);
		int busyNum = pool->busyNum;
		pthread_mutex_unlock(&pool->mutexBusy);

		// 添加线程
		// 任务的个数 > 存活的线程个数 && 存活的线程数 < 最大线程数
		// 一次性最多添加 NUMBER 个
		if (queueSize > liveNum && liveNum < pool->maxNum) {
			pthread_mutex_lock(&pool->mutexPool);
			int counter = 0;
			for (int i = 0; i < pool->maxNum && counter < NUMBER &&
				pool->liveNum < pool->maxNum; ++i) {
				if (pool->threadIDs[i] == 0) { // 从 0 到 maxNum 寻找 可以添加的 线程 
					pthread_create(&pool->threadIDs[i], NULL, worker, pool);
					counter++;
					pool->liveNum++;
				}
			}
			pthread_mutex_unlock(&pool->mutexPool);
		}
		// 销毁线程 
		// 忙的线程*2  < 存活的线程 && 存活的线程 > 最小线程数
		// 每次销毁2个线程
		if (busyNum * 2 < liveNum && liveNum > pool->minNum) {
			pthread_mutex_lock(&pool->mutexPool);
			// 要自杀的线程数
			pool->exitNum = NUMBER;
			pthread_mutex_unlock(&pool->mutexPool);
			// 让工作线程自杀
			for (int i = 0; i < NUMBER; ++i) {
				pthread_cond_signal(&pool->notEmpty);
			}
		}
	}
	return nullptr;
}

template<class T>
void ThreadPool<T>::threadExit(){
	pthread_t tid = pthread_self();
	for (int i = 0; i < maxNum; ++i) {
		if (threadIDs[i] == tid) {
			threadIDs[i] = 0;
			std::cout << "threadExit() called, " << std::to_string(tid) << " exiting..." << std::endl;
			break;
		}
	}
	pthread_exit(NULL);
}
