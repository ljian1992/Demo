#include "commonheader.h"
#include "flight.h"

//打印作者信息
void print_auth_info (void)
{
	system ("clear");
    printf ("--------------------------------------------------------------\n");
	printf ("author:ljian\n");
	printf ("complete time:2014.11.18\n");
	printf ("version:2.0\n");
    printf ("--------------------------------------------------------------\n");
    printf ("press any key to continue...");
	getchar ();
	while ('\n' != getchar ());	
}

//打印欢迎信息
void print_welcome_menu (void)
{
    printf ("--------------------------------------------------------------\n");
	printf ("               welcome to filght check syste\n");
    printf ("--------------------------------------------------------------\n");
}

//打印选项信息
void print_options_menu (void)
{
	printf ("==============================================================\n");
	printf ("1:input flight     2:print flight info    3:check flight info\n");
	printf ("4:sort flight info 5:delete               6:auther info\n");
	printf ("7:exit\n");	
	printf ("==============================================================\n");
}

//打印输入航班信息
void print_input_info(void)
{
    system ("clear");
	printf ("==============================================================\n");
	printf ("                  flight information input\n");
	printf ("==============================================================\n");
}

void print_fli_info_menu (void)
{
	printf("%-8s  %-12s     %-12s  %-20s  %-20s  $%-9s\t%-s\n", "number", "start", "end", "start time", "arrival time", "price", "type");
}



//输入信息
void print_input_menu (FILE * fd, NODE * head)
{
	system ("clear");
	print_input_info ();
	input_flight_data (fd, head);
}

//打印航班信息
void print_fli_info (NODE * head)
{

	system ("clear");
	printf ("===========================================flight information========================================\n\n");
    print_fli_info_menu ();
	printf ("=====================================================================================================\n\n");
	show_kel_list (head);
	printf ("=====================================================================================================\n\n");
	printf ("press any key to continue...\n");
	getchar ();

	while ('\n' != getchar ());
}

//打印一个节点信息
void print_node_data (void(*function)(void), NODE * node)
{
    function ();
	print_node (node);
}

//查找信息
void print_find_menu (FILE * fd, NODE * head)
{
	int choice = -1;
	char choice_del_mod = -1;
	char yes_del = -1;
	char yes_mod = -1;
	char str[30];
	NODE *pTmp = NULL;
	POITER_NODE *poiter_pTmp = NULL;
	struct list_head *pos = NULL;

	//生成找到的相关链表
	POITER_NODE *poiter_head = init_poiter_list (); 

	system ("clear");

	printf ("=============================================find menu==============================================\n");
	printf ("1:by number            2:by start place            3:by arrival place\n");
	printf ("4:by airplane type     5:by price\n");
	printf ("=====================================================================================================\n");

	printf ("your choice[1--5]:");

	scanf ("%d", &choice);
	while ('\n' != getchar ());

	printf ("\ninput what you want to find:");
	scanf ("%s", str);
	while ('\n' != getchar ());

	//查找是否有相对应的信息
	find_data (head, poiter_head, str, choice);	


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


/*******************************删除与修改操作**************************************/
	if (poiter_head->list.next == &poiter_head->list)
	{

	}
	else
	{
		printf ("the next step: delete or modify (D/M)");
		scanf ("%c", &choice_del_mod);
		while ('\n' != getchar ());

		if ('d' == choice_del_mod || 'D' == choice_del_mod)
		{
			list_for_each (pos, &poiter_head->list)
			{

				system ("clear");
				poiter_pTmp = list_entry (pos, POITER_NODE, list);

				//打印出要删除的航班信息
				print_node_data (print_fli_info_menu, poiter_pTmp->poiter);

				printf ("do you want to detele it?(Y/N)");
				scanf ("%c", &yes_del);
				while ('\n' != getchar ());	

				if ('y' == yes_del || 'Y' == yes_del)
				{
					if (delete_data (fd, head, poiter_pTmp->poiter))   //删除相应的航班信息 
					{
						printf ("delete succee!\n");
						printf ("press any key to continue...");
						getchar ();
						while ('\n' != getchar ());
					}
				}

			}

		}
		else if ('m' == choice_del_mod || 'M' == choice_del_mod)
		{
			list_for_each (pos, &poiter_head->list)
			{

				system ("clear");
				poiter_pTmp = list_entry (pos, POITER_NODE, list);

				//打印出要修改的的航班信息
				print_node_data (print_fli_info_menu, poiter_pTmp->poiter);

				printf ("do you want to modify it?(Y/N)");
				scanf ("%c", &yes_mod);
				while ('\n' != getchar ());	

				if ('y' == yes_mod || 'Y' == yes_mod)
				{
					if (modify_data (fd, head, poiter_pTmp->poiter))  //修改相应的航班信息
					{
						printf ("modify succee!\n");
						printf ("press any key to continue...");
						getchar ();
						while ('\n' != getchar ());
					}
				}

			}
		}


	}
	
	//销毁链表
	destroy_poiter_link (poiter_head);

}

void print_sort_data (NODE * head)
{
 
	int choice = -1;
	system ("clear");

	printf ("=============================================sort menu===============================================\n");
	printf ("1:by number            2:by start place            3:by arrival place\n");
	printf ("4:by airplane type     5:by price\n");
	printf ("=====================================================================================================\n");
    printf ("input your choice:");

	scanf ("%d", &choice);
	while ('\n' != getchar ());

	
    list_sort (head, choice);	
}


void print_delete_menu (FILE *fd, NODE *head )
{
	system ("clear");
	char yes_del = 'n';
    int fd_fu = -1;
	print_fli_info_menu ();
    show_kel_list (head);	
    printf ("do you want to delete all flight record?(Y/N)");

	yes_del = (char )fgetc(stdin);
    while ('\n' != getchar ());

	if ('y' == yes_del || 'Y' == yes_del)
	{
       //清空记录航班信息的链表head
	   clear_data_link (head);

	   //清空记录文件中的内容	
	   fd_fu = fileno (fd);   //把文件指针转换成文件描述符
	   ftruncate (fd_fu, 0);	
       printf ("delete success!\n");
	   printf ("press any key to continue...");
	   getchar ();
	   while ('\n' != getchar ());
	}



}
