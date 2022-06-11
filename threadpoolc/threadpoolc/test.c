#if 1
#include "threadpool.h"
#define numTask 1000

void taskFunc(void* arg) {
    printf("thread %ld is working, number = %d\n", pthread_self(), *(int*)arg);
    usleep(100);
}

int main() {
    ThreadPool* pool = threadPoolCreate(3, 10, numTask);
    for (int i = 0; i < numTask; ++i) {
        int* num = (int*)malloc(sizeof(int));
        *num = i + 1;
        threadPoolAdd(pool, taskFunc, num);
    }
    sleep(20);
    threadPoolDestroy(pool);
    return 0;
}
#endif // 1