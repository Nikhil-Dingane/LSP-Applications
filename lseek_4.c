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

	fd = open("Hole.txt", O_WRONLY | O_CREAT, 0770);
	if( fd == -1)
	{
		printf("Unable to open the file.\n");
		printf("Error: %s\n", strerror(errno));
	}

	printf("File successfullly opened with fd: %d\n", fd);
	
	iRet = lseek(fd, 4100, SEEK_SET);

	printf("Current offset is: %d\n", iRet);

	iRet = write(fd, "END", 3);

	printf("%d bytes successfully written in the file\n", iRet);
	
	close(fd);

	return 0;
}
