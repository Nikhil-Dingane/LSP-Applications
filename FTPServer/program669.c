// Server

#include <stdio.h>		// printf, scanf
#include <stdlib.h>		// malloc, free
#include <string.h>		// memset, memcp
#include <unistd.h>		// close, write, read
#include <fcntl.h>		// creat, unlink
#include <errno.h>
#include <sys/socket.h>		// socket, bind, listen, accept, connect
#include <netinet/in.h>		// sockaddr_in, htons
#include <arpa/inet.h>

/*
   struct sockaddr {
   	sa_family_t sa_family;
   	char        sa_data[14];
   }
   struct sockaddr_in {
           sa_family_t     sin_family;      AF_INET 
           in_port_t       sin_port;        Port number 
           struct in_addr  sin_addr;        IPv4 address 
       };
*/

int main()
{
	int serverSocketFD = 0;
	int iRet = 0;
	int port = 11000;
	struct sockaddr_in addr, clientAddr;
	int clientSocketFD = 0;

	// Step 1: create TCP server socket
	serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
	if(serverSocketFD == -1)
	{
		perror("socket: ");
		return -1;
	}

	// Step 2: Attach the socket to IP address & 

	memset(&addr, 0, sizeof(addr));

	addr.sin_family = AF_INET;
	//addr.sin_addr.s_addr = INADDR_ANY;
	inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
	addr.sin_port = htons(port);

	iRet = bind(serverSocketFD, (const struct sockaddr *)&addr, sizeof(addr));

	if(iRet == -1)
	{
		perror("socket: ");
		close(serverSocketFD);
		return -1;
	}

	printf("Socket successfully bind\n");

	// Step 3: Mark the socket as active/listen
	iRet = 0;
	errno = 0;
	
	iRet = listen(serverSocketFD, 0);

	if(iRet == -1)
	{
		perror("listen failed");
		close(serverSocketFD);
		return -1;
	}
	
	printf("Socket is successfully listening\n");

	// Step 4: Accept new socket request
	
	memset(&addr, 0, sizeof(clientAddr));

	clientSocketFD = accept(serverSocketFD, NULL, 0);

	if(clientSocketFD == -1)
	{
		perror("accept failed");
		close(serverSocketFD);
		return -1;
	}

	printf("Client connection accepted successfully\n");

	return 0;
}
