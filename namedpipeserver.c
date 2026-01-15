// Named pipe server

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>

int main()
{
	int fd = 0;
	int iRet = 0;

	iRet = mkfifo("/tmp/marvelous", 0666);

	if((iRet = 0) || (iRet != 0) && (errno != EEXIST))
	{
		printf("Nmaed pipe gets successfully created");
	}
	else
	{
		perror("");
		return -1;
	}	

	return 0;
}
