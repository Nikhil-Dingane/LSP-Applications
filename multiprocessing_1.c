#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

#define BUFFER_SIZE 1024

int main()
{
	pid_t pid1 = 0, pid2 = 0;

	pid1 = fork();
	if(pid1 == 0)
	{
		//printf("CHILD SAYS: PID of current process is: %d, PID of parent process is: %d, PID of value of fork is: %d\n", getpid(), getppid(), pid1);
		execl("./CapitalProcess", "", NULL);
	}
	else

	pid2 = fork();
	if(pid2 == 0)
	{
		//printf("CHILD SAYS: PID of current process is: %d, PID of parent process is: %d, PID of value of fork is: %d\n", getpid(), getppid(), pid2);
		execl("./SmallProcess", "", NULL);
	}
	else

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	printf("End of main process\n");

	return 0;
}
