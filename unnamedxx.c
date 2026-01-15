#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int pipefd[2] = {0, 0};
	int iRet = 0;
	char arr[100];

	if(pipe(pipefd) != 0)
	{
		perror("");
		return -1;
	}

	iRet = fork();

	if(iRet == 0)		// child
	{
		close(pipefd[0]);
		write(pipefd[1], "Jay Ganesh", 10);
		exit(0);
	}
	else
	{
		close(pipefd[1]);
		read(pipefd[0], arr, 10); 
		printf("Data is: %s\n", arr);
	}

	return 0;
}
