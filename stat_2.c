#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>


int main()
{
	struct stat sobj;
	int iRet = 0;
	iRet = stat("Demo.txt", &sobj);

	printf("Inode number: %lu\n", sobj.st_ino);
	printf("Hard link count: %lu\n", sobj.st_nlink);
	printf("Total size: %lu\n", sobj.st_size);
	printf("Block size: %lu\n", sobj.st_blksize);

	if(iRet == 0)
	{
		printf("stat system call is successfull\n");
	}
	else
	{
		printf("There is a problem in stat system problem\n");
		return -1;
	}
	return 0;
}
