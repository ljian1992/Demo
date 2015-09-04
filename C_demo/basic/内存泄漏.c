#include <stdio.h>
#include <malloc.h>

void f(unsigned int size)
{
    int* p = (int*)malloc(size*sizeof(int));
    int i = 0;
    
    if( size % 2 != 0 )
    {
        return; // OOPS! 返回后，p并没有free掉。造成内存泄漏 
    }
    
    for(i=0; i<size; i++)
    {
        p[i] = i;
        printf("%d\n", p[i]);
    }
    
    free(p);
}

int main()
{
    f(9);
    f(10);
       
    return 0;
}

