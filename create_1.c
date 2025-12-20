#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd = 0;
	fd = creat("LST.txt", 0777);

	if(fd == -1)
	{
		printf("Unable to create file\n");
	}
	else
	{
		printf("File gets successfully created with fd: %d\n", fd);
	}

	close(fd);

	return 0;
}
