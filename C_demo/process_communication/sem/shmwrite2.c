#include "commonheader.h"
#include "shm.h"

int main (int argc, char *argv[])
{
	int shmId = -1;
	int running = 1;
	SHARE *pshm = NULL;
	void *tmp = (void *)0;
	key_t semkey = ftok ("/home/ljian/vimrc", 123);
	int semId;
	int get;
	struct sembuf sembuff;

	printf ("semkey: %d\n", semkey);
	semId = semget (semkey, 1, 0666 | IPC_CREAT);
	if (0 > semId)
	{
		printf ("semget error: %s\n", strerror (errno));
		exit (1);
	}
	printf ("write semId: %d\n", semId);

	//1.创建或打开共享内存
	shmId = shmget ((key_t)1234, sizeof (SHARE), 0666 | IPC_CREAT);
	if (0 > shmId)
	{
		printf ("shmget error: %s\n", strerror (errno));
		exit (1);
	}

	//2.映射共享内存
	pshm = (SHARE *)shmat (shmId, NULL, 0);
	if ((SHARE *)-1 == pshm)
	{
		printf ("shmat error: %s\n", strerror (errno));
		exit (1);
	}

	semctl (semId, 0, SETVAL,1);
	//3.轮询地写入数据
	while (running)
	{
		sembuff.sem_num = 0;
		sembuff.sem_op = -1;
		sembuff.sem_flg = SEM_UNDO;


		if (1 == (get = semctl (semId, 0, GETVAL)))
		{
		    printf ("input your msg: ");
	     	fgets (pshm->text, sizeof (pshm->text), stdin);

			semop (semId, &sembuff, 1);
     		if (0 == strncmp (pshm->text, "end", 3))
    		{        	
				running = 0;
    			continue;
    		}

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
