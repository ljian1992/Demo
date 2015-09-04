#include "commonheader.h"

#define SIZE 100

int main (int argc, char *argv[])
{
	char buf[100];
	size_t nmemb = 0;

	if (argc != 3)
	{
		fprintf(stderr, ""); 
		exit (-1);
	}

	FILE *fdSrc = fopen (argv[1], "r");
	FILE *fdDet = fopen (argv[2], "w");

	while( !feof(fdSrc) )
	{
		bzero (buf, sizeof(buf));
		fgets (buf, sizeof(buf), fdSrc);
		fputs (buf,fdDet);

    }

	printf ("copy complete!\n");
	

	return 0;
}
