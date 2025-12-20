#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int fd = 0;
	char buffer[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int iRet = 0;
	fd = open("Demo.txt", O_WRONLY);
	if( fd == -1)
	{
		printf("Unable to open the file.\n");
		printf("Error: %s\n", strerror(errno));
	}
	printf("File successfully opened with of fd: %d\n", fd);
	close(fd);
	return 0;
}
