#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

int main()
{
	int iRet = 0;
	DIR* dir = NULL;

	dir = opendir("./Data");
	
	if(dir == NULL)
	{
		printf("Unable to open directory.\n");
		printf("%s\n", strerror(errno));
		return -1;
	}
	else
	{
		printf("Directory gets successfully opened.\n");
	}
	
	return 0;
}
