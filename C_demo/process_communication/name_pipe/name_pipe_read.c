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


	if (0 > (fd = open (FILEPATH, O_RDONLY )))
	{
		printf ("open error: %s\n", strerror (errno));
		exit (-1);
	}

	memset (buf, 0, sizeof (buf));

    read (fd, buf, sizeof (buf));
    printf ("read info: %s", buf);

	close (fd);

	return 0;
}
