#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("No of command line arguments are: %d\n", argc);
	printf("Exe name: %s\n", argv[0]);
	printf("IP: %s\n", argv[1]);
	printf("Port: %s\n", argv[2]);
	printf("Targeted file: %s\n", argv[3]);
	printf("New file: %s\n", argv[4]);
	return 0;
}
