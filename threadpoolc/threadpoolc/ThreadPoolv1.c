#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ��ӽڵ�
#define LL_ADD(item, list) do{           \
	item->prev = NULL;                   \
	item->next = list;                   \
	if (list != NULL) list->prev = item; \
	list = item;                         \
} while (0)

// ɾ���ڵ�
#define LL_REMOVE(item, list) do{                           \
	if (item->prev != NULL) item->prev->next = item->next;  \
	if (item->next != NULL) item->next->prev = item->prev;  \
	if (list == item) list = item->next;                    \
	item->prev = item->next = NULL;                         \
}while(0)

struct MANAGER;

// �������߳�
typedef struct WORKER
{
	pthread_t tid;
	struct WORKER* prev, *next;
	struct MANAGER* pool;
	int terminate;
}Worker;

// �������
typedef struct JOB {
	// 
	void* user_data;
	// ������
	void (*func)(struct JOB* job);
	struct JOB* prev, *next;
}Job;

typedef struct MANAGER {
	Worker* workers;
	Job* jobs;
	
	// �ȴ�������������
	pthread_cond_t jobs_cond;
	// ��������м���
	pthread_mutex_t jobs_mutex;
}ThreadPool;

static void* ThreadCallback(void* arg) {
	Worker* worker = (Worker*)arg;
	while (1) {
		pthread_mutex_lock(&worker->pool->jobs_mutex);
		while (worker->pool->jobs == NULL) {
			// �����߳��Ƿ�Ҫ�˳�
			if (worker->terminate) break;
			pthread_cond_wait(&worker->pool->jobs_cond, &worker->pool->jobs_mutex);
		}
		// �����߳��Ƿ�Ҫ�˳����ͷ���
		if (worker->terminate) {
			pthread_mutex_unlock(&worker->pool->jobs_mutex);
			break;
		}
		// �õ�һ������
		Job* job = worker->pool->jobs;
		// ȥ��list�и�����
		LL_REMOVE(job, worker->pool->jobs);
		pthread_mutex_unlock(&worker->pool->jobs_mutex);
		// ִ�лص�����
		job->func(job->user_data);
	}
	// �˳��߳�
	free(worker);
	pthread_exit(NULL);
}

// �̳߳صĳ�ʼ��
int ThreadPoolCreate(ThreadPool* pool, int numWorkers) {
	// ����̳߳��еĹ������߳�С�� 1
	if (numWorkers < 1) numWorkers = 1;
	if (pool == NULL) return -1;
	memset(pool, 0, sizeof(ThreadPool));
	// ����������ʼ��
	pthread_cond_t blank_cond = PTHREAD_COND_INITIALIZER;
	memcpy(&pool->jobs_cond, &blank_cond, sizeof(pthread_cond_t));
	// ��������ʼ��
	pthread_mutex_t blank_mutex = PTHREAD_MUTEX_INITIALIZER;
	memcpy(&pool->jobs_mutex, &blank_mutex, sizeof(pthread_mutex_t));

	int i = 0; 
	for (i = 0; i < numWorkers; ++i) {
		// ���������߶���
		Worker* worker = (Worker*)malloc(sizeof(Worker));
		if (worker == NULL) {
			perror("malloc");
			return -2;
		}
		memset(worker, 0, sizeof(Worker));
		worker->pool = pool;
		// �����������߳�
		int ret = pthread_create(&worker->tid, NULL, ThreadCallback, worker);
		if (ret) {
			perror("pthread_create");
			free(worker);
			return -2;
		}
		// �����߳���ӵ��̳߳�
		LL_ADD(worker, pool->workers);
	}
	return 0;
}


void ThreadPoolPush(ThreadPool* pool, Job* job) {
	// �������
	pthread_mutex_lock(&pool->jobs_mutex);
	LL_ADD(job, pool->jobs);
	// ֪ͨ�������߳�
	pthread_cond_signal(&pool->jobs_cond);
	pthread_mutex_unlock(&pool->jobs_mutex);
}

int ThreadPollDestory(ThreadPool* pool) {
	Worker* worker = NULL;
	for (worker = pool->workers; worker != NULL; worker = worker->next) {
		worker->terminate = 1;
	}
	pthread_mutex_lock(&pool->jobs_mutex);
	pthread_cond_broadcast(&pool->jobs_cond);
	pthread_mutex_unlock(&pool->jobs_mutex);
	return 0;
}

#if 0
#define NUM 1000

void printNum(void* arg) {
	printf("thread %ld is worker, num = %d \n", pthread_self(), *(int*)arg);
	usleep(200);
}

int main() {
	ThreadPool* pool = (ThreadPool*)malloc(sizeof(ThreadPool));
	ThreadPoolCreate(pool, 5);
	int nums[NUM] = { NUM };
	Job* jobs = (Job*)malloc(sizeof(Job) * NUM);
	memset(jobs, 0, sizeof(Job) * NUM);
	for (int i = 0; i < NUM; ++i) {
		jobs[i].func = printNum;
		if (i > 0) nums[i] = nums[i - 1] - 1;
		jobs[i].user_data = &nums[i];
		ThreadPoolPush(pool, &jobs[i]);
	}
	sleep(20);
	ThreadPollDestory(pool);
	free(pool);
	free(jobs);
	return 0;
}
#endif // 0