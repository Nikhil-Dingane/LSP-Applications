#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int ret = 0;

	ret = nice(0);
	printf("Current nice value: %d\n", ret);

	ret = nice(-5);		// Increase priority
	printf("Current nice value: %d\n", ret);

	if(ret == -1)
	{
		perror("");
		return -1;
	}

	return 0;
}
