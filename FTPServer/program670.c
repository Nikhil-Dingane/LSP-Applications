// client

#include <stdio.h>		// printf, scanf
#include <stdlib.h>		// malloc, free
#include <string.h>		// memset, memcp
#include <unistd.h>		// close, write, read
#include <fcntl.h>		// creat, unlink
#include <errno.h>
#include <sys/socket.h>		// socket, bind, listen, accept, connect
#include <netinet/in.h>		// sockaddr_in, htons

int main()
{
	int iRet = 0;
	int port = 11000;
	struct sockaddr_in serverAddr, clientAddr;
	int clientSocketFd = 0, serverSocketFD = 0;

	serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);

	if(serverSocketFD == -1)
	{
		perror("socket creation failed");
		return -1;
	}

	printf("Socket successfully created\n");
	return 0;
}
