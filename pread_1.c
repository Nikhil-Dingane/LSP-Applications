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

	offset = lseek(fd, 0, SEEK_SET);
	printf("Current offset is: %ld\n", offset);

	read(fd, buffer, 10);

	offset = lseek(fd, 0, SEEK_CUR);
	printf("Current offset is: %ld\n", offset);

	return 0;
}
