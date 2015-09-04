#include <stdio.h>
#include <malloc.h>

struct Demo
{
    int* p;
};

int main()
{
    struct Demo d1;
    struct Demo d2;
    
    int i = 0;
    
    for(i=0; i<10; i++)
    {
        d1.p[i] = 0; // OOPS! 操作了随机的内存块 
    }
    
    d2.p = (int*)calloc(5, sizeof(int));
    
    for(i=0; i<10; i++)
    {
        d2.p[i] = i; // OOPS!没有为结构体分配足够的内存 
    }
    
    free(d2.p);
    
    return 0;
}
