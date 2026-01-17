#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>

void marvelusHandler(int no)
{
	printf("Signal arrived: %d\n", no);	
	signal(SIGUSR1, marvelusHandler);
}

int main()
{
	printf("PID is: %d\n", getpid());
	signal(SIGUSR1, marvelusHandler);

	while(1)
	{
		sleep(1);
	}

	return 0;
}
