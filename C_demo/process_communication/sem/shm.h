#ifndef _SHM_H_
#define _SHM_H_

#define TEXTSIZE 1024

typedef struct share_mem
{ 
	char text[TEXTSIZE];
}SHARE;

#endif //_SHM_H_
	
