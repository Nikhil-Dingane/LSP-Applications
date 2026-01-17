#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>

void marvelusHandler(int no)
{
	if(no == SIGUSR1)
		printf("Marvelouw Message - SIGUSR1 arrived\n");
	else if(no == SIGINT)
		printf("Marvelouw Message - SIGINT arrived\n");
}

int main()
{
	printf("PID is: %d\n", getpid());
	signal(SIGUSR1, marvelusHandler);
	signal(SIGINT, marvelusHandler);

	while(1)
	{
		sleep(1);
	}

	return 0;
}
