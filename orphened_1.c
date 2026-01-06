// OUTPUT depends on scheduling

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
	}
	else			// parent
	{
		printf("Parent process is running\n");
		printf("PID of parent is: %d and PPID of parent is %d\n", getpid(), getppid());
	}
	return 0;
}
