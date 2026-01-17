#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>

#define MAXTEXT 512

struct MarvellousMessage
{
	long int msg_type;
	char data[MAXTEXT];
};

int main()
{
	key_t key;
	int id = 0, iRet = 0;
	struct MarvellousMessage mobj;

	key = ftok(".", 'a');

	id = msgget(key, 0666 | IPC_CREAT);

	if(id == -1)
	{
		perror("Unable to allocate the message queue");
		return -1;
	}

	mobj.msg_type = 11;
	strcpy(mobj.data, "Jay Ganesh...");

	iRet = msgsnd(id, (void *)&mobj, MAXTEXT, 0);

	if(iRet == 0)
		printf("Message sent successfully\n");
	else
	{
		perror("Unable to send to message");
		return -1;
	}

	return 0;
}
