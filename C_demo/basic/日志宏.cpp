#include <stdio.h>
#include <time.h>

#define LOG(s) (printf("%s %s\n[%s: %d]:%s\n", __DATE__, __TIME__, __FILE__, __LINE__, s)) 

int main(int argc, char *argv[])
{
  	LOG("enter main");
  	
  
    return 0;
}