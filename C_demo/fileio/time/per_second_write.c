/********************************************************
作用：编程读写一个文件 test.txt，每隔 1 秒向文件中写入一行数据，类似这样
	  该程序应该无限循环，直到强制中断该进程为止（比如按 Ctrl-C 中断程序） 。接着再启
      动程序，将系统时间追加到原文件之后，并且序号能够接续上次的序号 
********************************************************/ 
#include "commonheader.h"

#define SIZE 100

int main (void)
{
	time_t t;
	char buf[SIZE];
	unsigned int count = 0;
	int tmp = 0;

	//1.以追加的形式打开记录文件，没有该文件则在当前目录下创建该文件
	FILE *pfd = fopen ("time_record", "a+");
	if (NULL == pfd)
	{
		printf ("open error!\n");
		exit (-1);
	}

	//2.获取序号 ，  
	//实验证明：fseek()返回-1出错了，它还是改变文件的位置指针， 函数运行之后出错后不应该接受它的处理结果

	if (-1 == fseek(pfd, -40, SEEK_END))   
	{                                     
		fseek(pfd, 0, SEEK_SET);     //当只有一行或没有时，把文件位置指针移到最开头
		fscanf (pfd, "%d", &count);
		count++;
	}
	else
	{
		//2.1把文件位置指针移动到最后一行的开始处
		while ('\n' != (char)fgetc(pfd))
			;

		fscanf (pfd, "%d", &count);
		count++;
	}


	//3.把文件位置指针指向文件末尾
	fseek (pfd, 0, SEEK_END);
	

	//4.每隔一秒向pfd所指向的文件写入序列和时间，并向终端输出写入的内容
	while (1)
	{
	
	   //4.1清空重用的buf
	   bzero (buf, sizeof(buf));
	   
	   //4.2获取时间并打印到pfd所指向的文件的缓存中
       time(&t);
	   sprintf(buf, "%d\t%s", count, ctime(&t));
	   if ( 0 > (tmp = fprintf (pfd, "%s", buf)) )
	   {
		   printf ("write error!\n"); 
		   printf ("error info: %s\n", strerror(errno));
	   }

	   //4.3清空缓存使到数据写入到pfd所指向的文件
	   fflush (pfd);

	   //4.4打印写入的数据
	   fprintf (stdout, "%s", buf);
	   count++;

   	   //4.5延时1s
	   sleep (1);
	}

	//5关闭文件
	fclose (pfd);

	return 0;
}
