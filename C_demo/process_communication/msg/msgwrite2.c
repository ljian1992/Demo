/****************************************************************************
消息队列的写：不断地向消息队列写入数据，直到写入end为止
*****************************************************************************/

#include "commonheader.h"
#include "msg.h"


int main (int argc, char *argv[])
{
	int msgid = -1;
	int senlen = -1;
	int running = 1;
	MSG msgtmp;

	//1.创建消息队列
	msgid = msgget ((key_t)123, 0666 | IPC_CREAT);
	if (0 > msgid)
	{
		printf ("msgget error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);	
	}

	//2.不断地向消息队列中写入数据
	while (running)
	{
		printf ("your msg:");

		memset (msgtmp.text, 0, sizeof (msgtmp.text));
		fgets (msgtmp.text, sizeof (msgtmp.text), stdin);
		msgtmp.type = 1;


		if (0 > (senlen = msgsnd(msgid, (void *)(&msgtmp), sizeof (msgtmp.text), 0)))
		{
			printf ("msgrcv error: %s\n", strerror (errno));
			exit (EXIT_FAILURE);	
		}

		if (0 == strncmp (msgtmp.text, "end", 3))
		{
			running = 0;
			continue;
		}

	}

/*	
	//3.删消息队列
	if (0 > msgctl (msgid, IPC_RMID, NULL))
	{
		printf ("msgctl error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);	
	}
*/

	pause ();

	return 0;
}
