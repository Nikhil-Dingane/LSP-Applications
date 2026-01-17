#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	printf("PID is: %d\n", getpid());

	while(1)
	{
		sleep(1);
	}

	return 0;
}
