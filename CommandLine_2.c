#include<stdio.h>

int main(int argc, char *argv[])
{
	printf("Number of command line args: %d\n", argc);
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	return 0;
}
