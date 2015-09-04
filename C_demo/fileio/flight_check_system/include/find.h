#ifndef _FIND_H_
#define _FIND_H_

#include <stdbool.h>
#include "flight.h"
#include "commonheader.h"

//查找航班信息
void find_data (NODE *head, POITER_NODE * poiter_head, const char *str, int mode);

//删除航班信息	
bool delete_data (FILE *fd, NODE *head, NODE *delnode);
	
//修改航班信息	
bool modify_data (FILE *fd, NODE *head, NODE *modnode);
#endif
