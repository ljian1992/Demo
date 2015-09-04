/**********************************************************
2.��дһ�γ���ʹ��ϵͳ���ú���fork( )���������ӽ��̣�����ϵͳ���ú���signal( )
�ø����̲�׽�ź�SIGINT��Ҳ������kill������������������׽���ж��źź󣬸�������ϵ
ͳ���ú���kill( )�������ӽ��̷����źţ��ӽ��̲�׽�������̷������źź󣬷ֱ������
����Ϣ����ֹ��  
		Child process 1 is killed by parent!
		Child process 2 is killed by parent!
�����̵ȴ������ӽ�����ֹ�����������Ϣ����ֹ��
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
