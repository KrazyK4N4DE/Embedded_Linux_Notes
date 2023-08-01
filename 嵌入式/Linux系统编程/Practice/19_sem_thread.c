#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

int count = 0;  // 线程共享资源
sem_t sem_id;

void* thread1_function(void* arg);
void* thread2_function(void* arg);

int main(void)
{
	pthread_t pthread1, pthread2;
	int ret;
	sem_init(&sem_id, 0, 0);

	ret = pthread_create(&pthread1, NULL, thread1_function, NULL);
	if(ret)
	{
		perror("pthread_create");
		exit(1);
	}

	ret = pthread_create(&pthread2, NULL, thread2_function, NULL);
	if(ret)
	{
		perror("pthread_create");
		exit(1);
	}

	pthread_join(pthread1, NULL);
	pthread_join(pthread2, NULL);
	printf("The thread is over, so does the process.\n");

	return 0;
}

void* thread1_function(void* arg)
{
	while(1)
	{
		sem_wait(&sem_id);
		printf("Thread1 count = %d\n", count++);
	}
	return NULL;
}

void* thread2_function(void* arg)
{
	while(1)
	{
		printf("Thread2 running!\n");
		sleep(1);
		sem_post(&sem_id);
	}
	return NULL;
}
