#pragma once
#include <queue>
#include <pthread.h>

// �൱�� typedef
using callback = void (*) (void* arg);

// ����ṹ��
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

	// �������
	void addTask(Task<T> task);
	void addTask(callback f, void* arg);

	// ȡ��һ������
	Task<T> takeTask();

	// ��ȡ��ǰ����ĸ���
	inline size_t taskNumber() {
		return m_taskQ.size();
	}
	//


private:
	// ���һ��������
	pthread_mutex_t m_mutex;
	// �������
	std::queue<Task<T>> m_taskQ;

};

