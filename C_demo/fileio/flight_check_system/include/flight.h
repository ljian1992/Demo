#ifndef _FLIGTH_H_
#define _FLIGTH_H_

#include "kernel_list.h"

//航班信息数据节点
typedef struct flight_data
{
	char number[8];        //航班号
	char startAddr[12];     //起点站
	char arrAddr[12];       //终点站
	char type;              //机型
	char stime[25];         //起飞时间
	char atime[25];         //到达时间
	float price;            //价格 
}datatype;


//链表节点
typedef struct node
{
	datatype info;           //航班数据结构体
	int num;                 //第几个有效数据
	struct list_head list;   //内核链表
}NODE;


//用来保存链表节点指针的链表
typedef struct poiter_node_list
{
	NODE * poiter;
	struct list_head list;
}POITER_NODE;

//void dadatype_copy (datatype *dest, datatype *src);


#ifdef DEBUG
#define LOG(x) (printf ("%s[%d]: %s\n", __FILE__, __LINE__, x))

#else
#define LOG(x) 

#endif //DEBUG



/*

//清空标准输入缓存
void clear_stdin (void)
{
	while ('\n' != getchar());
}
*/

#endif //_FLIGTH_H_
