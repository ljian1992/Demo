#ifndef _SHM_H_
#define _SHM_H_

#define TEXTSIZE 1024

typedef struct share_mem
{ 
	int can_read;
	int can_write;
	char text[TEXTSIZE];
}SHARE;

#endif //_SHM_H_
	
