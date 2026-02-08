//Server
#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>

int main()
{
	int serverSocket = 0;
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(serverSocket < 0)
	{
		perror("socket: ");
		return -1;
	}
	return 0;
}
