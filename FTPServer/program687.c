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

int readLine(int sock, char *line, int max)
{
	int i = 0;
	char ch = '\0';
	int n = 0;

	while(i < max - 1)
	{
		n = read(sock, &ch, 1);

		if(n <= 0)
			break;

		line[i++] = ch;

		if(ch == '\n')
			break;
	}

	line[i] = '\0';

	return i;
}

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
	char header[64] = {'\0'};

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

	/////////////////////////////////////////////////////////////////////
	// Step 3: Send file name
	/////////////////////////////////////////////////////////////////////

	write(sock, fileName, strlen(fileName));
	write(sock, "\n", 1);

	/////////////////////////////////////////////////////////////////////
	// Step 3: Read the header
	/////////////////////////////////////////////////////////////////////
	iRet = readLine(sock, header, 64);

	if(iRet <= 0)
	{
		printf("Server gets disconnected abonormally\n");
		close(sock);
		return -1;
	}

	long fileSize = 0;

	sscanf(header, "OK %ld", &fileSize);
	printf("File size is: %ld\n", fileSize);
	
	/////////////////////////////////////////////////////////////////////
	// Step 3: Read the header
	/////////////////////////////////////////////////////////////////////

	int outFd = 0;

	outFd = open(outFileName, O_CREAT | O_WRONLY | O_TRUNC, 0777);

	if(outFd == -1)
	{
		printf("Unable to create downloaded file");
		return -1;
	}

	char buffer[1024] = {'\0'};
	long received = 0;
	long remaining = 0;
	int n = 0;
	int toRead = 0;

	while(received < fileSize)
	{
		remaining = fileSize - received;

		if(remaining > 1024)
			toRead = 1024;
		else
			toRead = remaining;

		n = read(sock, buffer, toRead);

		write(outFd, buffer, n);

		received = received + n;
	}

	close(outFd);
	close(sock);

	if(received == fileSize)
		printf("Download complete\n");
	else
	{
		printf("Downalod failed\n");
		return -1;
	}

	return 0;
} // End of main
