#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

pthread_mutex_t mutex;

void* thread1_function(void* arg);
void* thread2_function(void* arg);

int main(void)
{
	pthread_t pthread1, pthread2;
	int ret;
	// 创建互斥锁
	pthread_mutex_init(&mutex, NULL);
	// 创建线程1
	ret = pthread_create(&pthread1, NULL, thread1_function, NULL);
	if(ret)
	{
		perror("pthread_create");
		exit(1);
	}
	// 创建线程2
	ret = pthread_create(&pthread2, NULL, thread2_function, NULL);
	if(ret)
	{
		perror("pthread_create");
		exit(1);
	}
	// 监控线程
	pthread_join(pthread1, NULL);
	pthread_join(pthread2, NULL);
	printf("The thread is over, so does the process.\n");

	return 0;
}

void* thread1_function(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		for(int i = 0; i < 10; ++i)
		{
			printf("Hello, this's thread 1.\n");
			sleep(1);
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return NULL;
}

void* thread2_function(void* arg)
{
	sleep(1);
	while(1)
	{
		pthread_mutex_lock(&mutex);
		for(int i = 0; i < 10; ++i)
		{
			printf("Thread2 running!\n");
			sleep(1);
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return NULL;
}
