#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd  = 0;
	fd = open("Second.c",  O_TRUNC, 0777);

	if(fd == -1)
	{
		printf("Unable to create the file.\n");
	}
	else
	{
		printf("File is successfully created with fd: %d\n", fd);
	}

	return 0;
}
