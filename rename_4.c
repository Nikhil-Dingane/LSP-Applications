#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int iRet = 0;
	int fd = 0;
	char Arr[100];

	memset(Arr, '\0', sizeof(Arr));

	fd = open("./process.txt", O_RDONLY);
	
	if(fd != 0)
	{
		printf("File opened with fd: %d\n", fd);
	}
	else
	{
		printf("Error: %s\n", strerror(errno));
		return -1;
	}

	iRet = rename("./process.txt", "./Test/Hello.txt");
	if(iRet == 0)
	{
		printf("Rename is successfull\n");
	}
	else
	{
		printf("Error: %s\n", strerror(errno));
		return -1;
	}
	
	iRet = read(fd, Arr, sizeof(Arr));

	if(iRet != 0)
	{
		printf("Data from file is: %s\n", Arr);
	}
	else
	{
		printf("Error while read: %s\n", strerror(errno));
		return -1;
	}

	close(fd);

	return 0;
}
