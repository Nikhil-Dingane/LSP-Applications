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

	printf("File successfullly opened with fd: %d\n", fd);
	
	iRet = read(fd, buffer, 10);

	memset(buffer, '\0', SIZE_BUFFER);

	iRet = lseek(fd, 5, SEEK_CUR);
	printf("File offset is: %d\n", iRet);
	
	iRet = read(fd, buffer, 11);
	printf("Data from the file: %s\n", buffer);

	close(fd);

	return 0;
}
