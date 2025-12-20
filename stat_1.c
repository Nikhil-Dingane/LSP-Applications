#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>


int main()
{
	struct stat sobj;
	int iRet = 0;
	iRet = stat("Demo.txt", &sobj);

	if(iRet == 0)
	{
		printf("stat system call is successfull\n");
	}
	else
	{
		printf("There is a problem in stat system problem\n");
	}
	return 0;
}
