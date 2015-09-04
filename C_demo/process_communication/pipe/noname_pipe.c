#include "commonheader.h"

#define TIME 1000000

int main (int argc, char *argv[])
{
	pid_t pd;
	char buf[100];
	int i;
	int count = 0;

	//创建无名管道
	int fd[2];
	if(0 > pipe (fd))
	{
		printf ("pipe error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);
	}

	//创建子进程
	if (0 > (pd = fork ()))
	{
		printf ("pipe error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);
	} 



	if (0 == pd) //子进程读数据
	{
		//关闭写端
		close (fd[1]);
	
		//读取数据
		for (i=0; i<TIME; ++i)
		{
			bzero (buf, sizeof (buf));
			read (fd[0], buf, sizeof(buf));
			printf ("count: %d\tread info from father: %s",++count, buf);
		}



		//关闭读端
		close (fd[0]);
		exit (EXIT_SUCCESS);
	}
	else  //父进程写数据
	{
		close (fd[0]);

		bzero (buf, sizeof (buf));
		strcpy (buf, "I hate this!\n");
		for (i=0; i<TIME; i++)
		{
			write (fd[1], buf, sizeof (buf));  
		}
		

		waitpid (pd, NULL, 0);
		close (fd[1]);
	}


	return 0;
}
