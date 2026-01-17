#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
	char arr[100] = {'\0'};
	fgets(arr,sizeof(arr),stdin);
	printf("data received : %s\n", arr);
	return 0;
}
