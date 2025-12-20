#include<stdio.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
	int fd = 0;
	fd = open("Marvelous.txt", O_RDONLY);
	printf("Value of fd: %d\n", fd);
	printf("Value of errno: %d\n", errno);
	return 0;
}
