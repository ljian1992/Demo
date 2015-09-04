#ifndef _FILEIO_H_
#define _FILEIO_H_

#include "flight.h"
#include "commonheader.h"

void write_node (NODE * node, FILE * fd);

NODE * read_flight_info (FILE * fd, NODE * head);

void input_flight_data (FILE * fd, NODE *head);

#endif
