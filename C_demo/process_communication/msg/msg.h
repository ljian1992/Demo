#ifndef _MSG_H_
#define _MSG_H_

#define TEXT_SIZE 1024

typedef struct msg
{
	long type;
	char text[TEXT_SIZE];
}MSG;

#endif //_MSG_H_
