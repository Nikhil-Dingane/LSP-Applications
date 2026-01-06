#include<stdio.h>
#include<string.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<errno.h>
#include<unistd.h>

int main()
{
	char *ptr = NULL;
	int fd = 0;
	struct stat st;

	if((fd = open("Pune.txt", O_RDWR | O_CREAT, 0777)) == -1)
	{
		perror("Unable to open");
		return -1;
	}

	if(fstat(fd, &st) == -1)
	{
		perror("Unable to stat");
		return -3;
	}

	if(ftruncate(fd, 4096) == -1)
	{
		perror("Unable to truncate");
		return -4;
	}
	ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	strcpy(ptr, "Jay Ganesh...\n");

	printf("Data from mapped memory is: %s\n", ptr);

	munmap(ptr, 4096);
	close(fd);

	return 0;
}
