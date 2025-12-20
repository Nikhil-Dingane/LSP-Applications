#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define SIZE_BUFFER 100

int main()
{
	int fd = 0;
	char buffer[SIZE_BUFFER];
	int iRet = 0;

	memset(buffer, '\0', SIZE_BUFFER); // Chnage

	fd = open("Demo.txt", O_RDONLY);
	if( fd == -1)
	{
		printf("Unable to open the file.\n");
		printf("Error: %s\n", strerror(errno));
	}

	iRet = read(fd, buffer, 10);
	printf("Bytes successfully written to file is: %d\n", iRet);
	printf("Data from file: %s\n", buffer);
	
	memset(buffer, '\0', SIZE_BUFFER); // IMP

	iRet = read(fd, buffer, 10);
	printf("Bytes successfully written to file is: %d\n", iRet);
	printf("Data from file: %s\n", buffer);

	close(fd);

	return 0;
}
