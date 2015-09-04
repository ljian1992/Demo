#include <stdio.h>
#include <malloc.h>

int main()
{
    char* s = (char*)malloc(10);
    
    printf(s); // OOPS! 内存分配成功，但未初始化。 
    
    free(s);
       
    return 0;
}

