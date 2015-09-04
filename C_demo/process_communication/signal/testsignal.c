/**********************************************************
2.编写一段程序，使用系统调用函数fork( )创建两个子进程，再用系统调用函数signal( )
让父进程捕捉信号SIGINT（也可以用kill命令来触发），当捕捉到中断信号后，父进程用系
统调用函数kill( )向两个子进程发出信号，子进程捕捉到父进程发来的信号后，分别输出下
列信息后终止：  
		Child process 1 is killed by parent!
		Child process 2 is killed by parent!
父进程等待两个子进程终止后，输出以下信息后终止：
        Parent process exit!

***********************************************************/ 

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

void childfun(int sig)
{

}

void myfun(int sig)
{
	if(sig==SIGINT)
		printf("I have got SIGKILL\n");
}

int main(void)
{
	int i;
	pid_t f[2];
	for(i=0;i<2;i++)
	{
		f[i]=fork();
		if(f[i]==0)
		{
			signal(SIGINT,childfun);
			pause();
			printf("Child process %d is killed by parent!\n",i+1);
			exit(0);
		}
	}

	printf("Waiting for signal SIGKILL\n");
	signal(SIGINT,myfun);

	sleep (2);
	raise (SIGINT);

	kill(f[0],SIGINT);
	waitpid (f[0], NULL, 0);

	kill(f[1],SIGINT);
	waitpid (f[1], NULL, 0);

	printf("Parent process exit!\n");
	exit(0);
}
