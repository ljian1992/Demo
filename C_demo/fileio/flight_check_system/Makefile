CC=gcc
TARGET=main

SRCS=$(wildcard *.c */*.c */*/*.c)
OBJS=$(patsubst %.c, %.o, $(SRCS))
FLAGS=-I$(shell pwd)/include -g -DDEBUG

$(TARGET):$(OBJS)
	$(CC) $(FLAGS) -o $@ $^

#	echo $(SRCS)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm $(TARGET) *.o -r

