#include "commonheader.h"
#include <sys/wait.h>
#include <sys/types.h>

int main (void)
{
	pid_t re1, re2;
	int count = 0;

	//创建子进程
	if (0 > (re1 = fork ()))
	{
		printf ("Fork Error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);
	}
	else
	{
		//子进程睡眠5秒，然后正常退出
        if (0 == re1)
		{
			printf ("child sleep 5s\n");
			sleep (3);
			exit (EXIT_SUCCESS);
		}	
		else//父进程不断测试子进程退出
		{
			do 
			{
                re2 = waitpid (re1, NULL, WNOHANG);
				if (0 == re2)
				{   
					printf ("time: %d\n", ++count);
					printf ("the child process has not exited\n");
					sleep (1);
				}

			}while (0 == re2);
		}

		if (re1 == re2)
		{
            printf ("the child process has exited\n");
		}
	}
}
	

