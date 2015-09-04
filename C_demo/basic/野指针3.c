#include <stdio.h>
#include <malloc.h>
#include <string.h>

void func(char* p)
{
    printf("%s\n", p);
    free(p);  //归还了空间 
}

int main()
{
    char* s = (char*)malloc(5);
    
    strcpy(s, "Delphi Tang");
    
    func(s);
    
    printf("%s\n", s); // OOPS! 使用已经释放过后的指针。 
    
    return 0;
}
