#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>

#define BUFFER_SIZE 100

int main()
{
	int fd = 0;
	off_t offset = 0;
	char buffer[100];

	fd = open("./LSP.txt", O_RDONLY);

	if(fd == -1)
	{
		perror("Error");
		printf("Unable to open file Demo.txt\n");
		return -1;
	}

	offset = lseek(fd, 10, SEEK_SET);
	printf("Current offset is: %ld\n", offset);

	int iRet = read(fd, buffer, 5);
	//printf("Data from file is: %5s\n", buffer);
	printf("\n");
	write(1, buffer, iRet);
	printf("\n");
	
	offset = lseek(fd, 0, SEEK_CUR);
	printf("Current offset is: %ld\n", offset);

	return 0;
}
