#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/msg.h>
#include<sys/ipc.h>

int main()
{
	key_t key;
	int id = 0;

	key = ftok(".", 'a');

	id = msgget(key, 0666);

	if(id == -1)
	{
		perror("Unable to allocate the message queue");
		return -1;
	}

	return 0;
}
