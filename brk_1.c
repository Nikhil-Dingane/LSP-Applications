#include<stdio.h>
#include<unistd.h>

int main()
{
	void *ptr = NULL;

	ptr = sbrk(0);
	printf("Current break value: %p\n", ptr);

	return 0;
}
