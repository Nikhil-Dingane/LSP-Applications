#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main()
{
	void *current_break = NULL;
	int ret = 0;

	current_break = sbrk(0);
	printf("Current process break: %p\n", current_break);

	brk((char *)current_break + 100);
	strcpy((char *)current_break, "Jay Ganesh...");
	printf("Data from new memory: %s\n", (char *)current_break);

	brk((char *)current_break);

	return 0;
}
