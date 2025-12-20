#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

int main()
{
	int iRet = 0;
	DIR* dir = NULL;
	struct dirent* direntry = NULL;

	dir = opendir("./Data");
	
	if(dir == NULL)
	{
		printf("Unable to open directory.\n");
		printf("%s\n", strerror(errno));
		return -1;
	}

	errno = 0;
	while((direntry = readdir(dir)) != NULL && errno == 0)
	{
		// fd = open();
		// iRet = read();
		printf("Inode number: %ld\n", direntry->d_ino);
		printf("Inode name: %s\n", direntry->d_name);
	}

	closedir(dir);

	return 0;
}
