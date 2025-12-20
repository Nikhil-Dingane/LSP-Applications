#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd  = 0;
	fd = open("First.c",  O_RDWR);

	if(fd == -1)
	{
		printf("Unable to open the file.\n");
	}
	else
	{
		printf("File is successfully opened with fd: %d\n", fd);
	}

	return 0;
}
