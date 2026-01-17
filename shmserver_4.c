#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<errno.h>

int main()
{
	int id = 0;
	char *ptr = NULL, *start = NULL;
	key_t key = 0;
	key = ftok(".", 's');

	id = shmget(key, 1024, 0666 | IPC_CREAT);

	if(id == -1)
	{
		perror("Unable to allocate the shared memory");
		return -1;
	}

	ptr = shmat(id, NULL, 0);

	if(ptr == (char *)-1)
	{
		perror("Unable to attach the memory");
		return -2;
	}
	
	start = ptr;
	for(char c = 'a'; c <= 'z'; c++, ptr++)
		*ptr = c;
	
	*ptr = '\0';
	
	printf("Data is successfully written to the shared memory by the server\n");

	while(*start != '*')
		sleep(1);
	
	printf("Data is successfully fetched by the client\n");

	shmdt(ptr);

	return 0;
}
