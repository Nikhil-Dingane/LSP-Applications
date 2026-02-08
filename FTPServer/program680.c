#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("PID Of running process: %d\n", getpid());
	printf("PID Of parent process: %d\n", getppid());
	return 0;
}
