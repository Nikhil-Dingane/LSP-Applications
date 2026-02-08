// Server Application

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

void sendFileToClient(int clientSocket, char* fileName)
{
	int fd = 0;
	struct stat sobj;
	char buffer[1024] = {'\0'};
	int bytesRead = 0;
	char header[64] = {'\0'};

	errno = 0;
	fd = open(fileName, O_RDONLY);

	if(fd == -1)
	{
		write(clientSocket, "ERR\n", 4);
		perror("open failed");
		return;
	}

	stat(fileName, &sobj);

	// header: "OK <file size>"
	snprintf(header, sizeof(header), "OK %ld\n", (long)sobj.st_size);

	// write header to client
	int iRet = write(clientSocket, header, strlen(header));

	// send actual file contents
	while((bytesRead = read(fd, buffer, 1024)) != 0)
	{
		write(clientSocket, buffer, bytesRead);
	}

	close(fd);
}

//////////////////////////////////////////////////////////////////////////////
//
//	Commandline Argument Application
//	1st Argument:	Port Number
//
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	int serverSocket = 0;
	int clientSocket = 0;
	int port = 0;
	int iRet = 0;
	int pid = 0;
	char fileName[50] = {'\0'};

	struct sockaddr_in serverAddr, clientAddr;
	socklen_t addrLen = sizeof(clientAddr);

	if(argc != 2)
	{
		errno = EINVAL;
		perror(argv[0]);
		printf("Usage: %s <port>\n", argv[0]);
		return -1;
	}

	// port number of server
	port = atoi(argv[1]);

	/////////////////////////////////////////////////////////////////////
	// Step 1: Create TCP socket
	/////////////////////////////////////////////////////////////////////

	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	if(serverSocket == -1)
	{
		perror("socket failed");
		return -1;
	}

	/////////////////////////////////////////////////////////////////////
	// Step 2: BInd socket to IP and port
	/////////////////////////////////////////////////////////////////////

	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	iRet = bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

	if(iRet == -1)
	{
		perror("bind failed");
		close(serverSocket);
		return -1;
	}

	/////////////////////////////////////////////////////////////////////
	// Step 3: Listen for client connection
	/////////////////////////////////////////////////////////////////////

	iRet = listen(serverSocket, 11);

	if(iRet == -1)
	{
		perror("listen failed");
		close(serverSocket);
		return -1;
	}

	printf("Server is running on the port %d\n", port);

	/////////////////////////////////////////////////////////////////////
	// Loop which accepts client requests continuiosuly
	/////////////////////////////////////////////////////////////////////

	// Loop to accept multiple client request
	while(1)
	{
		/////////////////////////////////////////////////////////////////////
		// Step 4: Accept the client request
		/////////////////////////////////////////////////////////////////////

		errno = 0;
		memset(&clientAddr, 0, sizeof(clientAddr));
		errno = 0;
		printf("Server is waiting for client request\n");
		clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen);

		if(clientSocket == -1)
		{
			perror("accept failed");
			continue;
		}

		printf("Client gets connected: %s\n", inet_ntoa(clientAddr.sin_addr));
		
		/////////////////////////////////////////////////////////////////////
		// Step 5: Create new process to handle new client request
		/////////////////////////////////////////////////////////////////////

		errno = 0;
		pid = fork();

		if(pid < 0)
		{
			perror("fork failed");
			close(clientSocket);
			continue;
		}

		// New process gets created
		if(pid == 0)
		{
			printf("New process is created for client request\n");
			close(serverSocket);
			iRet = read(clientSocket, fileName, sizeof(fileName));
			printf("Requested file name: %s\n", fileName);
			fileName[strcspn(fileName, "\r\n")] = '\0';
			sendFileToClient(clientSocket, fileName);
			printf("File transfer done & client disconnected\n");
			exit(0);
		}
		else
		{
			close(clientSocket);
		}

	} // End of while
	
	close(serverSocket);
	return 0;
} // End of main
