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

	id = msgget(key, 0666);

	if(id == -1)
	{
		perror("Unable to allocate the message queue");
		return -1;
	}

	while(1)
	{
		memset(mobj.data, '\0', MAXTEXT);
		iRet = msgrcv(id, (void *)&mobj, MAXTEXT, 11, 0);
		printf("Received message data from server:\n%s\n", mobj.data);

		if(iRet == -1)
		{
			perror("Unable to receive the message");
			return -1;
		}

		if(strncmp(mobj.data, "end", 3) == 0)
			break;
	}


	return 0;
}
