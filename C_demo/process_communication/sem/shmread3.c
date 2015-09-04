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


//初始化一个信号量
//semid：信号量描述符
//number:第几个信号量
//val:设置的初始值
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
     SHARE * pShare = NULL;
     key_t semkey = ftok ("/home/ljian/sem/2.c", 1);
	 int semId;
	 int get;
	 

	printf ("semkey: %d\n", semkey);

	//创建或打开信号量集合，里面的信号量默认值为0
	semId = semget ((key_t )semkey, 2, 0666|IPC_CREAT);
    if (0 > semId)
	{
 		printf ("semget error: %s\n", strerror (errno));
 		exit (1);

	}	
	printf ("read semId: %d\n", semId); 


	//新建共享内存
 	shmId = shmget ((key_t)1234, sizeof (SHARE), 0666 | IPC_CREAT);
 	if (0 > shmId)
 	{
 		printf ("shmget error: %s\n", strerror (errno));
 		exit (1);
 	}

	//映射共享内存
	pShare = (SHARE *)shmat (shmId, NULL, 0);
    if ((SHARE *)-1 == pShare)
    {
		printf ("shmat error: %s\n", strerror (errno));
 		exit (1);
    }

	//通过轮询的方式读取信息
	while (running)
	{
			//获取读的信号量
			sem_p (semId, 0);
			if (0 == (strncmp (pShare->text, "end", 3)))
			{
				running = 0;				
				continue;
			}
			else	
			{
				printf ("get msg: %s", pShare->text);
				memset (pShare->text, 0, sizeof(pShare->text));
			}

			//释放写的信号量
			sem_v (semId, 1);
	
	}

	//断开映射
	if (0 > shmdt ((const void *)pShare))
	{
		printf ("shmdt error: %s\n", strerror (errno));
		exit (1);
	}


	//删除信号量集合
	semctl (semId,0,IPC_RMID);

	//删除共享内存
	shmctl (shmId, IPC_RMID, NULL);

	return 0; 
}
