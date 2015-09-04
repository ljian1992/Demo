/*****************************************************
 *实现：利用无名管道实现 ls -l | grep
 *注:grep若没有指定从那里搜索，将会从标准输入中搜索
 * ****************************************************/
#include "commonheader.h"

int main (int argc, char *argv[])
{
	int fd[2];
	pid_t pid;

	if (0 > pipe (fd))
	{
		printf ("pipe error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);
	}

	if (0 > (pid = fork ()))
	{
		printf ("pipe error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);
	}

	//子进程调用grep命令
	if (0 == pid)
	{
       dup2 (fd[0], 0);//修改标准输入为管道的读端
       close (fd[1]);
	   close (fd[0]);

	   if (0 > execl ("/bin/grep", "grep",argv[1], NULL))
	   {
		   printf ("execl error: %s\n", strerror (errno));
		   exit (EXIT_FAILURE);
	   }
	   exit (EXIT_SUCCESS);

	}

	//父进程调用ls -l命令
	else
	{

		dup2 (fd[1], 1); //修改标准输出为管道写端
        close (fd[0]);
		close (fd[1]);
		if (0 > execl ("/bin/ls", "ls", "-l", NULL))
		{
			printf ("execl error: %s\n", strerror (errno));
			exit (EXIT_FAILURE);
		}

	}
	return 0;
}


