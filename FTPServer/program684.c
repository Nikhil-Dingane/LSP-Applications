// Client Application

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <errno.h>

//////////////////////////////////////////////////////////////////////////////
//
//	Commandline Argument Application
//	1st Argument:	IP
//	2nd Argument:	Port
//	3rd Argument:	Target file name
//	4th Argument:	New file name
//
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	int sock = 0;
	int port = 0;
	int iRet = 0;
	int pid = 0;
	char *ip = NULL;
	char *fileName = NULL;
	char *outFileName = NULL;

	struct sockaddr_in serverAddr;

	if(argc != 5)
	{
		errno = EINVAL;
		perror(argv[0]);
		printf("Usage: %s <ip> <port> <target file> <new file>\n", argv[0]);
		return -1;
	}

	// store command line arguments into the variables
	ip = argv[1];
	port = atoi(argv[2]);
	fileName = argv[3];
	outFileName = argv[4];

	/////////////////////////////////////////////////////////////////////
	// Step 1: Create TCP socket
	/////////////////////////////////////////////////////////////////////

	errno = 0;
	sock = socket(AF_INET, SOCK_STREAM, 0);

	if(sock == -1)
	{
		perror("socket failed");
		return -1;
	}

	/////////////////////////////////////////////////////////////////////
	// Step 2: Connect socket to server
	/////////////////////////////////////////////////////////////////////

	errno = 0;
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	// convert IP addess into binary format
	inet_pton(AF_INET, ip, &serverAddr.sin_addr);

	errno = 0;
	iRet = connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

	if(iRet == -1)
	{
		perror("connect failed");
		close(sock);
		return -1;
	}

	write(sock, fileName, strlen(fileName));

	close(sock);
	return 0;
} // End of main
