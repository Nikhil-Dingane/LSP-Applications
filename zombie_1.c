#include<stdio.h>
#include<unistd.h>

int main()
{
	int childPid = 0;

	childPid = fork();

	if(childPid == 0)	// child
	{
		printf("Child process is running\n");
		printf("PID of child is: %d and PPID of child is %d\n", getpid(), getppid());
		printf("PID of child is: %d and PPID of child is %d\n", getpid(), getppid());
		exit(0);
	}
	else			// parent
	{
		printf("Parent process is running\n");
		printf("PID of parent is: %d and PPID of parent is %d\n", getpid(), getppid());
		sleep(20);	// child state SLEEP state
		exit(1);
	}
	return 0;
}
