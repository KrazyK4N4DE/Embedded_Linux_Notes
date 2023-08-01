#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count = 0;  // 线程共享资源

void* thread1_function(void* arg)
{
	printf("Thread1 begins running.\n");

	while(1)
	{
		printf("Thread1 count = %d\n", count++);
		sleep(1);
	}
	return NULL;
}

void* thread2_function(void* arg)
{
	printf("Thread2 begins running.\n");

	while(1)
	{
		printf("Thread2 count = %d\n", count++);
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	pthread_t pthread1, pthread2;
	int ret;

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
