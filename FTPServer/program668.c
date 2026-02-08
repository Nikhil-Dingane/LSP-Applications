// Server
#include <stdio.h>		// printf, scanf
#include <stdlib.h>		// malloc, free
#include <string.h>		// memset, memcp
#include <unistd.h>		// close, write, read
#include <fcntl.h>		// creat, unlink
#include <errno.h>
#include <sys/socket.h>		// socket, bind, listen, accept, connect
#include <netinet/in.h>		// sockaddr_in, htons

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
	int serverSocket = 0;
	int iRet = 0;
	int port = 11000;
	struct sockaddr_in addr;

	// Step 1: create TCP server socket
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(serverSocket == -1)
	{
		perror("socket: ");
		return -1;
	}

	// Step 2: Attach the socket to IP address & 

	memset(&addr, 0, sizeof(addr));

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);

	iRet = bind(serverSocket, (const struct sockaddr *)&addr, sizeof(addr));

	if(iRet == -1)
	{
		perror("bind failed");
		close(serverSocket);
		return -1;
	}

	printf("Socket successfully bind\n");

	// Step 3: Mark the socket as active/listen
	iRet = 0;
	errno = 0;
	
	iRet = listen(serverSocket, 1000);

	if(iRet == -1)
	{
		perror("listen failed");
		close(serverSocket);
		return -1;
	}
	
	printf("Socket is successfully listening\n");

	return 0;
}
