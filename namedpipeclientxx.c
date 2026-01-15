// Named pipe client

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>

int main()
{
	int fd = 0;
	int iRet = 0;
	char arr[100] = {'\0'};

	fd = open("/tmp/marvelous", O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open named pipe");
		perror("");
		return -2;
	}

	read(fd, arr, 3);
	printf("Data gets successfully read from the pipe by the client\n");
	printf("Data is: %s\n", arr);

	read(fd, arr, 7);
	printf("Data gets successfully read from the pipe by the client\n");
	printf("Data is: %s\n", arr);

	close(fd);

	return 0;
}
