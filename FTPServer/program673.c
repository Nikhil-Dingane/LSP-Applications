// client

#include <stdio.h>		// printf, scanf
#include <stdlib.h>		// malloc, free
#include <string.h>		// memset, memcp
#include <unistd.h>		// close, write, read
#include <fcntl.h>		// creat, unlink
#include <errno.h>
#include <sys/socket.h>		// socket, bind, listen, accept, connect
#include <netinet/in.h>		// sockaddr_in, htons
#include <arpa/inet.h>		// inet_pton

int main()
{
	int iRet = 0;
	int port = 11000;
	struct sockaddr_in serverAddr, clientAddr;
	int clientSocketFd = 0, serverSocketFD = 0;
	char buffer[1024] = {'\0'};

	// Step 1: create server socket
	serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);

	if(serverSocketFD == -1)
	{
		perror("socket creation failed");
		return -1;
	}

	printf("Socket successfully created\n");

	// Step 2: connect with server
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	//serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(port);
	// 127.0.0.1 -> Binary form
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	iRet = connect(serverSocketFD, (const struct sockaddr *)&serverAddr, sizeof(serverAddr));

	if(iRet == -1)
	{
		perror("socket creation failed");
		close(serverSocketFD);
		return -1;
	}

	printf("Successfully connected to server\n");

	errno = 0;
	iRet = read(serverSocketFD, buffer, sizeof(buffer));

	if(errno)
	{
		perror("socket read failed");
		close(serverSocketFD);
		return -1;
	}

	printf("Data from server is: %s\n", buffer);

	close(serverSocketFD);

	printf("Terminating the client application\n");
	return 0;
}
