#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int fd = 0;
	char buffer[100] = {'\0'};
	int iRet = 0;
	fd = open("Demo.txt", O_RDONLY);
	if( fd == -1)
	{
		printf("Unable to open the file.\n");
		printf("Error: %s\n", strerror(errno));
	}
	iRet = read(fd, buffer, 10);
	printf("Bytes successfully written to file is: %d\n", iRet);
	printf("Data from file: %s\n", buffer);
	close(fd);
	return 0;
}
