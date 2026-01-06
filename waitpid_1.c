#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t childPid = 0;
	int status = 0;

	childPid = fork();

	if(childPid == 0)
	{
		printf("Child is running with PID: %d\n", getpid());
		sleep(10);
		printf("Child process is exiting\n");
		return 11;
	}
	else
	{
		printf("Parent is running\n");
		printf("Parent is waiting for child: %d\n", childPid);
		pid_t ret = waitpid(childPid, &status, 0);

		if(WIFEXITED(status))
		{
			printf("Parent process is exiting because child exited with PID %d ended\n", ret);
			printf("Exist status of child is: %d\n", WEXITSTATUS(status));
		}
	}

	return 0;
}
