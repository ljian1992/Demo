/****************************************************************************
消息队列的读写：先从读端获取信息，再写入信息等写端读出，反复执行，直到接收到
                写端发送过来的"end\n"
                消息类型：1-->写端发送的
                          2-->读端接收
 *****************************************************************************/

#include "commonheader.h"
#include "msg.h"

int main (int argc, char *argv[])
{
	int msgid = -1;
	int rcvlen = -1;
	int senlen = -1;
	int running = 1;
	int semid;
	struct msqid_ds msq;
	MSG msgtmp;
 	pid_t pid;


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

        printf ("msg:%s", msgtmp.text);


        memset (msgtmp.text, 0, sizeof(msgtmp.text));
        printf ("input msg:");
        fgets (msgtmp.text, sizeof (msgtmp.text), stdin);
        msgtmp.type = 2;


        if (0 > (senlen = msgsnd(msgid, (void *)(&msgtmp), sizeof (msgtmp.text), 0)))
        {
            printf ("msgrcv error: %s\n", strerror (errno));
            exit (EXIT_FAILURE);	
        }

        if (0 == strncmp (msgtmp.text, "end\n", 4))
        {
            running = 0;
            continue;
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
