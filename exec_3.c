#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid = 0;
	pid = fork();
	if(pid == 0)
	{
		printf("CHILD SAYS: PID of current process is: %d, PID of parent process is: %d, PID of value of fork is: %d\n", getpid(), getppid(), pid);
		execl("./CommandLine", "", NULL);
	}
	else
	{
		printf("PARENT SAYS: PID of current process is: %d, PID of parent process is: %d, PID of value of fork is: %d\n", getpid(), getppid(), pid);
	}
	return 0;
}
