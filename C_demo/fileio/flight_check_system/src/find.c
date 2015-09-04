#include "kernel_list.h"
#include "commonheader.h"
#include "flight.h"
#include "flight_link.h"
#include "print.h"
#include "find.h"



/********************************************************************
 *Function Name: find_data
 *Input:
     head:记录信息头指针
     poiter_head:指向记录信息链表节点的链表的头指针
     str：要查找的信息
     mode:查找方式 航班号: 1 起点站：2 终点站：3 机型：4 价格：5
 *Output:无
 *Note:用于查找信息链表中的数据
 *******************************************************************/
void find_data (NODE *head, POITER_NODE * poiter_head, const char *str, int mode)
{

	struct list_head * pos;
	NODE *pTmp = NULL;
	char type;

    //遍历链表进行对比
	list_for_each (pos, &head->list)
	{
         pTmp = list_entry (pos, NODE, list);

		 switch (mode)
		 {
              case 1:      //按航班号查找
				  if (0 == strcmp (str, pTmp->info.number))
				  {
					    POITER_NODE * new = new_poiter_node (pTmp);
                        list_add_tail (&new->list, &poiter_head->list); 
				  }
				  break;

			  case 2:     //按起点站
				  if (0 == strcmp (str, pTmp->info.startAddr))
				  {
					  POITER_NODE * new = new_poiter_node (pTmp);
					  list_add_tail (&new->list, &poiter_head->list); 
				  }
				  break;

			  case 3:     //按终点站
				  if (0 == strcmp (str, pTmp->info.arrAddr))
				  {
					  POITER_NODE * new = new_poiter_node (pTmp);
					  list_add_tail (&new->list, &poiter_head->list); 
				  }
				  break;

			  case 4:     //按机型
                  type = str[0]; 
				  if ( type == pTmp->info.type )
				  {
					  POITER_NODE * new = new_poiter_node (pTmp);
					  list_add_tail (&new->list, &poiter_head->list); 
				  }
				  break;
			
			  case 5:     //按价格，未实现
				  //根据价格区间查找
				  break;
              default:
				  break;
		 }

	}
	
#if 0
	//有找到相关信息则，输出信息头
   if (poiter_head->list.next != &poiter_head->list)
   {
	   printf ("the information you want to find\n"); 
	   print_fli_info_menu ();	  

   }

   if (poiter_head->list.next != &poiter_head->list) //找到则输出相关信息
   {
	   show_poiter_list (poiter_head);
   }
   else    //没有则提示没有	
   {
	   printf ("\nno flight data!\n");
	   printf ("press any key to continue...");
	   getchar ();
	   while ('\n' != getchar ());
   }
   printf ("press any key to continue...");
   getchar ();
   while ('\n' != getchar ());
#endif //0
}



/********************************************************************
 *Function Name: delete_data
 *Function Description:用于删除记录信息的链表中的数据和相对应的文件中的数据
 *Input:
     fd:记录文件的文件指针
     head:记录信息头指针
     delnode:要删除的节点
 *Output:无
 *Note:
 *******************************************************************/

bool delete_data (FILE *fd, NODE *head, NODE *delnode)
{

	int del_pos = -1;
    int file_num = -1;
	int tmp_num = -1;
	int i = 0;
	int nmen = -1;
    int fd_fu = -1;

	//获取要删除的数据在文件中的位置 从0开始算
    struct list_head *pos = &delnode->list;  
	NODE *pTmp = list_entry (pos, NODE, list);
	del_pos = pTmp->num;

	//获取在文件中总的个数据 从0开始算
	pos = head->list.prev;
	pTmp = list_entry (pos, NODE, list);
    file_num = tmp_num = pTmp->num;
    

   

    //1.从文件中删除相应的节点

	//1.1把文件中的位置指针移动到要删除的数据的位置
	fseek (fd, del_pos * sizeof(datatype), SEEK_SET);

	//1.2把将文件要删除的数据后面的数据向前移动一位，达到删除的目的		
	pos = delnode->list.next;		
	for (i=0; i<tmp_num-del_pos; i++)
	{
	    pTmp = list_entry (pos, NODE, list);

		nmen = fwrite ( (const void *)(&(pTmp->info)), sizeof (datatype), 1, fd );
		if ( 0 > nmen)
		{
			perror ("write info error!n");
			exit (-1);
		}
		fflush (fd);

		pos = pos->next;
	}
	
	//1.3改变文件的大小，以删除最后一个数据所占的空间
	fd_fu = fileno (fd);   //把文件指针转换成文件描述符
	ftruncate (fd_fu, file_num * sizeof (datatype));	

	//2.从数据链表删处节点
	//2.1把要删除的节点的后面的节点中保存的位置自减1
	for (pos = delnode->list.next;  pos != &head->list; pos = pos->next)
	{
		pTmp = list_entry (pos, NODE, list);
		pTmp->num--;
	}
	//2.2删除结点
	list_del (&delnode->list);
	

	return true;
}

bool modify_data (FILE *fd, NODE *head, NODE *modnode)
{

	int mod_pos = -1;
    int file_num = -1;
	int tmp_num = -1;
	int i = 0;
	int nmen = -1;
    int fd_fu = -1;


	//1.修改航班信息链表节点中的数据o
	printf ("start input flight data:\n");

	printf ("number:");
	scanf ("%s", modnode->info.number);

	printf ("start address:");
	scanf ("%s", modnode->info.startAddr);

	printf ("arrival address:");
	scanf ("%s", modnode->info.arrAddr);

	printf ("start time:");
	scanf ("%s", modnode->info.stime);

	printf ("arrival time:");
	scanf ("%s", modnode->info.atime);

	printf ("price:");
	scanf ("%f", &modnode->info.price);

	printf ("flight type:");
	while ('\n' != getchar ());
	scanf ("%c", &modnode->info.type);
	while ('\n' != getchar ());



	
	
	//2.把修改过的节点中的航班数据重新写入到文件中
	
	//2.1.获取要修改的数据在文件中的位置 从0开始算
    struct list_head *pos = &modnode->list;  
	NODE *pTmp = list_entry (pos, NODE, list);
	mod_pos = pTmp->num;

	//记录下文件指针的位置,无网络找不到相因的函数
	

	//2.2把文件中的位置指针移动到要修改数据的位置
	fseek (fd, mod_pos * sizeof(datatype), SEEK_SET);

	//2.3把修改好的数据重新写入文件中相应的位置
	write_node (modnode, fd);
	printf ("your input flight information:\n");
	
    //2.4打印出写入的数据
	print_node_data (print_fli_info_menu, modnode);

	//3.把文件指针移动到最后面
	fseek (fd, 0, SEEK_END);
	
	return true;

}
