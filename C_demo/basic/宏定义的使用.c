#include <stdio.h>
#include <malloc.h>

#define MALLOC(type, x) (type*)malloc(sizeof(type)*x)
#define FOREVER() while(1)

#define BEGIN {
#define END   }
#define FOREACH(i, m) for(i=0; i<m; i++)

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int x = 0;
    int*p = MALLOC(int, 5);
    
    FOREACH(x, 5)
    BEGIN
        p[x] = array[x];
    END
    
    FOREACH(x, 5)
    BEGIN
        printf("%d\n", p[x]);
    END
    
    FOREVER();
    
    free(p);
    
    printf("Last printf...\n");
    
    return 0;
}