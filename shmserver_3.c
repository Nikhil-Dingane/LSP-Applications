#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<errno.h>

int main()
{
	int id = 0;
	char *ptr = NULL;
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

	*ptr = 'L';
	ptr++;

	*ptr = 'S';
	ptr++;

	*ptr = 'P';
	ptr++;

	*ptr = '\0';

	shmdt(ptr);

	return 0;
}
