/************************************************************************************************
 *PI函数编程一个程序，使之产生一个进程扇：父进程产生一系列子进程，
 *个子进程打印自己的PID然后退出。要求父进程最后打印PID。
 * **********************************************************************************************/
#include "commonheader.h"

void creat_child_procee (void)
{
	pid_t result = -1;

	if (0 > (result = fork ()))
	{
		printf ("fork error: %s\n", strerror (errno));
		exit (-1);
	}
	else
	{
		if (0 == result)
		{
			printf ("in child process pid = %d, ppid = %d\n", getpid (), getppid ());
			exit (0);
		}
		else
		{
			waitpid (result, NULL, 0);
		}
	}
}

int main (void)
{
    pid_t re[5];
    int i;

    for (i=0; i<5; ++i)
	{
        creat_child_procee ();	
	}
	printf ("father pid = %d\n", getpid ());

	return 0;
}
