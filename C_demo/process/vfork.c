#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main (void)
{
    int a = 0;

	pid_t re = -1;

    
	if (-1 == (re = vfork()))
	{
		printf ("fork error: %s\n", strerror (errno));
		exit (1);
	}
	else
	{
		if (0 == re)
		{  
			sleep (1);
			printf ("in child process, pid = %d, ppid = %d\n", getpid (), getppid ());
			exit (EXIT_SUCCESS);  //不正常退出，会发生段错误
		}
		else
		{
			printf ("in father process, pid = %d\n", getpid ());
		
		}
	}

	return 0;
}
