/****************************************************************************
消息队列的写: 先发送消息到写端，在从写端获取消息，输入"end\n"后，退出等待读
              端发送信号，结束程序
              消息类型：1-->写端发送
                        2-->读端发送
*****************************************************************************/

#include "commonheader.h"
#include "msg.h"

void func (int sig)
{ 
}

int main (int argc, char *argv[])
{
	int msgid = -1;
	int senlen = -1;
	int rcvlen = -1;
	int running = 1;
	MSG msgtmp;

	key_t semkey = ftok ("/home/ljian/sem/6.c", 12);
	pid_t pid;


	//1.创建消息队列
	msgid = msgget ((key_t)123, 0666 | IPC_CREAT);
	if (0 > msgid)
	{
		printf ("msgget error: %s\n", strerror (errno));
		exit (EXIT_FAILURE);	
	}

	signal (SIGINT, func);


    while (running)
    {


        memset (msgtmp.text, 0, sizeof(msgtmp.text));
        printf ("input msg:");
        fgets (msgtmp.text, sizeof (msgtmp.text), stdin);
        msgtmp.type = 1;


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

        if (0 > (rcvlen = msgrcv(msgid, (void *)(&msgtmp), sizeof (msgtmp.text), 2, 0)))
        {
            printf ("msgrcv error: %s\n", strerror (errno));
            exit (EXIT_FAILURE);	
        }

        if (0 == strncmp (msgtmp.text, "end\n", 4))
        {
            running = 0;
            continue;
        }
        else
        {
            printf ("msg:%s", msgtmp.text);
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

    //等待读进程发送关闭信号过来
    pause ();

    return 0;
}
