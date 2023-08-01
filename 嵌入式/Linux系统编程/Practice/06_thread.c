#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* thread_function(void* arg)
{
	printf("Thread begins running.\n");

	for(int i = 0; i < *(int*)arg; ++i)
	{
		printf("Hello world\n");
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	pthread_t pthread;
	int ret;
	int count = 5;

	ret = pthread_create(&pthread, NULL, thread_function, &count);
	if(ret)
	{
		perror("pthread_create");
		exit(1);
	}

	pthread_join(pthread, NULL);
	printf("The thread is over, so does the process.\n");

	return 0;
}
