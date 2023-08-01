#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char* argv[])
{
	kill(atoi(argv[1]), SIGQUIT);
	return 0;
}
