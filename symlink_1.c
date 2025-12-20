#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
	int iRet = 0;
	iRet = symlink("Hello.txt", "DemoX.txt");
	if(iRet == 0)
	{
		printf("symlink is sucessfull\n");
	}
	else
	{
		printf("symlink is failed\n");
		printf("%s\n", strerror(errno));
	}
	return 0;
}
