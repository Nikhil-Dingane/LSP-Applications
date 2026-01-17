#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main()
{
	key_t key = 0;

	key = ftok("LSP.txt", 's');

	printf("key: %d\n", key);
	return 0;
}
