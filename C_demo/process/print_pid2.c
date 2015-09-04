/*************************************************************************************************
 *2、用进程相关API函数编写一个程序，使之产生一个进程链：父进程派生一个子进程后
     然后打印出自己的PID，然后退出，该子进程继续派生子进程，然后打印PID，然后退出，以此类推。
 要求：1实现一个父进程要比子进程先打印PID的版本。（即打印的PID一般是递增的）
      2实现一个子进程要比父进程先打印PID的版本。（即打印的PID一般是递减的）
 *************************************************************************************************/

#include "commonheader.h"

/************************************************************
 * 默认为子进程先打印
 * 定义了宏FATHER_FIRST则父进程先打印
 * *********************************************************/
void creat_link_child_process (int num)
{
	pid_t result = -1;

	if (0 > (result = fork ()))
	{
		printf ("fork error: %s\n", strerror (errno));
		exit (-1);
	}

	if (0 == result)
	{

        #ifdef FATHER_FIRST
		sleep (1);
		printf ("process pid = %d, ppid = %d\n", getpid (), getppid ());
        #endif //FATHER_FIRST	

		if (num > 1)
		{
			creat_link_child_process (--num);
		}

        #ifndef FATHER_FIRST
		sleep (1);
		printf ("process pid = %d, ppid = %d\n", getpid (), getppid ());
        #endif //FATHER_FIRST		

		exit (0);

	}
	else
	{
		waitpid (result, NULL, 0);
	}
	
}

int main (void)
{
	creat_link_child_process (3);


	return 0;
}


