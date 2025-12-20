// Understanding the CommandLine by dennis ritchie

#include<stdio.h>

int main(int argc, char *argv[])
{
	printf("Number of command line args: %d\n", argc);
	for(int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return 0;
}
