#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
	int fd = 0, iRet = 0, iCnt = 0, i = 0;
	char buffer[BUFFER_SIZE] = {'\0'};

	fd = open("PPA.txt", O_RDONLY);

	while((iRet = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		for(i = 0; i < iRet; i++)
		{
			if(buffer[i] >= 'A' && buffer[i] <= 'Z')
				iCnt++;
		}
	}

	printf("Number of capital characters: %d\n", iCnt);
	return 0;
}
