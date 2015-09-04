/*************************************************************
有名管道例子：
有名管道进行：写操作
*************************************************************/
#include "commonheader.h"

#define FILEPATH "./fifo"
#define SIZE 20

int main (int argc, char *argv[])
{
	int fd;
    char buf[SIZE];
	
   
	
	if (0 > mkfifo (FILEPATH, O_CREAT | 0666))
	{
        printf ("mkfifo error: %s\n", strerror (errno));
		exit (-1);
	}


	if (0 > (fd = open (FILEPATH, O_WRONLY)))
	{
		printf ("open error: %s\n", strerror (errno));
		exit (-1);
	}

	memset (buf, 0, sizeof (buf));
	strcpy (buf, "I hate her!\n");

    write (fd, buf, sizeof (buf));
		


	close (fd);
	unlink (FILEPATH);

	return 0;
}
