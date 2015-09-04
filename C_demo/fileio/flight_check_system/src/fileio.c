#include "kernel_list.h"
#include "flight.h"
#include "commonheader.h"
#include "flight_link.h"
#include "print.h"


void dadatype_copy (datatype *dest, datatype *src)
{
	strcpy (dest->number, src->number);
	strcpy (dest->startAddr, src->startAddr);
	strcpy (dest->arrAddr, src->arrAddr);
	strcpy (dest->stime, src->stime);
	strcpy (dest->atime, src->atime);

	dest->type = src->type;
	dest->price = src->price;
}

void write_node (NODE * node, FILE * fd)
{
	ssize_t nmenber = 0;
    int file_exist = 0;

	datatype data;
	dadatype_copy (&data, &(node->info));	


	//写入数据
	nmenber = fwrite ((const void *)(&data), sizeof (datatype), 1, fd);
	if (1 > nmenber)
	{
		perror ("write error!\n");
		exit (-1);
	}	
	fflush (fd);
}


//从data.txt中读取航班信息，并形成链表，最后返回链表的头指针
NODE * read_flight_info (FILE * fd, NODE * head)
{
	ssize_t nmember = 0;
	int count = 0;                //记录读取到的节点的数目
	NODE *pTmp= new_node ();

	//读出数据节点并形成链表
	while ( 0 != (nmember = fread ((void *)(&(pTmp->info)), sizeof (datatype), 1, fd)) )
	{
		pTmp->num = count++;
		list_add_tail (&pTmp->list, &head->list);
		pTmp = new_node ();
	}

	//free掉多余的节点
	free (pTmp);

	LOG ("hey jude");
#ifdef DEBUG	
	printf ("count = %d\n", count);
#endif 	


	return head;
}

//输入数据并存进记录文件中
void input_flight_data (FILE * fd, NODE *head)
{
	char flag = 'n';
	struct list_head *pos = NULL;;
	NODE *pTmp = NULL;

	do
	{
		//读取用户输入的航班信息到结构体中
		NODE * new = new_node ();

	    printf ("start input flight data:\n");

		printf ("number:");
		scanf ("%s", new->info.number);
		
		printf ("start address:");
		scanf ("%s", new->info.startAddr);

		printf ("arrival address:");
		scanf ("%s", new->info.arrAddr);

		printf ("start time:");
		scanf ("%s", new->info.stime);

		printf ("arrival time:");
		scanf ("%s", new->info.atime);

		printf ("price:");
		scanf ("%f", &new->info.price);

		printf ("flight type:");
		while ('\n' != getchar ());
		scanf ("%c", &new->info.type);
		while ('\n' != getchar ());

		pos = head->list.prev;
		pTmp = list_entry (pos, NODE , list);
		new->num = pTmp->num +1;

		//把用户输入的数据节点添加到链表尾部
		list_add_tail (&new->list, &head->list);

		//把用户输入的数据节点写入记录文件
        write_node (new, fd);

		printf ("your input flight information:\n");
		print_fli_info_menu ();
		print_node (new);

	
		printf ("\none flight informaintion input complete, input more(Y/N)");
		scanf ("%c", &flag);

		//清除'\n'符号
	    while ('\n' != getchar ());

	}while(('y' == flag) || ('Y' == flag));


	
}

