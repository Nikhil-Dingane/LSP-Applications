#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int pipefd[2] = {0, 0};
	int iRet = 0;
	char arr[100];

	iRet = pipe(pipefd);

	if(iRet == 0)
	{
		printf("unlink pipe gets created\n");
	}

	write(pipefd[1], "Jay Ganehs", 10);

	read(pipefd[0], arr, 10); 

	printf("Data is: %s\n", arr);

	return 0;
}
