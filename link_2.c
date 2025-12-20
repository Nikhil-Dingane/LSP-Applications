#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int iRet = 0;
	iRet = link("./Demo.txt", "./Test/Demo.txt");
	if(iRet == 0)
	{
		printf("link is sucessfull\n");
	}
	else
	{
		printf("link is failed\n");
	}
	return 0;
}
