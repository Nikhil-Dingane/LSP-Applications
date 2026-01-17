#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>

int main()
{
	int pid = 0;
	printf("Enter the PID of process: \n");
	scanf("%d", &pid);
	
	kill(pid, SIGUSR1);

	return 0;
}
