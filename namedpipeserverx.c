// Named pipe server

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

	iRet = mkfifo("/tmp/marvelous", 0666);

	if(iRet == -1)
	{
		printf("Unable to create named pipe\n");
		perror("");
		return -1;
	}	

	fd = open("/tmp/marvelous", O_WRONLY);

	if(fd == -1)
	{
		printf("Unable to open named pipe");
		perror("");
		return -2;
	}

	write(fd, "Jay Ganesh", 10);
	if(errno)
		perror("");
	printf("Data gets successfully written into the pipe by the server\n");

	close(fd);
	unlink("/tmp/marvelous");

	return 0;
}
