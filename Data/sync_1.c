#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int fd = 0;
	char buffer[] = "helloworld";
	int iRet = 0;
	fd = open("Demo.txt", O_CREAT | O_WRONLY | O_APPEND, 0777); // IMP
	if( fd == -1)
	{
		printf("Unable to open the file.\n");
		printf("Error: %s\n", strerror(errno));
	}
	iRet = write(fd, buffer, 10);
	printf("Bytes successfully written to file is: %d\n", iRet);
	close(fd);
	return 0;
}
