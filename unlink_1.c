#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int iRet = 0;
	iRet = unlink("output.txt");
	if(iRet == 0)
	{
		printf("unlink is sucessfull\n");
	}
	else
	{
		printf("unlink is failed\n");
	}
	return 0;
}
