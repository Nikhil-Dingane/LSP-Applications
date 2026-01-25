#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
	void *handle;
	int (*fp)(int, int);

	handle = dlopen("./libserver_1.so", RTLD_LAZY);

	if(handle == NULL)
	{
		printf("Unable to link dynamic library\n");
		return -1;
	}

	printf("Library successfull linked\n");

	fp = dlsym(handle, "Addition");
	
	if(fp == NULL)
	{
		printf("Unable to get function pointer");
		return -2;
	}
	printf("Addition is: %d\n", fp(10, 15));
	
	fp = dlsym(handle, "Substraction");
	
	if(fp == NULL)
	{
		printf("Unable to get function pointer");
		return -2;
	}
	printf("Substraction is: %d\n", fp(10, 15));

	dlclose(handle);
	return 0;
}
