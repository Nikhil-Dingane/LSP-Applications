#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd = 0;
	fd = open("Marvelous.txt", O_WRONLY);
	if(errno != 0)
	{
		switch(errno)
		{
			case ENOENT:
				printf("There is no such file or directory exist\n");
				break;
			case EACCES:
				printf("Unable to access the file.\n");
				break;
			default:
				printf("Error: %s\n", strerror(errno));
		}
		return -1;
	}
	return 0;
}
