#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void * Demo(void *p)
{
	int iSum = 0;
	int *ptr = NULL;

	ptr = (int *)malloc(sizeof(int));

	printf("Inside thread with value: \n");
	iSum = (*((int *)p + 0) + *((int *)p + 1) + *((int *)p + 2) + *((int *)p + 3));
	*ptr = iSum;
	pthread_exit(ptr);
}

int main()
{
	pthread_t TID;
	int iRet = 0, *value = 0;
	int arr[] = {11, 21, 51, 101};

	printf("Main thread started\n");
	iRet = pthread_create(
		&TID,		// Thread ID
		NULL,		// Thread attributes
		Demo,		// Thread callback function
		(int *)arr		// Parameters fro the callback function
	);

	if(iRet == 0)
	{
		printf("Thread gets created successfully with TID: %lu\n", (unsigned long)TID);
	}

	pthread_join(TID, (void *)&value);

	printf("Summation is : %d\n", *value);

	printf("End of main thread\n");

	return 0;
}
