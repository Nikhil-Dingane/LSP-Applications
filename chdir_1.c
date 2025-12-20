#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

#define SIZE_BUFFER 1024

int main()
{
	char buffer[SIZE_BUFFER];

	memset(buffer, '\0', sizeof(buffer));
	getcwd(buffer, sizeof(buffer));
	printf("Current Working Directory Name: %s\n", buffer);

	chdir("./Data");

	memset(buffer, '\0', sizeof(buffer));
	getcwd(buffer, sizeof(buffer));
	printf("Current Working Directory Name: %s\n", buffer);

	return 0;
}
