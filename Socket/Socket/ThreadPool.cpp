#include "ThreadPool.h"
#include <iostream>
#include <string.h>
#include <string>
#include <unistd.h>

template<class T>
ThreadPool<T>::ThreadPool(int min, int max){
	do {
		// ʵ�����������
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
		// ��ʼ��Ϊ 0
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

		// �����̣߳� ��̬����ֻ�ܷ��ʾ�̬����������Ҫ��ʵ�����Ķ��� this ����ú���
		pthread_create(&managerID, NULL, manager, this);
		for (int i = 0; i < min; i++) {
			pthread_create(&threadIDs[i], NULL, worker, this);
		}
		return;
	} while (0);

	// ��ʼ��ʧ�ܣ��ͷ���Դ
	if (threadIDs) delete[] threadIDs;
	if (taskQ) delete taskQ;
}

template<class T>
ThreadPool<T>::~ThreadPool(){
	// �ر��̳߳�
	shutdown = 1;
	// �������չ������߳�
	pthread_join(managerID, NULL);
	// ���������Ĺ��������ѣ����߳�
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
	// �������
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
		// ��ǰ�����Ƿ�Ϊ�գ��Ƿ�ر��̳߳�
		while (pool->taskQ->taskNumber() == 0 && !pool->shutdown) {
			// ���������̣߳���������в�Ϊ�� 
			// �ỽ��һ�������̣߳�ֻ��һ���̻߳�õ� pool->mutexPool
			// �����Ļ��� while(1) ѭ���жϵȴ�
			pthread_cond_wait(&pool->notEmpty, &pool->mutexPool);
			
			// �ж��ǲ���Ҫ�����߳�
			if (pool->exitNum > 0) {
				// ���ܹ����߳���û����ɱ�����ﶼҪ pool->exitNum--
				pool->exitNum--;
				if (pool->liveNum > pool->minNum) {
					pool->liveNum--;
					pthread_mutex_unlock(&pool->mutexPool);
					pool->threadExit();
				}
			}
		}

		// �ж��̳߳��Ƿ񱻹ر�
		if (pool->shutdown) {
			// ��������
			pthread_mutex_unlock(&pool->mutexPool);
			pool->threadExit();
		}
		// �����������ȡһ������
		Task<T> task = pool->taskQ->takeTask();
		// ����
		pthread_mutex_unlock(&pool->mutexPool);

		std::cout << "thread " << std::to_string(pthread_self()) << " start working..." << std::endl;
		
		pthread_mutex_lock(&pool->mutexBusy);
		pool->busyNum++;
		pthread_mutex_unlock(&pool->mutexBusy);
		
		// ִ������
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
		// ÿ��3s���һ��
		sleep(3);
		//ȡ���̳߳��е�����������͵�ǰ�̵߳�����
		pthread_mutex_lock(&pool->mutexPool);
		int queueSize = pool->taskQ->taskNumber();
		int liveNum = pool->liveNum;
		pthread_mutex_unlock(&pool->mutexPool);

		//ȡ��æ���̵߳�����, ������ʹ�õĶ������
		pthread_mutex_lock(&pool->mutexBusy);
		int busyNum = pool->busyNum;
		pthread_mutex_unlock(&pool->mutexBusy);

		// ����߳�
		// ����ĸ��� > �����̸߳��� && �����߳��� < ����߳���
		// һ���������� NUMBER ��
		if (queueSize > liveNum && liveNum < pool->maxNum) {
			pthread_mutex_lock(&pool->mutexPool);
			int counter = 0;
			for (int i = 0; i < pool->maxNum && counter < NUMBER &&
				pool->liveNum < pool->maxNum; ++i) {
				if (pool->threadIDs[i] == 0) { // �� 0 �� maxNum Ѱ�� ������ӵ� �߳� 
					pthread_create(&pool->threadIDs[i], NULL, worker, pool);
					counter++;
					pool->liveNum++;
				}
			}
			pthread_mutex_unlock(&pool->mutexPool);
		}
		// �����߳� 
		// æ���߳�*2  < �����߳� && �����߳� > ��С�߳���
		// ÿ������2���߳�
		if (busyNum * 2 < liveNum && liveNum > pool->minNum) {
			pthread_mutex_lock(&pool->mutexPool);
			// Ҫ��ɱ���߳���
			pool->exitNum = NUMBER;
			pthread_mutex_unlock(&pool->mutexPool);
			// �ù����߳���ɱ
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
