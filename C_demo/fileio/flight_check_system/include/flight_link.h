#ifndef _FLIGHT_LINK_H_
#define _FLIGHT_LINK_H_

#include "flight.h"

//新建一个节点
NODE * new_node (void);

//初始化数据链表
NODE * init_list (void);

//打印出一个节点的信息
void print_node (NODE * node);


//打印出数据链表中的值	
void show_kel_list (NODE * head);

//摧毁数据链表
void destroy_data_link (NODE * head);

//清空数据链表
void clear_data_link (NODE * head);

//新建一个新的数据指针结点	
POITER_NODE * new_poiter_node (NODE * node_poiter);

//初始化一个数据指针节点链表
POITER_NODE * init_poiter_list (void);

//打印出数据节点指针链表
void show_poiter_list (POITER_NODE * head);

//销毁一个数据节点指针链表
void destroy_poiter_link (POITER_NODE * head);

//交换两个数据节点中的指针值
void poiter_list_data_exch (POITER_NODE *dest, POITER_NODE *src);


//将链表信息按照相应的顺序打印出来，注：链表的结点不做任何改动
void list_sort (NODE * head, int mode);

#endif
