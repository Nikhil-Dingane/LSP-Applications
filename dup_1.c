#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
	int fd1 = 0, fd2 = 0;

	fd1 = open("./LSP.txt", O_RDWR);
	printf("fd1: %d\n", fd1);

	fd2 = dup(fd1);
	printf("fd2: %d\n", fd2);

	close(fd1);
	close(fd2);
	
	return 0;
}
