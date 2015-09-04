#include "commonheader.h"
#include "shm.h"

int main (int argc, char *argv[])
{

     int shmId = -1;
     int running = 1;
     SHARE * pShare = NULL;
     
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
		if (1 == pShare->can_read)
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
				pShare->can_write = 1;
				pShare->can_read = 0;
			}
			
		}
	}

	//4断开映射
	if (0 > shmdt ((const void *)pShare))
	{
		printf ("shmdt error: %s\n", strerror (errno));
		exit (1);
	}

	//5删除共享内存
	shmctl (shmId, IPC_RMID, NULL);

	return 0; 
}
