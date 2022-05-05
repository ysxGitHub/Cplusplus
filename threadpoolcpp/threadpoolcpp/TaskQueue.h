#pragma once
#include <queue>
#include <pthread.h>

// 相当于 typedef
using callback = void (*) (void* arg);

// 任务结构体
template<class T>
struct Task{
	// void (*function)(void* arg);
	Task<T>() {
		function = nullptr;
		arg = nullptr;
	}
	Task<T>(callback f, void* arg) {
		this->arg = static_cast<T*>(arg);
		function = f;
	}
	callback function;
	T* arg;
};

template<class T>
class TaskQueue
{
public:
	TaskQueue();
	~TaskQueue();

	// 添加任务
	void addTask(Task<T> task);
	void addTask(callback f, void* arg);

	// 取出一个任务
	Task<T> takeTask();

	// 获取当前任务的个数
	inline size_t taskNumber() {
		return m_taskQ.size();
	}
	//


private:
	// 添加一个互斥锁
	pthread_mutex_t m_mutex;
	// 任务队列
	std::queue<Task<T>> m_taskQ;

};

