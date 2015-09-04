/******************************************************************************
创建共享内存通过信号量来对共享内存的访问进行控制
设置两个信号量：
		信号量0：为读控制信号量，为1时可读， 0不可读
		信号量1：为写控制信号量，为1时可写，0的时候不可写
要达到的效果：读要等到写进程，写入数据后才能读
			  写要等到读进程，把数据读走之后才能读

******************************************************************************/

#include "commonheader.h"
#include "shm.h"

void init_sem (int semid, int number, int val)
{
	semctl (semid, number, SETVAL, val);
}


/******************************************************************
函数名：sem_p
功能：获取信号量
参数:
		semid:信号量描述符
		num:要获取的信号量
返回值；成功返回1 失败返回0
注意：无
*******************************************************************/
int  sem_p (int semid, int num)
{
	struct sembuf sops;
	sops.sem_num = num;
	sops.sem_op = -1;
	sops.sem_flg = SEM_UNDO;


	if (0 > semop (semid, &sops, 1))
		{
			printf ("semop error: %s\n", strerror (errno));
			return 0; 
		}

	return 1;	
}



/******************************************************************
函数名：sem_v
功能：释放信号量
参数:
		semid:信号量描述符
		num:要释放的信号量
返回值；成功返回1 失败返回0
注意：无
*******************************************************************/
int sem_v (int semid, int num)
{
	struct sembuf sops;
	sops.sem_num = num,
	sops.sem_op = 1;
	sops.sem_flg = SEM_UNDO;

	if (0 > semop (semid, &sops, 1))
	{
		printf ("semop error: %s\n", strerror (errno));
		return 0; 
	}

	return 1;
}

int main (int argc, char *argv[])
{
	int shmId = -1;
	int running = 1;
	SHARE *pshm = NULL;
	void *tmp = (void *)0;
	key_t semkey = ftok ("/home/ljian/sem/2.c", 1);
	int semId;
	int get;
	struct sembuf sembuff;

	printf ("semkey: %d\n", semkey);
	semId = semget (semkey, 2, 0666 | IPC_CREAT);
	if (0 > semId)
	{
		printf ("semget error: %s\n", strerror (errno));
		exit (1);
	}
	printf ("write semId: %d\n", semId);

	//可读操作设置为0
	init_sem (semId, 0, 0);

	//可写操作设置为1
	init_sem (semId, 1, 1);


	//创建或打开共享内存
	shmId = shmget ((key_t)1234, sizeof (SHARE), 0666 | IPC_CREAT);
	if (0 > shmId)
	{
		printf ("shmget error: %s\n", strerror (errno));
		exit (1);
	}

	//映射共享内存
	pshm = (SHARE *)shmat (shmId, NULL, 0);
	if ((SHARE *)-1 == pshm)
	{
		printf ("shmat error: %s\n", strerror (errno));
		exit (1);
	}

	//轮询地写入数据
	while (running)
	{
		

		//获取写的信号量，
		sem_p (semId, 1);

		printf ("input your msg: ");
	    fgets (pshm->text, sizeof (pshm->text), stdin);

	    //释放读的信号量，让读进程可读
	    sem_v (semId, 0);
		
     	if (0 == strncmp (pshm->text, "end", 3))
    	{        	
			running = 0;
    		continue;
    	}

       
	}

	//4.断开映射
	if (0 > shmdt ((const void *)pshm))
	{
		printf ("shmdt error: %s\n", strerror (errno));
		exit (1);
	}
	
	return 0;

}
