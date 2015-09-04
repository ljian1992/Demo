#include <stdio.h>

char* func()
{
    char p[] = "Delphi Tang";
    
    return p;
}

int main()
{
    char* s = func();
    
    printf("%s\n", s); // OOPS! 指针所指向的变量在指针使用之前已被销毁 
    
    return 0;
}
