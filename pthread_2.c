#include<stdio.h>

void Demo(int *p)
{
	*p = 11;
	*(p+1) = 21;
}

int main()
{
	int arr[2];
	Demo(arr);
	printf("Return value is: %d %d\n", arr[0], arr[1]);
	return 0;
}
