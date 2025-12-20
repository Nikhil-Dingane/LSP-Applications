#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define SIZE_BUFFER 1024

int main()
{
	char buffer[SIZE_BUFFER];
	memset(buffer, '\0', sizeof(buffer));

	getcwd(buffer, sizeof(buffer));

	printf("Current Working Directory Name: %s\n", buffer);

	return 0;
}
