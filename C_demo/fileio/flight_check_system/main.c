/*****************************************************************************************
 *项目名：航班查询系统
 *说明：
 *1.该项目存在两种链表，均为Linux内核链表，一个存储航班信息的链表，一个存储指向航班信息节点的指针链表
 *  由于记录文件中的信息是顺序的，而链表是链式的，故在航班信息节点中设置一个位置值来表示航班信息在文件中的数据
 *
 *2.程序运行之后，从记录航班数据的文件读取出数据，并形成航班信息链表，航班信息链表的数据顺序和航班数据的文件
 *中的数据严格一致(顺序和值)，然后进行相关操作：遍历，查找，插入，排序，删除。退出程序之前销毁链表和关闭航班数据文件，
 *以达到单入口单出口的设计思想。
 *
 *3.相关操作说明：
 *  3.1.录入航班信息：把航班数据节点插入航班信息链表的末尾，并且写入记录文件的末尾
 *  3.2显示航班信息：遍历航班信息链表，依次输出里面的航班信息
 *  3.3查找航班信息：提供五种方式进行查找。查找之前建立一个指向航班信息节点的指针链表，找到一个符合的信息，则把该
 *     节点的指针，添加到航班信息节点指针链表后面，然后通过航班信息节点指针链表输出查找到符合要求的值。最后提供
 *     删除航班信息和修改航班信息的操作。最后摧毁掉航班信息节点指针链表
 *       3.3.1 删除航班信息：
 *             1.修改记录文件中的相对应的数据（把要删除的信息节点后面的节点从记录文件中要删除的信息的位置开始
 *               覆盖写入，最后修改记录文件的大小，即减少一个航班数据所占的字节）
 *             2.删除航班信息链表中相应的节点
 *       3.3.2 修改航班信息：
 *             1.修改相对应的信息节点中的信息
 *             2.修改记录文件中相对应的数据
 *  3.4排序:由于航班信息链表的数据顺序和航班数据的文件中的数据严格一致(顺序和值),故采取使用航班信息节点的指针链表,来进行排序，并显示
 *  3.5删除所有的记录信息:把航班信息链表清空，把记录文件清空         
 *
 *存在的缺点：
 *1.在函数的参数很多应该加const而每加上
 *2.删除信息和修改信息的功能没有再封装，导致print_find_menu()函数又臭有长
 *3.函数名命名得不够明确
 *4.有些常用功能每有封装成函数
 * *****************************************************************************************/
#include "flight.h"
#include "find.h"
#include "fileio.h"
#include "print.h"
#include "commonheader.h"
#include "flight_link.h"

#define RECORD_PATH "./dat/data.txt"

int main (int argc, char *agrv[])
{
	int choice = -1;
	int flag = 1;   //用于控制循环
	NODE *pTmp = NULL;

	//打开记录信息文件,以追加的方式打开，没有则创建
   FILE * fd = fopen (RECORD_PATH, "a+");
	if (NULL == fd)
	{
       perror ("open ./record/data.txt error!\n");	
       exit (-1);
	}

	//把文件位置指针指向：文件开头处，以便读出数据形成链表
	fseek (fd, 0, SEEK_SET);

	//初始化一个链表
    NODE * head = init_list ();

	//把记录文件中的信息读取到链表中
    read_flight_info (fd, head);

	//根据用户选项执行相应的操作
	while (1==flag)
	{
 
		//清屏
		system("clear");

		//打印出欢迎界面接选项界面
		print_welcome_menu ();
		print_options_menu ();
		printf ("input your choice:");
		
		scanf ("%d", &choice);

        //清空标准输入
		while ('\n' != getchar ());

	    switch (choice)
		{
            case 1: //输入信息
				//进入输入界面
				print_input_menu (fd, head);
				break;

			case 2: //打印信息
				print_fli_info (head);
				break;

			case 3: //查找信息
				print_find_menu (fd, head);
				break;

			case 4: //排序打印信息
				print_sort_data (head);
				break;

			case 5: //删除
			    print_delete_menu (fd, head);	
				break;

			case 6:
			    print_auth_info ();	
				break;
			case 7: //退出	
                flag = 0;
				break;

		}	
	}
	

	//关闭文件
	fclose (fd);
	//free链表
	destroy_data_link (head);
	return 0;
}
