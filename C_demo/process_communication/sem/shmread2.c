#include "commonheader.h"
#include "shm.h"

int main (int argc, char *argv[])
{

     int shmId = -1;
     int running = 1;
     SHARE * pShare = NULL;
     key_t semkey = ftok ("/home/ljian/vimrc", 123);
	 int semId;
	 int get;
	 struct sembuf obtain, release;

	 printf ("semkey: %d\n", semkey);
	semId = semget (semkey, 1, 0666|IPC_CREAT);
    if (0 > semId)
	{
 		printf ("semget error: %s\n", strerror (errno));
 		exit (1);

	}	
	printf ("read semId: %d\n", semId); 


	//1新建共享内存
 	shmId = shmget ((key_t)1234, sizeof (SHARE), 0666 | IPC_CREAT);
 	if (0 > shmId)
 	{
 		printf ("shmget error: %s\n", strerror (errno));
 		exit (1);
 	}

	//2映射共享内存
	pShare = (SHARE *)shmat (shmId, NULL, 0);
    if ((SHARE *)-1 == pShare)
    {
		printf ("shmat error: %s\n", strerror (errno));
 		exit (1);
    }

	//3通过轮询的方式读取信息
	while (running)
	{
		release.sem_num = 0;
		release.sem_op = 1;
		release.sem_flg = SEM_UNDO;

		if (0 == (get = semctl (semId, 0, GETVAL)))
		{
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
			semop (semId, &release, 1);
		}
	
	}

	//4断开映射
	if (0 > shmdt ((const void *)pShare))
	{
		printf ("shmdt error: %s\n", strerror (errno));
		exit (1);
	}

	semctl (semId,0,IPC_RMID);
	//5删除共享内存
	shmctl (shmId, IPC_RMID, NULL);

	return 0; 
}
