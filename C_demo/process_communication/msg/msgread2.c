/****************************************************************************
消息队列的读：不断地向消息队列读取数据，直到读取到end为止
*****************************************************************************/

#include "commonheader.h"
#include "msg.h"


int main (int argc, char *argv[])
{
	int msgid = -1;
	int rcvlen = -1;
	int running = 1;
	struct msqid_ds msq;
	MSG msgtmp;

	//1.创建消息队列
	msgid = msgget ((key_t)123, 0666 | IPC_CREAT);
	if (0 > msgid)
	{
		printf ("msgget error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);	
	}

	//2.采用轮询的方式从消息队列中读取值
	while (running)
	{
		if (0 > (rcvlen = msgrcv(msgid, (void *)(&msgtmp), sizeof (msgtmp.text), 1, 0)))
		{
			printf ("msgrcv error: %s\n", strerror (errno));
			exit (EXIT_FAILURE);	
		}

		if (0 == strncmp (msgtmp.text, "end", 3))
		{
			running = 0;
			continue;
		}
		else
		{
			printf ("the msg: %s", msgtmp.text);
		}

	}

	//获取消息队列的状态，以便获取最后一个向消息队列写入数据的进程的pid
	msgctl (msgid, IPC_STAT, &msq);
	
	//3.删消息队列
	if (0 > msgctl (msgid, IPC_RMID, NULL))
	{
		printf ("msgctl error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);	
	}
	
	kill (msq.msg_lspid, SIGKILL);
	return 0;
}
