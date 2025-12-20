#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
	int iRet = 0;

	iRet = rmdir("./Data");
	
	if(iRet == 0)
	{
		printf("Directory gets removed successfully.\n");
	}
	else
	{
		printf("Error: %s\n", strerror(errno));
	}
	
	return 0;
}
