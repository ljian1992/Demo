#ifndef _PRINT_H_
#define _PRINT_H_

//打印作者信息
void print_auth_info ();

//打印欢迎信息
void print_welcome_menu ();

//打印选项信息
void print_options_menu ();


//打印航班信息头
void print_fli_info_menu ();

//打印一个节点信息
void print_node_data (void(*function)(void), NODE * node);

//输入信息操作界面
void print_input_menu (FILE * fd, NODE * head);

//打印航班信息
void print_fli_info (NODE * head);

//查找信息
void print_find_menu (FILE * fd, NODE * head);

//打印出排序信息
void print_sort_data (NODE * head);


//打印出删除界面
void print_delete_menu (FILE *fd, NODE *head );


#endif
