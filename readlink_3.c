#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>


int main()
{
	char Path[100];
	char Arr[20];
	int iRet = 0;
	int fd = 0;

	memset(Path, '\0', sizeof(Path));
	memset(Arr, '\0', sizeof(Arr));
	
	iRet = readlink("./Test/LSPl.txt", Path, sizeof(Path));

	if(iRet == -1)
	{
		printf("%s\n", strerror(errno));
		return -1;
	}

	Path[iRet] = '\0';
	printf("Symlink Path: %s\n", Path);

	fd = open(Path, O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		printf("%s\n", strerror(errno));
		return -1;
	}

	iRet = read(fd, Arr, 10);

	printf("Data from original file is: %s\n", Arr);
	close(fd);

	return 0;
}
