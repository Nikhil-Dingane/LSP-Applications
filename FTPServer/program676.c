#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if(argc < 5)
	{
		errno = EINVAL;
		perror(argv[0]);
		printf("Usage: %s <IP> <port> <targeted file> <new file>\n", argv[0]);
		return -1;
	}

	printf("Exe name: %s\n", argv[0]);
	printf("IP: %s\n", argv[1]);
	printf("Port: %s\n", argv[2]);
	printf("Targeted file: %s\n", argv[3]);
	printf("New file: %s\n", argv[4]);

	return 0;
}
