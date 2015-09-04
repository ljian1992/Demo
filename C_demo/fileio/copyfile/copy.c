#include "commonheader.h"

#define BUF_SIZE 100

int main (int argc, char *argv[])
{
	int ReadSize = 0;
	char buf[BUF_SIZE];

	//判断是否输入复制的文件及复制后的文件名
	if (3 != argc)
	{
		fprintf (stdout, "error!\n");
	}

	//打开复制的文件
	int fSrc = open (argv[1], iO_RDONLY, 0666);
    int fDet = open (argv[2], O_WRONLY | O_CREAT, 0666);


	//开始复制文件
	off_t FileSize = lseek (fSrc, 0, SEEK_END);	
	lseek (fSrc, 0, SEEK_SET);
	
	while (FileSize > 0)
	{
		bzero (buf, sizeof(buf));
		ReadSize = read (fSrc, buf, sizeof (buf)); 
		write (fDet, buf, ReadSize);
		FileSize -= ReadSize;

	}

	printf ("copy complete!\n");

	//关闭复制的文件和复制后的文件
	close (fDet);
	close (fSrc);
	
	
}

