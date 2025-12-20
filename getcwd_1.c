#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define SIZE_BUFFER 1024

int main()
{
	printf("Current Working directory: %s\n", getcwd()); // LSP
	return 0;
}
