#include "kernel_list.h"
#include "commonheader.h"
#include "flight.h"
#include "print.h"

/*******************航班数据链表操作函数****************/

//新建一个节点
NODE * new_node (void)
{
	NODE * newnode = malloc (sizeof (NODE));
	if (NULL == newnode)
	{
		exit (-1);
	}

	INIT_LIST_HEAD (&newnode->list);
	newnode->num = 0;

	return newnode;
	
}



//初始化一个链表，
NODE * init_list (void)
{
	NODE * head = new_node ();
	head->num = -1;

	return head;
}

//打印出一个节点的信息
void print_node (NODE * node)
{
	char buff[200];

	NODE *pNode = node;

	
	printf("%-8s  %-12s --> %-12s  %-20s  %-20s  $%-8.2f\t%c\n", 
				pNode->info.number,        //航班号
				pNode->info.startAddr,     //起点站
				pNode->info.arrAddr,       //终点站
				pNode->info.stime,         //起飞时间
				pNode->info.atime,         //到达时间
				pNode->info.price,         //价格
				pNode->info.type);	       //机型
}



void show_kel_list (NODE * head)
{
	struct list_head *pos;
	NODE *pNode = NULL;

	list_for_each (pos, &head->list)
	{
		pNode = list_entry (pos, NODE, list);
        print_node (pNode);
	}

}


void destroy_data_link (NODE * head)
{
	NODE * pTmp = NULL;
    struct list_head * pos = NULL;
	struct list_head * q = NULL;

	pos = head->list.next;
	while (pos != &head->list)
	{
		  q = pos;   //保存将要free掉的数据节点的内核链表指针

          pTmp = list_entry (pos, NODE, list);
		  free (pTmp);

		  pos = q->next;   //避免使用已经free的空间的数据
	}
	pTmp = list_entry (&head->list, NODE ,list);
	free (pTmp);
	head = NULL;

#if 0	
    list_for_each (pos, &head->list)
	{
		  q = pos;   //保存将要free掉的数据节点的内核链表指针

          pTmp = list_entry (pos, NODE, list);
		  free (pTmp);

		  pos = q;   //避免使用已经free的空间的数据
	}
#endif //0

}

//清空数据链表
void clear_data_link (NODE * head)
{
	NODE * pTmp = NULL;
    struct list_head * pos = NULL;
	struct list_head * q = NULL;

	pos = head->list.next;
	while (pos != &head->list)
	{
		  q = pos;   //保存将要free掉的数据节点的内核链表指针

          pTmp = list_entry (pos, NODE, list);
		  free (pTmp);

		  pos = q->next;   //避免使用已经free的空间的数据
	}
    INIT_LIST_HEAD (&head->list);


}

/*******************航班数据指针链表操作函数****************/

POITER_NODE * new_poiter_node (NODE * node_poiter)
{
     POITER_NODE * new = (POITER_NODE *)malloc (sizeof (POITER_NODE));
	 if (NULL == new)
	 {
		 perror ("create poiter_node error!\n");
		 exit (-1);
	 }

	 INIT_LIST_HEAD (&(new->list));
	 new->poiter = node_poiter;

	 return new;
}


POITER_NODE * init_poiter_list (void)
{
	POITER_NODE * head = (POITER_NODE *)malloc (sizeof (POITER_NODE));
	if (NULL == head)
	{
		perror ("create poiter_node error!\n");
		exit (-1);
	}

	 INIT_LIST_HEAD (&head->list);

	 head->poiter = NULL;

	 return head;
}

void show_poiter_list (POITER_NODE * head)
{
	struct list_head * pos = NULL;
	POITER_NODE * pTmp = NULL;

	list_for_each (pos, &head->list)
	{
		pTmp = list_entry (pos, POITER_NODE, list);
        print_node (pTmp->poiter);
	}

		
}

void destroy_poiter_link (POITER_NODE * head)
{

	POITER_NODE * pTmp = NULL;
    struct list_head * pos = NULL;
	struct list_head * q = NULL;

	pos = head->list.next;
	while (pos != &head->list)
	{
		  q = pos;   //保存将要free掉的数据节点的内核链表指针

          pTmp = list_entry (pos, POITER_NODE, list);
		  free (pTmp);

		  pos = q->next;   //避免使用已经free的空间的数据
	}
	pTmp = list_entry (&head->list, POITER_NODE, list);
	free (pTmp);
	head = NULL;
}


void poiter_list_data_exch (POITER_NODE *dest, POITER_NODE *src)
{
	NODE * tmp;
	tmp = src->poiter;
	src->poiter = dest->poiter;
	dest->poiter = tmp;
}


//将链表信息按照相应的顺序打印出来，注：链表的结点不做任何改动
void list_sort (NODE * head, int mode)
{
	char buff1[25];
	char buff2[25];

	int exchange = -1;  //置1代表发生一次交换
    struct list_head * posi = NULL;
	struct list_head * posj = NULL;

	NODE * pTmp = NULL;	
	POITER_NODE * pTmp1 = NULL;
	POITER_NODE * pTmp2 = NULL;
    POITER_NODE * pTmp3 = NULL;
	POITER_NODE * new = NULL;

	POITER_NODE *poiter_head = init_poiter_list ();

	//将数据链表的结点指针存进结点指针链表当中
    list_for_each (posi, &head->list)
	{
        pTmp = list_entry (posi, NODE, list);
		new = new_poiter_node (pTmp);

	    list_add_tail (&new->list, &poiter_head->list);
	}

	//将节点指针链表中的指针按要求从小到大排序
	list_for_each_prev (posi, &poiter_head->list)
	{
        exchange = 0;
		for (posj=poiter_head->list.next; posj != posi; posj = posj->next)
		{
			pTmp1 = list_entry (posj, POITER_NODE, list);
			pTmp2 = list_entry (posj->next, POITER_NODE, list);
            switch (mode)
			{
				case 1:   //  按照航班号排序输出o
					if (0 < strcmp (pTmp1->poiter->info.number, pTmp2->poiter->info.number))
					{
						poiter_list_data_exch (pTmp1, pTmp2);
						exchange = 1;
					}
					break;

				case 2:   //按照起点站排序输出
					if (0 < strcmp (pTmp1->poiter->info.startAddr, pTmp2->poiter->info.startAddr))
					{
						poiter_list_data_exch (pTmp1, pTmp2);
						exchange = 1;
					}

					break;

				case 3:   //按照终点站排序输出
					if (0 < strcmp (pTmp1->poiter->info.arrAddr, pTmp2->poiter->info.arrAddr))
					{
						poiter_list_data_exch (pTmp1, pTmp2);
						exchange = 1;
					}

					break;

				case 4:   //按照机型排序输出
					if (pTmp1->poiter->info.type > pTmp2->poiter->info.type)
					{
						poiter_list_data_exch (pTmp1, pTmp2);
						exchange = 1;
					}

					break;

				case 5:   //按照价格排序输出
					if (pTmp1->poiter->info.price > pTmp2->poiter->info.price)
					{
						poiter_list_data_exch (pTmp1, pTmp2);
						exchange = 1;
					}
					break;
				default:
				    break;	

			}
		}
        
		if (0 == exchange)
		{
			break;
		}
	}

	//打印排序好的结点信息
    printf ("sort complete!\n");
    print_fli_info_menu (); 	
	show_poiter_list (poiter_head);
	printf ("press any key to continue...");
	getchar ();
	while ('\n' != getchar ());

	//销毁节点指针链表
	destroy_poiter_link (poiter_head);
}
